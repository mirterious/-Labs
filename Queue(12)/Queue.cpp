#include "stdafx.h"
#include <iostream>

using namespace std;

struct Turn 
{
	int info;
	Turn *next, *prev;
} *start, *finish, *beginabove, *endabove, *beginbelow, *endbelow;

void Create(Turn** st, Turn** fin, int a)
{
	Turn *t = new Turn;
	t->info = a;
	t->next = t->prev = NULL;
	*st = *fin = t;
}

void AddBeg(Turn **st, int a)
{
	Turn *t = new Turn;
	t->info = a;
	t->prev = NULL;
	t->next = *st;
	(*st)->prev = t;
	*st = t;
}

void AddEnd(Turn **fin, int a)
{
	Turn *t = new Turn;
	t->info = a;
	t->prev = *fin;
	t->next = NULL;
	(*fin)->next = t;
	*fin = t;
}

void ViewBeg(Turn *t)
{
	Turn *ft = t;
	while (ft != NULL)
	{
		cout << ft->info << endl;
		ft = ft->next;
	}
}

void ViewEnd(Turn *t)
{
	Turn *ft = t;
	while (ft != NULL)
	{
		cout << ft->info << endl;
		ft = ft->prev;
	}
}

void Del_All(Turn **p) 
{
	Turn *t;
	while (*p != NULL) 
	{
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

void Delbeg(Turn **p)
{
	Turn *t = *p;
	*p = (*p)->next;
	(*p)->prev = NULL;
	delete t;
}

int main()
{	
	int option, elem;
	while (1)
	{
		cout << "\nCreate - 1\nAdd to begin - 2\nAdd to end - 3\nView from begin - 4\nView from end - 5\nTask - 6\nDeleting - 7\nEXIT - 0  :  ";
		cin >> option;
		switch (option)
		{
		case 1:
			if (start != NULL)
			{
				cout << "Clean memory" << endl;
				break;
			}
			cout << "Enter info" << endl;
			cin >> elem;
			Create(&start, &finish, elem);
			cout << "Created " << start->info << endl;
			break;
		case 2:
			cout << "Enter info" << endl;
			cin >> elem;
			AddBeg(&start, elem);
			break;
		case 3:
			cout << "Enter info" << endl;
			cin >> elem;
			AddEnd(&finish, elem);
			break;
		case 4:
			ViewBeg(start);
			break;
		case 5:
			ViewEnd(finish);
			break;
		case 6:
		{
			Turn *temp = start;
			Create(&beginabove, &endabove, 0);
			Create(&beginbelow, &endbelow, 0);
			while (temp != NULL)
			{
				if (temp->info >= 0)
				{
					AddEnd(&endabove, temp->info);
				}
				if (temp->info < 0)
				{
					AddEnd(&endbelow, temp->info);
				}
				temp = temp->next;
			}
			Delbeg(&beginabove);
			Delbeg(&beginbelow);
			cout << ">=0" << endl;
			ViewBeg(beginabove);
			cout << "<0" << endl;
			ViewBeg(beginbelow);
		}
			break;
		case 7: 
			Del_All(&start);
			Del_All(&beginbelow);
			Del_All(&beginabove);
			cout << "Memory was cleaned" << endl;
			break;
		case 0:
			return 0;
		}
	}
    return 0;
}
#include "stdafx.h"
#include <iostream>
using namespace std;

struct Stack
{
	int info;
	Stack *next;
} *first, *t, *below = NULL, *above = NULL;

Stack* Addel(Stack *st, int el)
{
	Stack *t = new Stack;
	t->info = el;
	t->next = st;
	return t;
}

Stack* OutStack(Stack* p, int *out) {
	Stack *t = p;			
	*out = p->info;
	p = p->next; 		
	delete t; 			
	return p; 			
}

void View(Stack *st)
{
	Stack *t = st;
	while (t != NULL)
	{ 
		cout << t->info << endl;
		t = t->next;
	}
}

void Del_All(Stack **st)
{
	while (*st != NULL) 
	{
		t = *st;
		*st = (*st)->next;
		delete t;
	}
}

void Sort_p(Stack **p)
{
	Stack *t = NULL, *t1, *r;
	if ((*p)->next->next == NULL) return;
	do
	{
		for (t1 = *p; t1->next->next != t; t1 = t1->next)
		{
			if (t1->next->info > t1->next->next->info)
			{
				r = t1->next->next;
				t1->next->next = r->next;
				r->next = t1->next;
				t1->next = r;
			}
		}
		t = t1->next;
	} while ((*p)->next->next != t);
}

void Sort_info(Stack *st) 
{
	Stack *t = NULL, *t1;
	int r;
	do
	{
		for (t1 = st; t1->next != t; t1 = t1->next)
			if (t1->info > t1->next->info) 
			{
				r = t1->info;
				t1->info = t1->next->info;
				t1->next->info = r;
			}
		t = t1;
	} while (st->next != t);
}

void Deletion(Stack *st)
{
	if (st->next == NULL)
	{
		Stack *t = st;
		while (t->next->next != NULL)
		{
			t = t->next;
		}
		t->next = NULL;
	}
}

int main()
{
	int i, j, option, n, el, b = 0;
	while (true)
	{
		cout << "\nCreate - 1.\nAdd - 2.\nView - 3.\nDel - 4.\nSort - 5.\nSprt - 6.\nTask - 7.\nDelete last el - 8.\nEXIT - 0. : ";
		cin >> option;
		switch (option)
		{
		case 1: case 2:
			if (option == 1 && first != NULL)
			{
				cout << "Clear Memory!" << endl;
				break;
			}
			cout << "Input kol = "; cin >> n;
			for (i = 1; i <= n; i++)
			{
				cin >> el;
				first = Addel(first, el);
			}
			if (option == 1) cout << "Create " << n << endl;
			else cout << "Add " << n << endl;
			break;
		case 3:
			if (!first)
			{
				cout << "No elements" << endl;
				break;
			}
			View(first);
			break;
		case 4:
			Del_All(&first);
			cout << "Memory Free!" << endl;
			break;
		case 5:
			if (!first)
			{
				cout << "No elements" << endl;
				break;
			}
			first = Addel(first, b);
			Sort_p(&first);
			first = OutStack(first, &b);
			View(first);
			break;
		case 6:
			if (!first)
			{
				cout << "No elements" << endl;
				break;
			}
			Sort_info(first);
			View(first);
			break;
		case 7:
		{
			if (!first)
			{
				cout << "No elements" << endl;
				break;
			}
			Stack *t = first;
			while (t != NULL)
			{
				if (t->info >= 0)
					above = Addel(above, t->info);
				else below = Addel(below, t->info);
				t = t->next;
			}
			cout << "<0" << endl;
			View(below);
			cout << ">0" << endl;
			View(above);
			break;
		}
		case 8:
			Deletion(first);
			View(first);
			break;
		case 0:
			if (first != NULL)
			{
				Del_All(&first);
			}
			if (below != NULL)
			{
				Del_All(&below);
			}
			if (above != NULL)
			{
				Del_All(&above);
			}
			return 0;
		default:
			cout << "Wrong input" << endl;
			break;
		}
	}
}
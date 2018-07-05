#include "stdafx.h"
#include <iostream>
#include <io.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;

struct Node
{
	int x;
	Node *left, *right;
};

/*int Count(Node *&Tree, int a)
{
	while (Tree != NULL)
		a++;
	Count(Tree->left, a);
	Count(Tree->right, a);
	return a;
}

int* Mass(Node *MyTree, int *a)
{
	int i=0;
	while (MyTree != NULL)
	{
		a[i] = MyTree->x;
		i++;
		Mass(MyTree->left, a);
		Mass(MyTree->right, a);
	}
	return a;
}*/

void View_Tree(Node *MyTree) 
{
	if(MyTree != NULL) 
	{
		cout << MyTree->x << ": " << endl;
		if (MyTree->left)
			cout << "Left: " << MyTree->left->x << endl;
		else
			cout << "Left: none" << endl;
		if (MyTree->right)
			cout << "Right: " << MyTree->right->x << endl;
		else
			cout << "Right: none" << endl;
		View_Tree(MyTree->right);		
		View_Tree(MyTree->left); 		
	}
}

Node* add_node(int x, Node *MyTree)
{
	if (NULL == MyTree)
	{
		MyTree = new Node;
		MyTree->x = x;
		MyTree->left = MyTree->right = NULL;
	}
	if (x<MyTree->x)
	{
		if (MyTree->left != NULL) add_node(x, MyTree->left);
		else
		{
			MyTree->left = new Node;
			MyTree->left->left = MyTree->left->right = NULL;
			MyTree->left->x = x;
		}
	}
	if (x>MyTree->x)
	{
		if (MyTree->right != NULL) add_node(x, MyTree->right);
		else
		{
			MyTree->right = new Node;
			MyTree->right->left = MyTree->right->right = NULL;
			MyTree->right->x = x;
		}
	}
	return MyTree;
}

Node* Build(int *arr, int size)
{
	Node *MyTree = NULL;
	for (int i = 0; i < size; i++)
	{
		MyTree = add_node(arr[i], MyTree);
	}
	return MyTree;
}

bool search(int x, Node *MyTree)
{
	bool check = true;
	if (x>MyTree->x)
	{
		if (MyTree->right == NULL) check = false;
		else search(x, MyTree->right);
	}
	else if (x<MyTree->x)
	{
		if (MyTree->left == NULL) check = false;
		else search(x, MyTree->left);
	}
	else return check;
}

Node* DeleteNode(int x, Node *MyTree)
{
	Node *deleted = MyTree, *deletedPrev = NULL, *change, *changePrev;
	while (deleted != NULL && deleted->x != x)
	{
		deletedPrev = deleted;
		if (deleted->x > x) deleted = deleted->left;
		else deleted = deleted->right;
	}
	if (deleted == NULL)
	{
		cout << "Element hasn't found" << endl;
		return MyTree;
	}
	if (deleted->right == NULL) change = deleted->left;
	else
		if (deleted->left == NULL) change = deleted->right;
		else {
			changePrev = deleted;
			change = deleted->left;
			while (change->right != NULL)
			{
				changePrev = change;
				change = change->right;
			}
			if (changePrev == deleted) change->right = deleted->right;
			else
			{
				change->right = deleted->right;
				changePrev->right = change->left;
				change->left = changePrev;
			}
		}
		if (deleted == MyTree) MyTree = change;
		else
			if (deleted->x < deletedPrev->x)
				deletedPrev->left = change;
			else
				deletedPrev->right = change;
		delete deleted;
		return MyTree;
}

void Del_Tree(Node *MyTree)
{
	if (MyTree != NULL) {
		Del_Tree(MyTree->left); 			
		Del_Tree(MyTree->right); 			
		delete MyTree;
	}
}

Node* Min_Key(Node *MyTree) 
{			
	while (MyTree->left != NULL) MyTree = MyTree->left;
	return MyTree;
}

Node* Max_Key(Node *MyTree)
{
	while (MyTree->right != NULL) MyTree = MyTree->right;
	return MyTree;
}

void Balans(Node **p, int n, int k, int *a) 
{
	if (n == k) {
		*p = NULL;
		return;
	}
	else {
		int m = (n + k) / 2;
		*p = new Node;
		(*p)->x = a[m];
		Balans(&(*p)->left, n, m, a);
		Balans(&(*p)->right, m + 1, k, a);
	}
}

void ForwardLook(Node *Tree, FILE *A)
{
	if (Tree != NULL)
	{
		fprintf(A, "%d", Tree->x);
		ForwardLook(Tree->left, A);
		ForwardLook(Tree->right, A);
	}
}

void SymetricLook(Node *Tree, FILE *A)
{
	if (Tree != NULL)
	{
		SymetricLook(Tree->left, A);
		fprintf(A, "%d", Tree->x);
		SymetricLook(Tree->right, A);
	}
}

void BackLook(Node *Tree, FILE *A)
{
	if (Tree != NULL)
	{
		BackLook(Tree->left, A);
		BackLook(Tree->right, A);
		fprintf(A, "%d", Tree->x);
	}
}

void PrintFile(Node *MyTree, FILE *A)
{
	ForwardLook(MyTree, A);
	fprintf(A, "\n\r");
	BackLook(MyTree, A);
	fprintf(A, "\n\r");
	SymetricLook(MyTree, A);
}

Node* Task(Node *MyTree)
{
	Node *Max, *Min;
	Max = Max_Key(MyTree);
	Min = Min_Key(MyTree);
	/*Node *temp = Min;
	Min = Max;
	Max = temp;*/
	int temp = Min->x;
	Min->x = Max->x;
	Max->x = temp;
	return MyTree;
}

FILE *FileText;
char File_Rez[] = "result.txt";

int main()
{
	Node *Tree = NULL;
	int option, elem;
	while (1)
	{
		cout << "\nAdd - 1\nBalance- 2\nSearch - 3\nDelete - 4\nPrint information - 5\nTask - 6\nDelete Tree - 7\nView Tree - 8\nEXIT - 0  :  ";
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "Input number : ";
			cin >> elem;
			Tree = add_node(elem, Tree);
			break;
		case 2:
		{
			Node *NewTree = NULL;
			int *arr;
			cout << "Input array size" << endl;
			int s1ze;
			cin >> s1ze;
			int temp=0;
			arr = new int[s1ze];
			for (int i = 0; i < s1ze; i++)
			{
				arr[i] = rand();
			}
			for (int i = 0; i < s1ze; i++)
			{
				if (arr[i] > arr[i + 1])
				{
					arr[i + 1] = temp;
					arr[i + 1] = arr[i];
					arr[i] = temp;
				}
			}
			for (int i = 0; i < s1ze; i++)
				cout << arr[i] << " ";
			NewTree = Build(arr, s1ze);
			Balans(&NewTree, 0, s1ze, arr);
			View_Tree(NewTree);
			break;
		}
		case 3:
			cout << "Input number : ";
			cin >> elem;
			if (search(elem, Tree) == true) cout << "EST'" << endl;
			else cout << "NET" << endl;
			break;
		case 4:
			cout << "Input number : ";
			cin >> elem;
			Tree = DeleteNode(elem, Tree);
			break;
		case 5:
			FileText = fopen(File_Rez, "w");
			View_Tree(Tree);
			PrintFile(Tree, FileText);
			fclose(FileText);
			system("type result.txt");
			break;
		case 6:
			Tree = Task(Tree);
			View_Tree(Tree);
			break;
		case 7:
			Del_Tree(Tree);
			break;
		case 8:
			View_Tree(Tree);
			break;
		case 0:
			return 0;
		default:
			cout << "Wrong input" << endl;
			break;
		}
	}
    return 0;
}
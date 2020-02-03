#include "Header.h"

Node* getFreeNode(T value, Node* parent)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}
void insert(Node** head, int value)
{
	Node* tmp = NULL;
	if (*head == NULL)
	{
		*head = getFreeNode(value, NULL);
		return;
	}

	tmp = *head;
	while (tmp)
	{
		if (value > tmp->data)
		{
			if (tmp->right)
			{
				tmp = tmp->right;
				continue;
			}
			else
			{
				tmp->right = getFreeNode(value, tmp);
				return;
			}
		}
		else if (value < tmp->data)
		{
			if (tmp->left)
			{
				tmp = tmp->left;
				continue;
			}
			else
			{
				tmp->left = getFreeNode(value, tmp);
				return;
			}
		}
		else
		{
			exit(2);	//	дерево построено не правильно
		}
	}
}
//	Построить идеально сбалансированное дерево с n узлами
Node* Tree(int n)
{
	Node* newNode;
	int x, nl, nr;
	if (n == 0)
	{
		newNode = NULL;
	}
	else
	{
		fscanf(file, "%d", &x);
		nl = n / 2;
		nr = n - nl - 1;
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = x;
		newNode->left = Tree(nl);
		newNode->right = Tree(nr);
	}
	return newNode;
}


// Распечатка двоичного дерева в виде скобочной записи
void printTree(Node* root) {
	if (root)
	{
		printf("%d", root->data);
		if (root->left || root->right)
		{
			printf("(");
			if (root->left)
				printTree(root->left);
			else
				printf("NULL");
			printf(",");
			if (root->right)
				printTree(root->right);
			else
				printf("NULL");
			printf(")");
		}
	}
}
/*
	Рекурсивный обход двоичного дерева

	1. КЛП — «корень–левый–правый»(обход в прямом порядке, pre-order):
		a. Посетить корень.
		b. Обойти левое поддерево.
		c. Обойти правое поддерево.
*/
void preOrderTravers(Node* root) {
	if (root) {
		printf("%d ", root->data);
		preOrderTravers(root->left);
		preOrderTravers(root->right);
	}
}
/*
	2. ЛКП — «левый–корень–правый»(симметричный обход, in-order):
		a. Обойти левое поддерево.
		b. Посетить корень.
		c. Обойти правое поддерево.
*/
void inOrderTraves(Node* root)
{
	if (root)
	{
		inOrderTraves(root->left);
		printf("%d ", root->data);
		inOrderTraves(root->right);
	}
}
/*
	3. ЛПК — «левый–правый–корень»(обход в обратном порядке, post-order):
		a. Обойти левое поддерево.
		b. Обойти правое поддерево.
		c. Посетить корень.

*/
void postOrderTraves(Node* root)
{
	if (root)
	{
		postOrderTraves(root->left);
		postOrderTraves(root->right);
		printf("%d ", root->data);
	}
}
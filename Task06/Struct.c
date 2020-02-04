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
			exit(2);	//	������ ��������� �� ���������
		}
	}
}
//	��������� �������� ���������������� ������ � n ������
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
// ���������� ��������� ������ � ���� ��������� ������
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
	����������� ����� ��������� ������

	1. ��� � �������������������(����� � ������ �������, pre-order):
		a. �������� ������.
		b. ������ ����� ���������.
		c. ������ ������ ���������.
*/
void preOrderTravers(Node* root) {
	if (root) {
		printf("%d ", root->data);
		preOrderTravers(root->left);
		preOrderTravers(root->right);
	}
}
/*
	2. ��� � �������������������(������������ �����, in-order):
		a. ������ ����� ���������.
		b. �������� ������.
		c. ������ ������ ���������.
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
	3. ��� � �������������������(����� � �������� �������, post-order):
		a. ������ ����� ���������.
		b. ������ ������ ���������.
		c. �������� ������.

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

/*	��� - �������	*/
hashTableIndex hash(T data)
{
	/***********************************
	*���-������� ����������� � ������ *
	***********************************/
	return (data % hashTableSize);
}
Node_* insertNode(T data)
{
	Node_* p, * p0;
	hashTableIndex bucket;
	/*************************************************
	*����������� ���� ��� ������ � ������� � �������*
	*************************************************/
	/* ������� ���� � ������ ������� */
	bucket = hash(data); // ������������ ����� �����
	p = (Node_*)malloc(sizeof(Node_));
	if (p == 0) {
		// � ����������� ����� ������ ������� ��������� � �������� ������
		fprintf(stderr, "out of memory (insertNode)\n");
		exit(1);
	}
	// ���������� ������� �������� ��������� ���������� �����
	p0 = hashTable[bucket];
	// � ��������� ���� ���������� ����� �������
	hashTable[bucket] = p;
	// ��������� ����� ������� �� ������
	p->next = p0;
	// ���������� ������ � ����� �������
	p->data = data;
	return p;
}
/*�������� ����*/
void deleteNode(T data) {
	Node_* p0, * p;
	hashTableIndex bucket;
	/********************************************
	* ������� ���� ���������� ������ �� ������� *
	********************************************/
	/* ������� ����*/
	p0 = 0;
	bucket = hash(data);
	p = hashTable[bucket];
	while (p && !compEQ(p->data, data)) {
		p0 = p;
		p = p->next;
	}
	if (!p)
		return;
	/* p ��������� ���� ��� ��������, ������� ��� �� ������ */
	if (p0)
		// �� ������, p0 ��������� �� ����������
		p0->next = p->next;
	else
		// ������ � �������
		hashTable[bucket] = p->next;
	free(p);
}
Node_* findNode(T data) {
	Node_* p;
	/**************************************
	*���������� ����, ����������� ������ *
	**************************************/
	p = hashTable[hash(data)];
	while (p && !compEQ(p->data, data))
		p = p->next;
	return p;
}
void printTable(int size) {
	Node_* p;
	for (int i = 0; i < size; i++)
	{
		p = hashTable[i];
		while (p)
		{
			printf("%5d", p->data);
			p = p->next;
		}
		printf("\n");
	}
}
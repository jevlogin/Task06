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

/*	ХЕШ - ФУНКЦИЯ	*/
hashTableIndex hash(T data)
{
	/***********************************
	*хэш-функция применяемая к данным *
	***********************************/
	return (data % hashTableSize);
}
Node_* insertNode(T data)
{
	Node_* p, * p0;
	hashTableIndex bucket;
	/*************************************************
	*распределим узел для данных и вставим в таблицу*
	*************************************************/
	/* Вставка узла в начало таблицы */
	bucket = hash(data); // рассчитываем номер блока
	p = (Node_*)malloc(sizeof(Node_));
	if (p == 0) {
		// В стандартный поток ошибок выводим сообщение о нехватке памяти
		fprintf(stderr, "out of memory (insertNode)\n");
		exit(1);
	}
	// Запоминаем текущее значение указателя найденного блока
	p0 = hashTable[bucket];
	// В найденный блок записываем новый элемент
	hashTable[bucket] = p;
	// Связываем новый элемент со старым
	p->next = p0;
	// Записываем данные в новый элемент
	p->data = data;
	return p;
}
/*Удаление узла*/
void deleteNode(T data) {
	Node_* p0, * p;
	hashTableIndex bucket;
	/********************************************
	* удаляем узел содержащие данные из таблицы *
	********************************************/
	/* находим узел*/
	p0 = 0;
	bucket = hash(data);
	p = hashTable[bucket];
	while (p && !compEQ(p->data, data)) {
		p0 = p;
		p = p->next;
	}
	if (!p)
		return;
	/* p найденный узел для удаления, удаляем его из списка */
	if (p0)
		// не первый, p0 указывает на предыдущий
		p0->next = p->next;
	else
		// первый в цепочке
		hashTable[bucket] = p->next;
	free(p);
}
Node_* findNode(T data) {
	Node_* p;
	/**************************************
	*нахождение узла, содержащего данные *
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
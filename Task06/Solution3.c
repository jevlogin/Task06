#include "Header.h"

Node** hashTable;
int hashTableSize;

void Solution3(int argc, char argv[])
{
	int i, * a, maxnum, random;
	if (argc<2)
	{
		printf("incorrect command line\ncommand line maxnum hashTableSize [random]\nSample:\n");
		printf("hashTable 2000 100\n");
		printf("Create 2000 records, hastTable=100, fill sequense numbers\n");
		printf("or 4000 200 r\n");
		printf("Create 4000 records, hastTable=200, fill random numbers\n");
		exit(0); // ¬ыход без ошибки
	}
	maxnum = atoi(argv[1]);
	hashTableSize = atoi(argv[2]);
	random = argc > 3;
	if ((a = (int*)malloc(sizeof(*a))) == 0)
	{
		fprintf(stderr, "out of memory (a)\n");
		exit(1);
	}
	if ((hashTable = (Node_*)calloc(hashTableSize, sizeof(Node_*))) == 0)
	{
		fprintf(stderr, "out of memory (hashTable)\n");
		exit(1);
	}
	if (random)
	{
		// заполн€ем "a" случайными числами
		for (i = 0; i < maxnum; i++)
		{
			a[i] = rand() % 100;
		}
		printf("ran ht, %d items, %d hashTable\n", maxnum, hashTableSize);

	}
	else
	{
		// заполн€ем последовательными данными
		for (i = 0; i < maxnum; i++)
		{
			a[i] = i;
		}
		printf("seq ht, %d items, %d hashTable\n", maxnum, hashTableSize);
	}
	for (i = 0; i < maxnum; i++)
	{
		insertNode(a[i]);
	}
	printTable(hashTableSize);
	for (i = 0; i < maxnum; i++)
	{
		findNode(a[i]);
	}
	for (i = maxnum - 1; i >= 0; i--)
	{
		findNode(a[i]);
	}
	for (i = maxnum -1; i >= 0; i--)
	{
		deleteNode(a[i]);
	}
}

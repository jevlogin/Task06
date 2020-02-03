#include "Header.h"

void Solution2()
{
	Node* Tree = NULL;
	file = fopen("D:\\temp\\data.txt", "r");
	//	проверка на доступ к файлу data.txt
	if (file == NULL)
	{
		puts("Не могу открыть файл");
		return 1;
	}
	int count;
	fscanf(file, "%d", &count);	//	Считываем кол-во записей
	int i;
	for (size_t i = 0; i < count; i++)
	{
		int value;
		fscanf(file, "%d", &value);
		insert(&Tree, value);
	}
	fclose(file);
	printTree(Tree);
	printf("\nPreOrderTraves: ");
	preOrderTravers(Tree);
}
#include "Header.h"

void Solution1()
{
	printf("Здесь будем выполнять задания");

	Node* tree = NULL;
	file = fopen("D:\\temp\\data.txt", "r");
	//	проверка на доступ к файлу data.txt
	if (file == NULL)
	{
		puts("Не могу открыть файл");
		return 1;
	}
	
	int count;
	fscanf(file, "%d", &count);	//	Считываем кол-во записей
	tree = Tree(count);

	fclose(file);

	printTree(tree);
}
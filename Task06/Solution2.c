#include "Header.h"

void Solution2()
{
	Node* Tree = NULL;
	file = fopen("D:\\temp\\data.txt", "r");
	//	�������� �� ������ � ����� data.txt
	if (file == NULL)
	{
		puts("�� ���� ������� ����");
		return 1;
	}
	int count;
	fscanf(file, "%d", &count);	//	��������� ���-�� �������
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
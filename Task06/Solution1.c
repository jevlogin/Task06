#include "Header.h"

void Solution1()
{
	printf("����� ����� ��������� �������");

	Node* tree = NULL;
	file = fopen("D:\\temp\\data.txt", "r");
	//	�������� �� ������ � ����� data.txt
	if (file == NULL)
	{
		puts("�� ���� ������� ����");
		return 1;
	}
	
	int count;
	fscanf(file, "%d", &count);	//	��������� ���-�� �������
	tree = Tree(count);

	fclose(file);

	printTree(tree);
}
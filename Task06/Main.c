#include "Header.h"


int HashFunction(int k)
{
	int N = 13;
	double A = 0.618033;
	int hash = N * fmod(k * A, 1);
	return (hash);
}

int main(int argc, char* argv[])
{
	//	Поключение кириллицы
	setlocale(LC_ALL, "ru");
	//	Первое задание
	//Solution1();
	//Solution2();
	//Solution3(argc, argv);

	int key = 97;

	key = HashFunction(key);

	printf("key = %d", key);
	
	return (0);
}

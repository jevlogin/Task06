#include "Header.h"
#include <string.h>


int HashFunction(const char* key)
{
	int hash = 1234;
	double A = 0.618033;
	//int hash = N * fmod(key * A, 1);
	char t;

	while (*key )
	{
		t = *key;
		hash += hash * fmod(t * A, 1);
		++key;
	}
	
	return hash;
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
	char* s = "Doom";

	//key = HashFunction(key);
	int k2 = HashFunction(s);
	printf("key = %d\n", k2);

	s = "Dom";
	 k2 = HashFunction(s);
	printf("key = %d\n", k2);

	s = "Doo";
	 k2 = HashFunction(s);
	printf("key = %d\n", k2);

	return (0);
}

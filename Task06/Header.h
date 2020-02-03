#pragma once
#ifndef _HEADER_
#define _HEADER_
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//#define T int
//	это тоже самое (почти, надо ставить точку с запятой в конце обязательно!)
typedef int T;
FILE* file;

typedef struct Node
{
	T data;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
} Node;

#endif // !_HEADER_


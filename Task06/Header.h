#pragma once
#ifndef _HEADER_
#define _HEADER_
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

//#define T int
//	это тоже самое (почти, надо ставить точку с запятой в конце обязательно!)
typedef int T;
typedef int hashTableIndex;
#define compEQ(a, b)(a == b)	//	Определили директиву сравнения двух значений. Не знаю пока что это..

FILE* file;

typedef struct Node
{
	T data;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
} Node;

struct Node_
{
	T data;
	struct Node_* next;
};
typedef struct Node_ Node_;

extern Node** hashTable;
extern int hashTableSize;


#endif // !_HEADER_


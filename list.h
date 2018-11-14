#ifndef __TEST__
#define __TEST__

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning(disable:4996)

#define MANNUM 100
#define USE_NUM 5


extern int use_num;

typedef struct man
{
	char Name[15];
	char Gender[5];
	int Age;
	char Phone[6];
	char Home[30];
}man;



//man List[MANNUM];
//void ListOpera(struct man* List[100]);
void Print(man* List);
void Add(man* List,FILE* fp);
void Delete(man* List,FILE* fp);
void Search(man*List,FILE* fp);
void Change(man*List,FILE* fp);
void Clear(man*List,FILE* fp);
void Sort(man*List,FILE* fp);
void write(man*List, FILE* fp);


#endif
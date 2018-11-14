#include "list.h"

int use_num =USE_NUM;

/*写入文件*/
void write(man* List,FILE* fp)
{
	for (int i = 0; i < use_num; i++)
	{
		fprintf(fp, "Name:%s\nGendfder:%s\nAge:%d\nPhone:%s\nHome:%s\n\n"\
			, List[i].Name, List[i].Gender, List[i].Age, List[i].Phone, List[i].Home);
	}
}
/*添加联系人信息*/
void Add(man* List,FILE* fp)
{
	for (int i = 0; i < use_num; i++){
		printf("Name:");
		scanf("%s", List[i].Name);//输入信息
		printf("Gender:");
		scanf("%s", List[i].Gender);
		printf("Age:");
		scanf("%d", &List[i].Age);
		printf("Phone:");
		scanf("%s", List[i].Phone);
		printf("Home:");
		scanf("%s", List[i].Home);
		printf("\n");
	}
	write(List, fp);		//写入文件
}
/*删除联系人*/
void Delete(man* List, FILE* fp)
{
	char name[15];
	printf("输入要删除的人：");
	scanf("%s", &name);
	for (int i = 0; i < use_num; i++)
	{
		if (strcmp(name, (List + i)->Name) == 0){
			for (int j = i; j <= use_num - i; j++){
				memmove(List + j, List + j + 1, sizeof(List));
			}
			use_num--;
			break;
		}
		else if (i == use_num - 1){
			printf("查无此人\n");
		}
	}
	write(List, fp);		//写入文件
}
/*修改指定联系人*/
void Change(man*List, FILE* fp)
{
	char name[15];
	printf("输入要更改的人：\n");
	scanf("%s", &name);
	for (int i = 0; i < use_num; i++)
	{
		if (strcmp(name, List[i].Name) == 0)
		{
			printf("Name:");
			scanf("%s", List[i].Name);
			printf("Gender:");
			scanf("%s", List[i].Gender);
			printf("Age:");
			scanf("%d", &List[i].Age);
			printf("Phone:");
			scanf("%s", List[i].Phone);
			printf("Home:");
			scanf("%s", List[i].Home);
			printf("\n");
			break;
		}
		if (i == use_num - 1){
			printf("查无此人！\n");
		}
	}
	write(List, fp);		//写入文件
}
/*查找指定联系人*/
void Search(man* List, FILE* fp)
{
	char name[15];
	printf("输入要查找的联系人\n");
	scanf("%s", &name);
	for (int i = 0; i < use_num; i++)
	{
		if (strcmp(name, List[i].Name) == 0){
			printf("Name:%s\nGendfder:%s\nAge:%d\nPhone:%s\nHome:%s\n\n"\
				, List[i].Name, List[i].Gender, List[i].Age, List[i].Phone, List[i].Home);
			break;
		}
		if (i == use_num - 1){
			printf("查无此人！\n");
		}
	}

}
/*打印联系人信息*/
void Print(man* List)
{
	system("cls");
	printf("用户信息：\n");
	for (int i = 0; i < use_num; i++){
		printf("Name:%s\nGendfder:%s\nAge:%d\nPhone:%s\nHome:%s\n\n"\
			, List[i].Name, List[i].Gender, List[i].Age, List[i].Phone, List[i].Home);
	}
}
/*清空联系人*/
void Clear(man* List, FILE* fp)
{
	for (int i=0; i < use_num ; i++){
		memmove(List + i, List + use_num, sizeof(man));
	}
	for (int j = 0; j < use_num*sizeof(man);j++)
	{
		fputc(0, fp);
	}
	use_num = 0;
}
/*名字排序*/
void Sort(man*List, FILE* fp)
{
	man a;
	man*test=&a;
	for (int i = 0; i < use_num-1; i++)
	{
		for (int j = 0; j < use_num - i-1; j++)
		{
			if (strcmp(List[j].Name, List[j + 1].Name)>0)
			{
				memcpy(test, List+j+1, sizeof(man));
				memcpy(List+j+1, List+j, sizeof(man));
				memcpy(List+j, test, sizeof(man));
			}
		}
	}
	write(List, fp);		//写入文件
}



//void ListOpera(struct man*List)
//{
//	
//}
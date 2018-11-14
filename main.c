#include "list.h"


int main()
{
	man*List = NULL;
	List = (man*)calloc(MANNUM, sizeof(man));
	if (NULL != List){
		FILE* fp = fopen("List.txt", "r+");
		if (fp == NULL){
			printf("error£¡d\n");
			return 0;
		}

		//Add(List, fp);
		//Sort(List,fp);
		//Change(List,fp);
		//Clear(List,fp);
		//Search(List,fp);
		//Print(List,fp);
		//Delete(List,fp);
		fclose(fp);
	}
	else{
		printf("defeat\n");
	}


	free(List);
	system("pause");
	return 0;
}

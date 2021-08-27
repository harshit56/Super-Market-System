#include<stdio.h>
#include<conio.h>
#include<string.h>

typedef struct Emp                                                                                                                  //Structure Employee
{
	int emplId,flag;
	char emplName[30],pass[30],contact[11];
}Employee;

int main()
{
	Employee e;
	system("cls");
	FILE *fin; //File Pointer
	fin=fopen("Empl.dat","rb");
	while(fread(&e,sizeof(e),1,fin))
	{
		//fread(&e,sizeof(e),1,fin);
		printf("Employee Id: %d\tEmplyee Name: %s\tEmployee Contact: %s\t",e.emplId,e.emplName,e.contact);
		if(e.flag==0)
		{	
			printf("Employee Status: Active");
		}
		printf("\n");
	
	}
	fclose(fin);
	return 0;
}


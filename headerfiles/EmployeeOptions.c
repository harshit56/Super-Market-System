//#include<C:\Users\Flash\Desktop\c\headerfiles\EmployeeOptions.c>

typedef struct Emp                                                                                                                  //Structure Employee
{
	int emplId,flag;
	char emplName[30],pass[30],contact[11];
}Employee;

void newEmployee()                                                                                                                              //New Employee
{
	Employee e;
	system("cls");
	Name();
	char rpass[30];
	int check=1;
	printf("\n\nMain Menu->Admin Menu->Employee->New Employee\n\n");
	FILE *fout; //File Pointer
	printf("Enter New Employee Details below: \n");
	printf("Enter Employee Id:");
	scanf("%d",&e.emplId);
	printf("Enter Employee name:");
	fflush(stdin);
	gets(e.emplName);
	printf("Enter Employee contact number:");
	fflush(stdin);
	gets(e.contact);
	while(check)
	{
		printf("Enter employee password:");
		scanf("%s",e.pass);
		printf("Re-enter employee password:");
		scanf("%s",rpass);
		if(strcmp(e.pass,rpass)==0)
		{
			check=0;
			printf("\nPassword created successfully\nPress any key to continue...");
			getch();
		}
		else
		{
			printf("\n\nPassword not match\nPress any key to reenter...");
			getch();
		}
	}
	fout=fopen("Empl.dat","ab"); //Opening of File(Empl.dat)
	if(fout!=NULL)
	{
		e.flag=0;
		fwrite(&e,sizeof(e),1,fout);
		printf("\n\nData Stored Successfully\n\n");
	}
	else
	{
		printf("Unable to open file");
	}
	fclose(fout);
	printf("Press any key to continue....");
	getch();
	employeeOptions();
}

void searchEmployee()                                                                                                                         //Search Employee
{
	system("cls");
	Name();
	Employee e;
	int found;
	char ch;
	printf("\n\nMain Menu->Admin Menu->Employee->Search Employee \n\n");
	int Se;
	FILE *fin; //File Pointer
	do
	{
		system("cls");
		fin=fopen("Empl.dat","rb");
		if(fin!=NULL)
		{
			printf("Enter Employee ID to Search:");
			scanf("%d",&Se);
			while(fread(&e,sizeof(e),1,fin))
			{
				if(Se==e.emplId)
				{
					printf("\nSearched Successfully\n\n");
				
					printf("Employee Details are:\n\n");
					printf("Employee ID:%d\nEmployee Name:%s\nEmployee contact number:%s\nEmployee Password:%s\n",e.emplId,e.emplName,e.contact,e.pass);
					if(e.flag==0)
					{
						printf("Employee Status: Active");
					}
					else
					{
						printf("Employee Status: Blocked");
					}
					found=1;
					fclose(fin);
					printf("\n\nDo you want to add new product again(Y/N): ");
					fflush(stdin);
					scanf("%c",&ch);
					break;
				}
				else
				{
					found=0;
				}
			}
			if(found==0)
			{
				printf("Record not found...Please try again");
				fclose(fin);
				employeeOptions();
			}
		}
		else
		{
			printf("Unable..to open file");
			employeeOptions();
		}
	}while(ch=='Y'||ch=='y');
	printf("Press any key to continue.....");
	getch();
	employeeOptions();
}

void blockEmployee()                                                                                                                          //Employee Block
{
	Employee e;
	system("cls");
	Name();
	int Se,status=0;
	printf("\n\nMain Menu->Admin Menu->Employee->Block Employee\n\n");
	FILE *fin,*fout; //File Pointer
	fin=fopen("Empl.dat","rb");
	fout=fopen("Emplblock.dat","wb");
	if(fin!=NULL||fout!=NULL)
	{
		printf("Enter Employee ID to block:");
		scanf("%d",&Se);
		while(fread(&e,sizeof(e),1,fin))
		{
			if(Se==e.emplId)
			{                                                                                                             
				e.flag=1;
				status=1;
			}
		
			fwrite(&e,sizeof(e),1,fout);
		}
		fclose(fin);
		fclose(fout);
		if(status==1)
		{
			printf("\nEmployee blocked successfully....");
			remove("Empl.dat");
			rename("Emplblock.dat","Empl.dat");
		}
		else
		{
			printf("Record not found...");
			remove("Emplblock.dat");
		}
	}
	else
	{
		printf("Unable to open file...");
	}
	printf("\n\nPress any key to continue....");
	getch();
	employeeOptions();
}

void unblockEmployee()                                                                                                                      //Employee Unblock
{
	Employee e;
	system("cls");
	Name();
	int Se,status=0;
	printf("\n\nMain Menu->Admin Menu->Employee->Block Employee\n\n");
	FILE *fin,*fout; //File Pointer
	fin=fopen("Empl.dat","rb");
	fout=fopen("Emplunblock.dat","wb");
	if(fin!=NULL||fout!=NULL)
	{
		printf("Enter Employee ID to unblock:");
		scanf("%d",&Se);
		while(fread(&e,sizeof(e),1,fin))
		{
			if(Se==e.emplId)
			{                                                                                                             
				e.flag=0;
				status=1;
			}
			fwrite(&e,sizeof(e),1,fout);
		}
		fclose(fin);
		fclose(fout);
		if(status==1)
		{
			printf("\nEmployee unblocked successfully....");
			remove("Empl.dat");
			rename("Emplunblock.dat","Empl.dat");
		}
		else
		{
			printf("Record not found...");
			remove("Emplunblock.dat");
		}
	}
	else
	{
		printf("Unable to open file...");
	}
	printf("\n\nPress any key to continue....");
	getch();
	employeeOptions();
}

void deleteEmployee()                                                                                                                       //Delete Employee
{
	Employee e;
	system("cls");
	Name();
	int Se,status=0;
	printf("\n\nMain Menu->Admin Menu->Employee->Delete Employee\n\n");
	FILE *fin,*fout;
	fin=fopen("Empl.dat","rb");
	fout=fopen("EmployeeDel.dat","wb"); //Opening of a file(EmployeeDelete.dat)
	if(fin!=NULL||fout!=NULL)
	{
		printf("Enter Employee ID to delete:");
		scanf("%d",&Se);
		while(fread(&e,sizeof(e),1,fin))
		{
			if(Se!=e.emplId)
			{
				fwrite(&e,sizeof(e),1,fout);
			}
			else
			{
				status=1;
			}

		}
		fclose(fin);
		fclose(fout);
		if(status==1)
		{
			printf("Record deleted successfully...");
			remove("Empl.dat");
			rename("EmployeeDel.dat","Empl.dat");
		}
		else
		{
			printf("Record not found...");
			remove("EmployeeDel.dat");
		}
	}
	else
	{
		printf("Unable to open file");
	}
	printf("Press any key to continue....");
	getch();
	employeeOptions();
}

void modifyEmployee()                                                                                                        //Modify Product
{
	Employee e;
	system("cls");
	Name();
	int Se,b,c=0;
	printf("\n\nMain Menu->Admin Menu->Employee->Modify Employee\n\n");
	FILE *fin,*fout;
	fin=fopen("Empl.dat","rb");
	fout=fopen("Mod.dat","wb");
	if(fin!=NULL||fout!=NULL)
	{
		printf("Enter Employee ID to modify:");
		scanf("%d",&Se);
		while(fread(&e,sizeof(e),1,fin))
		{
			if(Se==e.emplId)
			{
				c=1;
				printf("1.Modify Name\n2.Modify Contact\n3.Modify Password\n\nEnter your choice:");
				scanf("%d",&b);
				switch(b)
				{
					case 1:
					
							printf("Enter new Employee name:");
							fflush(stdin);
							gets(e.emplName);
							break;
						
						
					case 2:
						
						
							printf("Enter Employee new conatct:");
							fflush(stdin);
							gets(e.contact);
							break;
						
					case 3:
						
							printf("Enter Employee new password:");
							scanf("%s",e.pass);
							break;
						
				}
			
			}
			fwrite(&e,sizeof(e),1,fout);
		}
	}
	else
	{
		printf("Unable to open file");
	}
	fclose(fin);
	fclose(fout);
	if(c==1)
	{
		printf("\nData Modified Successfully\n\n");
		remove("Empl.dat");
		rename("Mod.dat","Empl.dat");
		
	}
	else
	{
		printf("\nRecord not found...");
		remove("Mod.dat");
		
		
	}
	printf("Press any key to continue...");
	getch();
	employeeOptions();
}



int userMenu(void)                                                                                                                      //User Menu
{
	Employee e;
	system("cls");
	Name();
	int SI;
	char pass[30];
	printf("\nMain Menu->User Menu\n\n");
	printf("Enter Employee ID to login:");
	scanf("%d",&SI);
	printf("Enter Password:");
	fflush(stdin);
	scanf("%s",pass);
	FILE *fin;
	fin=fopen("Empl.dat","rb");
	if(fin!=NULL)
	{
		fread(&e,sizeof(e),1,fin);
		if(SI==e.emplId )
		{
			if(strcmp(e.pass,pass)==0)
			{	
				if(e.flag==0)
				{
					printf("\nEmployee Login Successfull\n\n");
					employeeLogin();
				}
				else
				{
					printf("Blocked...Please contact admin....ASAP");
					main();
				}
			}
			else
			{
				printf("Password does not match...Please try again");
				printf("Enter any key...");
				getch();
				main();
			}
		}
		else
		{
			printf("Employee ID incorrect...Please try again");
			main();
		}	
	}
	else
	{
		printf("Unable to open file...Please try again");
		main();
	}
	fclose(fin);	
} 




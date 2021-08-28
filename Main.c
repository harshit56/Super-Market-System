#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

//Custom Header Files
#include<C:\users\flash\desktop\c\headerfiles\EmployeeOptions.c>
#include<C:\users\flash\desktop\c\headerfiles\StockOptions.c>
#include<C:\users\flash\desktop\c\headerfiles\Billing.c>
#include<C:\users\flash\desktop\c\headerfiles\Logo.c>


int main()                                                                                                                             //Main Menu
{
	int loop=1,a;
	char log[10]="Login";
	char pass[10];
	system("cls");
	while(loop)
	{
		Name();
		printf("\nMain Menu\n\n");
		printf("1.Admin\n2.User\n3.Exit\n\nEnter your choice:");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
					printf("Enter Password to login:");
					scanf("%s",pass);
					if(strcmp(log,pass)==0)
					{
						printf("Log In Successful");
						adminMenu();
						break;
					}
					else
					{
						printf("Wrong Password");
						main();
						break;
					}
			case 2:
					userMenu();
					break;
			case 3:
					printf("Closing Application");
					exit(0);
					break;
			default:
					printf("Invalid Option");
		}
	}
	return 0;
}


int adminMenu()                                                                                                                             //Admin Menu
{
	int a;
	system("cls");
	Name();
	printf("\n\n1.Employee Option\n2.Stock option\n3.Main Menu\n\nEnter your choice:");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
				employeeOptions();
				break;
		case 2:
				stockOptions();
				break;
		case 3:
				main();
				break;
	}	
	return 0;
}

int employeeOptions()                                                                                                                       //Employee
{
	int a;
	system("cls");
	Name();
	printf("\n\nMain Menu->Admin Menu->Employee \n\n");
	printf("1.New Employee\n2.Search Employee\n3.Block Employee\n4.Unblock Employee\n5.Modify Employee\n6.Delete Employee\n7.Admin Menu\n8.Main Menu\n\nEnter your choice:");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			newEmployee();
			break;
		case 2:
			searchEmployee();
			break;
		case 3:
			blockEmployee();
			break;
		case 4:
			unblockEmployee();
			break;
		case 5:
			modifyEmployee();
			break;	
		case 6:
			deleteEmployee();
			break;	
		case 7:
			adminMenu();
			break;
		case 8:
			main();
			break;
		default: 
			printf("Invalid Option\nPlease enter correctly\n");
			employeeOptions();
	}	
	return 0;
}



int stockOptions()                                                                                                //Stock Option
{
	int a;
	system("cls");
	Name();
	printf("\n\n\nMain Menu->Admin Menu->Stock\n\n");
	printf("1.New Product\n2.Search Product\n3.Modify Product\n4.Block Product\n5.Unblock Product\n6.Delete Product\n7.Stock Update\n8.Admin Menu\n9.Main Menu\n\nEnter your choice:");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
				newProduct();
				break;
		case 2:
				searchProduct();
				break;
		case 3:
				modifyProduct();
				break;
		case 4:
				blockProduct();
				break;
		case 5:
				unblockProduct();
				break;
		case 6:
				deleteProduct();
				break;
		case 7:
				updateStock();
				break;
		case 8:
				adminMenu();
				break;
		case 9:
				main();
				break;	
			
		default:
				
				printf("Invalid Options");		
	}
	return 0;
}

int userMenu(void)                                                                                                                      //User Menu
{
	Employee e;
	system("cls");
	Name();
	int sid;
	char pass[30];
	printf("\n\nMain Menu->User Menu\n\n");
	printf("Enter Employee ID to login:");
	scanf("%d",&sid);
	FILE *fin;
	fin=fopen("Empl.dat","rb");
	if(fin!=NULL)
	{
		fread(&e,sizeof(e),1,fin);
		if(sid==e.emplId )
		{
			while(1)
			{
				printf("Enter Password:");
				scanf("%s",pass);
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
					printf("Enter any key...\n\n");
					getch();
				}
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

int employeeLogin()                                                                                              //Employee employeeLogin
{
	int op;
	system("cls");
	Name();
	printf("\n\nMain Menu->User Menu->Employee Login\n\n");
	printf("1.New Bill\n2.Search Bill\n3.Stock Enquiry\n4.Logout\n\nEnter your choice:");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			Bill();
			break;			
		case 2:
			searchBill();
			break;
		case 3:
			searchQuantity();
			break;
		case 4:
			main();
			break;
		default:
			printf("Invalid Option");
	}
}






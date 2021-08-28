
typedef struct Stk                                                                                                                         //Struture Stock
{
	int productId,flag,productQty;
	float productPrice;
	char productName[50];
}Stock;


void newProduct()                                                                                                                    //New Product
{
		Stock s;
		system("cls");
		Name();
		char ch;
		FILE *gout; //File Pointer	
		printf("\n\nMain Menu->Admin Menu->Stock->Product Entry\n\n");
		do
		{
			printf("Enter New Product Details below:\n\n");
			printf("Enter Product Id:");
			scanf("%d",&s.productId);
			printf("Enter Product name:");
			fflush(stdin);
			gets(s.productName);
			printf("Enter product Price:");
			scanf("%f",&s.productPrice);
			printf("Enter Product Available Quantity:");
			scanf("%d",&s.productQty);
			gout=fopen("Stock.dat","ab"); //Opening of File(Stock.dat)
			if(gout!=NULL)
			{
				s.flag=0;
				fwrite(&s,sizeof(s),1,gout);
				printf("\n\nData Stored Successfully\n");
			}
			else
			{
				printf("Unable to open file");
			}
			fclose(gout);
			printf("\nDo you want to add new product again(Y/N): ");
			fflush(stdin);
			scanf("%c",&ch);
		}while(ch=='Y'||ch=='y');
		printf("Press any key to continue.....");
		getch();
		stockOptions();
}

void searchProduct()                                                                                                                  //Search Product
{
	Stock s;
	char ch;
	system("cls");
	Name();
	int found;
	printf("\n\nMain Menu->Admin Menu->Stock->Search Stock\n\n");
	FILE *gin; //File Pointer
	int Sp;
	do
	{
		system("cls");
		gin=fopen("Stock.dat","rb");
		if(gin!=NULL)
		{
			printf("Enter Product ID to Search:");
			scanf("%d",&Sp);
			while(fread(&s,sizeof(s),1,gin))
			{
				if(Sp==s.productId)
				{
					printf("\nSearched Successfully\n\n");
					printf("\nProduct Details are:\n\n");
					printf("Product ID:%d\nProduct Name:%s\nProduct Price:%f\nProduct Avaliable Quantity:%d\n",s.productId,s.productName,s.productPrice,s.productQty);
					if(s.flag==0)
					{
						printf("Product Status: Available");
					}
					else
					{
						printf("Product Status: Blocked");
					}
					found=1;
					fclose(gin);
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
				fclose(gin);
				stockOptions();
			}
		}
		else
		{
			printf("Unable..to open file");
			stockOptions();
		}	
	}while(ch=='Y'||ch=='y');
	printf("Press any key to continue.....");
	getch();
	stockOptions();
}

void modifyProduct()                                                                                                        //Modify Product
{
	Stock s;
	system("cls");
	Name();
	int Sp,op,status=0;
	printf("\n\nMain Menu->Admin Menu->Stock->Modify Stock\n\n");
	FILE *gin,*gout;
	gin=fopen("Stock.dat","rb");
	gout=fopen("Modify.dat","wb");
	if(gin!=NULL||gout!=NULL)
	{
		printf("Enter Product ID to modify:");
		scanf("%d",&Sp);
		while(fread(&s,sizeof(s),1,gin))
		{
			if(Sp==s.productId)
			{
				status=1;
				printf("1.Modify name\n2.Modify Price\n3.Modify Quantity\n\nEnter your choice:");
				scanf("%d",&op);
				switch(op)
				{
					case 1:
						printf("Enter Product name:");
						fflush(stdin);
						gets(s.productName);
						break;
					case 2:
						printf("Enter Product Price:");
						scanf("%f",&s.productPrice);
						break;
					case 3:
						printf("Enter Product Quantity:");
						scanf("%d",&s.productQty);
						break;
				}
			
			}
			fwrite(&s,sizeof(s),1,gout);
		}
	}
	else
	{
		printf("Unable to open file");
	}
	fclose(gin);
	fclose(gout);
	if(status==1)
	{
		printf("\nData Modified Successfully\n\n");
		remove("Stock.dat");
		rename("Modify.dat","Stock.dat");
	}
	else
	{
		printf("\nRecord not found...");
		remove("Modify.dat");
	}
	printf("\n\nPress any key to continue....");
	getch();
	stockOptions();
}


void blockProduct()                                                                                                                            //Product Block
{
	Stock s;
	system("cls");
	Name();
	int Sp,status=0;
	printf("\n\nMain Menu->Admin Menu->Stock->Block Stock\n\n");
	FILE *gin,*gout; //File Pointer
	gin=fopen("Stock.dat","rb");
	gout=fopen("Stockblock.dat","wb");
	if(gin!=NULL||gout!=NULL)
	{
		TRYING:
		printf("Enter Product ID to block:");
		scanf("%d",&Sp);
		while(fread(&s,sizeof(s),1,gin))
		{
			if(Sp==s.productId)
			{
				s.flag=1;
				status=1;
			}
			fwrite(&s,sizeof(s),1,gout);
		}
		fclose(gin);
		fclose(gout);
		if(status==1)
		{
			printf("Product was blocked successfully\n\n");
			remove("Stock.dat");
			rename("Stockblock.dat","Stock.dat");
			stockOptions();
		}
		else
		{
			printf("Record not found...");
			remove("Stockblock,dat");
		}
	}
	else
	{
		printf("Unable to open file...");
	}
	printf("Press any to continue....");
	getch();
	stockOptions();	
}

void unblockProduct()                                                                                                                  //Employee Unblock
{
	Stock s;
	system("cls");
	Name();
	int Sp,status;
	printf("\n\nMain Menu->Admin Menu->Stock->Unblock Stock\n\n");
	FILE *gin,*gout; //File Pointer
	gin=fopen("Stock.dat","rb");
	gout=fopen("Stockunblock.dat","wb");
	if(gin!=NULL||gout!=NULL)
	{
		printf("Enter Stock ID to block:");
		scanf("%d",&Sp);
		while(fread(&s,sizeof(s),1,gin))
		{
			if(Sp==s.productId)
			{
				s.flag=0;
				status=1;
			}
			fwrite(&s,sizeof(s),1,gout);
		}
		fclose(gin);
		fclose(gout);
		if(status==1)
		{
			printf("\nProduct was unblocked successfully\n\n");
			remove("Stock.dat");
			rename("Stockunblock.dat","Stock.dat");
		}
		else
		{
			printf("Record not found...");
			remove("Stockunblock.dat");
		}
	}
	else
	{
		printf("Unable to open file...");
	}
	printf("Press any key to continue...");
	getch();
	stockOptions();
}

void deleteProduct()                                                                                                                   //Product Delete
{
	Stock s;
	system("cls");
	Name();
	int Sp,status=0;
	printf("\n\nMain Menu->Admin Menu->Stock->Delete Stock\n\n");
	FILE *gin,*gout;
	gin=fopen("Stock.dat","rb");
	gout=fopen("StockDel.dat","wb");  //Opening of a file(StockDelete.dat)
	if(gin!=NULL||gout!=NULL)
	{
		printf("Enter Product ID to delete:");
		scanf("%d",&Sp);
		while(fread(&s,sizeof(s),1,gin))
		{
			if(Sp!=s.productId)
			{
				fwrite(&s,sizeof(s),1,gout);
			}
			else
			{
				status=1;
			}
		}
		fclose(gin);
		fclose(gout);
		if(status==1)
		{
			printf("Deleted Successfully");
			remove("Stock.dat");
			rename("StockDel.dat","Stock.dat");
		}
		else
		{
			printf("Record not found...");
			remove("StockDel.dat");
		}
	}
	else
	{
		printf("Unable to open file");
	}
	printf("Press any key to continue....");
	getch();
	stockOptions();
}

void updateStock()
{
	Stock s;
	system("cls");
	Name();
	int Sp,status=0;
	FILE *gin,*gout;
	gin=fopen("Stock.dat","rb");
	gout=fopen("Update.dat","wb");
	if(gin!=NULL||gout!=NULL)
	{
		printf("Enter Product ID to update Quantity:");
		scanf("%d",&Sp);
		while(fread(&s,sizeof(s),1,gin))
		{
			if(Sp==s.productId)
			{
				status=1;
				printf("Enter Product New Quantity:");
				scanf("%d",&s.productQty);
				break;
			}
		}
		fwrite(&s,sizeof(s),1,gout);
	}
	else
	{
		printf("Unable to open file");
	}
	fclose(gin);
	fclose(gout);
	if(status==1)
	{
		printf("\nData Modified Successfully\n\n");
		remove("Stock.dat");
		rename("Update.dat","Stock.dat");
	}
	else
	{
		printf("\nRecord not found...");
		remove("Update.dat");
	}
	printf("Press any key to continue...");
	getch();
	stockOptions();
}

	

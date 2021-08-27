//Bill Generation

typedef struct Bill
{
	char invNo[10],prdName[30];
	int prdId,units;
	float prdPrice,amount;
}Billing;

void Bill()
{
	typedef struct Stk                                                                                                                         //Struture Stock
	{
		int productId,flag,productQty;
		float productPrice;
		char productName[50];
	}Stock;

	system("cls");
	Name();
	Stock stk;
	Billing b;
	int sid,found,newInvNo;
	char ch,invNo[10];
	float totInvAmt=0;
	FILE *fin,*fout,*invlog;             //File Pointer
	printf("\n\nMain Menu->User Menu->Employee Login->New Invoice\n\n");
	invlog=fopen("invoicelog.dat","r");
	if(invlog!=NULL)
	{
		while(!feof(invlog))
		{
			fscanf(invlog,"%d\n",&newInvNo);
		}
	}
	else
	{
		printf("Error: Unable to open Invoice Log file.....");
	}
	fclose(invlog);
	//newInvNo=atoi(b.invNo);
	newInvNo++;
	itoa(newInvNo,b.invNo,10);
	printf("New Invoice number: %s",b.invNo);
	getch();
	//scanf("%s",b.invNo);
	fin=fopen("Stock.dat","rb+");
	if(fin!=NULL)
	{
		do
		{
			system("cls");
			Name();
			printf("\n\nEnter Product Id:");
			scanf("%d",&sid);
			while(fread(&stk,sizeof(Stock),1,fin))
			{
				if(sid==stk.productId)
				{
					found=1;
					if(stk.productQty>0)
					{
						printf("Available Stock: %d\n\n",stk.productQty);
						printf("No of Units Purchased:");
						scanf("%d",&b.units);
						b.amount=stk.productPrice*b.units;
						b.prdId=stk.productId;
						strcpy(b.prdName,stk.productName);
						b.prdPrice=stk.productPrice;
						totInvAmt+=b.amount;
						printf("PID:%d\tPrd name:%s\tPrd Price:%f\tNo of Units:%d\tAmount:%.2f\n\n",b.prdId,b.prdName,b.prdPrice,b.units,b.amount);
						fout=fopen(b.invNo,"ab");//Opening of File of invioce
						if(fout!=NULL)
						{
							fwrite(&b,sizeof(b),1,fout);
						}
						else
						{		
							printf("Error: File Not Opened.....Unable to generate invoice.....\n\n");
						}
						fclose(fout);
					}
					else
					{
						printf("Sorry.... Out of Stock...\n\n");
					}
					stk.productQty-=b.units;
					fseek(fin,-(sizeof(Stock)),SEEK_CUR);
					fwrite(&stk,sizeof(Stock),1,fin);
					rewind(fin);
					invlog=fopen("invoicelog.dat","a");
					if(invlog!=NULL)
					{
						fprintf(invlog,"%d\n",newInvNo);
					}
					else
					{
						printf("Error: Unable to open Invoice Log file.....");
					}
					fclose(invlog);
					break;
				}
				else
				{
					found=0;
				}
				
			}
			if(found==0)
			{
				printf("Product Not Found...\n\n");
				rewind(fin);
			}
			printf("Do you want to add another product(Y/N): ");
			fflush(stdin);
			scanf("%c",&ch);
		}while(ch=='Y'||ch=='y');
	}
	else
	{
		printf("Error: File Not Opened.....");
	}
	fclose(fin);
	printf("\n\nTotal Invoice Amount: %.2f\n\n",totInvAmt);
	printf("Press any key to continue.....");
	getch();
	employeeLogin();
}


//Bill Searching

void searchBill()
{
	system("cls");
	Name();
	printf("\n\nMain Menu->User Menu->Employee Login->Search Invoice\n\n");
	FILE *fin,*invlog;//File Pointer
	Billing sb;
	char foundInvNo[10];
	int sinvNo,invNo,found;
	float totInvAmt=0;
	char op;
	do
	{
		printf("Enter Invoce Number to serch: ");
		scanf("%d",&sinvNo);
		invlog=fopen("invoicelog.dat","r");
		if(invlog!=NULL)
		{
			while(!feof(invlog))
			{
				fscanf(invlog,"%d\n",&invNo);
				if(sinvNo==invNo)
				{
					found=1;
					break;
				}
			}
			
		}
		else
		{
			printf("Error: Unable to open Invoice Log file.....");
		}
		fclose(invlog);
		if(found==1)
		{
			itoa(sinvNo,foundInvNo,10);
			fin=fopen(foundInvNo,"rb");
			if(fin!=NULL)
			{
				printf("Invoice Details\n\n");
				printf("Invoice No: %s\n",foundInvNo);
				while(fread(&sb,sizeof(sb),1,fin))
				{
					printf("PID:%d\tPrd name:%s\tPrd Price:%f\tNo of Units:%d\tAmount:%.2f\n",sb.prdId,sb.prdName,sb.prdPrice,sb.units,sb.amount);
					totInvAmt+=sb.amount;
				}
				printf("\nTotal Invoice Amount: %.2f",totInvAmt);
			}
			fclose(fin);
		}
		else
		{
			printf("Invalid Invoice Number...\n");
		}
		printf("\n\nDo you want to search another Invoice (Y/N): ");
		fflush(stdin);
		scanf("%c",&op);
	}while(op=='y'||op=='Y');
	printf("Press any key to continue.....");
	getch();
	employeeLogin();
}



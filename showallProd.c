#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef struct Stk                                                                                                                         //Struture Stock
{
	int productId,flag,productQty;
	float productPrice;
	char productName[50];
}Stock;

int main()
{
	Stock s;
	system("cls");
	FILE *gin; //File Pointer
	gin=fopen("Stock.dat","rb");
	while(fread(&s,sizeof(s),1,gin))
	{
		//fread(&e,sizeof(e),1,fin);
		printf("Product Id:%d\tProduct Name:%s\tProduct Price:%f\tAvailable Quantity:%d\t",s.productId,s.productName,s.productPrice,s.productQty);
		if(s.flag==0)
		{	
			printf("Product Status: Available");
		}
		printf("\n");
	
	}
	fclose(gin);
	return 0;
}


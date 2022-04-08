#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int id;
	char product_name[30];
	float price;
	int quantity;
}c[5];


void display()
{
	int i, flag = 0;

	for(i = 0; i < 5; i++)
	{
		if(c[i].id != -1)
		{
			flag = 1;
			
			printf("\nYour cart : \n");
			
			printf("ID\tProduct\t\tPrice\t  Quantity\n");
			
			for(i = 0; i < 5; i++)
			{
				if(c[i].id != -1)
				{
					printf("%d\t", c[i].id);
					printf("%s\t\t", c[i].product_name);
					printf("%.2f\t  ", c[i].price);
					printf("%d\n", c[i].quantity);
				}
			}
			printf("\n");
		}
	}
	if(flag == 0)
	{
		printf("Your cart is empty!!\n");
	}		
}

void add_to_cart()
{
	int i, choice, count, flag = 0;
	float price;
	          // count = count_cart();
	
	for(i = 0; i < 5; i++)
	{
		if(c[i].id == -1)
		{
			printf("Enter the product name : ");
			scanf("%s", c[i].product_name);
			
			printf("Enter the ID of product : ");
			scanf("%d", &c[i].id);
			
			printf("Enter the price of product : ");
			scanf("%f", &price);

			printf("Enter the quantity to buy : ");
			scanf("%d", &c[i].quantity);
		
			c[i].price = (price) * ((float)c[i].quantity);
			
			flag = 0;
			break;
		}
		else
		{
			flag = 1;
		}
	}
	if(flag == 1)
	{
		printf("Your cart is full !\n");
	}
}

void remove_from_cart(int data)
{
	int i, flag = 0;
	char name[20];
		
	for(i = 0; i < 5; i++)
	{
		if(c[i].id == data)
		{
			strcpy(name, c[i].product_name);
			c[i].id = -1;
			flag = 0;
			break;
		}
		else
		{
			flag = 1;
		}
	}
	if(flag == 1)
	{
		printf("\nProduct is Not avaliable with that Id!!\n");
	}
	else
	{
		printf("\nData deleted from the cart  %d : %s\n", data, name);
	}
}

void file_write(FILE *fp)
{
	int i;
	if(fp == NULL)
	{
		fp = fopen("shoping_list_file.txt", "w");  // 'w' means open file for writing ,if already file exit it destroy all data,file doesnt exit then create new 
		fprintf(fp,"ID\tProduct\t\tPrice\t  Quantity\n");
			
		for(i = 0; i < 5; i++)
		{
			if(c[i].id != -1)
			{
				fprintf(fp, "%d\t", c[i].id);        // fprintf means write set of data values
				fprintf(fp, "%s\t\t", c[i].product_name);
				fprintf(fp, "%.2f\t  ", c[i].price);
				fprintf(fp, "%d\n", c[i].quantity);
			}
		}
		// fprintf(fp,"\n");
	}	
	else
	{
		fp = fopen("shoping_list_file.txt", "a"); 
		
		for(i = 0; i < 5; i++)
		{
			if(c[i].id != -1)
			{
				fprintf(fp, "%d\t", c[i].id);
				fprintf(fp, "%s\t\t", c[i].product_name);
				fprintf(fp, "%.2f\t  ", c[i].price);
				fprintf(fp, "%d\n", c[i].quantity);
			}
		}
	//	fprintf(fp,"\n");
	}
}

void main()
{
	int choice, data, i, flag = 0;
	FILE *fp  = NULL; 
	
	for(i = 0; i < 5; i++)
	{
		c[i].id = -1;
	}
	printf("1.Add Item\n2.Remove Item\n3.Display\n4.Exit\n");
	
	while(1)
	{
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
	
				add_to_cart();
				break;
			
			case 2:
				printf("\nEnter Id of Product To Remove : ");
				scanf("%d", &data);
				
				remove_from_cart(data);
				break;
			
			case 3:
				display();
				break;
			
			case 4:
				printf("Writing all data in the file...\n");
				
				file_write(fp);
				break;
			
			case 5:
				exit(0);
				break;
			
			default :
				printf("\nPlease enter a valid choice !!\n");	
				break;
		}
	}
}	

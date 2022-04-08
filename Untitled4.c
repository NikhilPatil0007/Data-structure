#include<stdio.h>
#include<stdlib.h>

int decimal_binary(int num)
{
int digit,binary=0,i=1;
while(num>0)
{
digit=num%2;
binary=digit*i+binary;
i=i*10;
num=num/2;
}
return binary;
}

int binary_decimal(int num)
{
int digit,decimal=0,i=1;
while(num!=0)
{
digit=num%10;
decimal=(digit*i)+decimal;
i=i*2;
num=num/10;
}
return decimal;
}

int main()
{
char str[100],str1[100],str2[100];
int a,b,c,d,a1,b1,c1,d1,a3,b3,c3,d3;
int a2,b2,c2,d2,choice,temp=0;
do{
printf("Enter 1 for decimal to binary conversion of IP address\nEnter 2 for binary to decimal conversion of IP address: ");
scanf("%d",&choice);
switch(choice)
{
	case 1: printf("Enter a IP address in decimal format: ");
			scanf("%s",str);
			sscanf(str,"%d.%d.%d.%d",&a,&b,&c,&d);
			a1=decimal_binary(a);
			b1=decimal_binary(b);
			c1=decimal_binary(c);
			d1=decimal_binary(d);
			printf("\nDecimal to binary conversion of IP address:  ");
			printf("%d %d %d %d",a1,b1,c1,d1);
	break;
	case 2: printf("Enter a IP address in binary format: ");
			scanf("%d %d %d %d",&a3,&b3,&c3,&d3);
			a2=binary_decimal(a3);
			b2=binary_decimal(b3);
			c2=binary_decimal(c3);
			d2=binary_decimal(d3);
			printf("\nBinary to decimal conversion of IP address: ");
			printf("%d.%d.%d.%d",a2,b2,c2,d2);
	break;
	default: printf("Enter valid choice...");
}
printf("\nDo you want to perform any other operation? if no enter 1 otherwise enter 0: ");
scanf("%d",&temp);
}while(temp==0);

return 0;
}


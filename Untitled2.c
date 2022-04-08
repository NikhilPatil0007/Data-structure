#include <stdio.h>
int main()
{
	char str[100];
	printf("enter ip address\n");
	scanf("%s",str);
	int w,x,y,z;
	sscanf(str,"%d.%d.%d.%d",&w,&x,&y,&z);
	if(w<=255&&x<=255&&y<=255&&z<=255)
	{
		if(w>=0&&w<128)
		{
			printf("ip belongs to class A\n");
			printf("Net id=%d\n",w);
			printf("Host id=%d.%d.%d\n",x,y,z);
			printf("default mask=255.0.0.0\n");
		}
		else if(w>=128&&w<192)
		{
			printf("ip belongs to class B\n");
			printf("Net id=%d.%d\n",w,x);
			printf("Host id=%d.%d\n",y,z);
			printf("default mask=255.255.0.0\n");
		}
		else if(w>=192&&w<224)
		{
			printf("ip belongs to class C\n");
			printf("Net id=%d.%d.%d\n",w,x,y);
			printf("Host id=%d\n",z);
			printf("default mask=255.255.255.0\n");
		}
		else if(w>=224&&w<240)
		{
			printf("ip belongs to class D\n");
			printf("net id ,host id ,default mask does not exist for class D\n");
		}
		else
		{
			if(w>=240&&w<256)
			{
				printf("ip belongs to class E\n");
			printf("net id ,host id ,default mask does not exist for class E\n");
			}
		}
	}
	else
	{
		printf("please enter valid ip address\n");
	}
	return 0;

}


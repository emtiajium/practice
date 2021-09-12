#include<stdio.h>
#include<math.h>
int bin(int a)
{
	int b,i,j=0,ar[100];
	while(a!=0)
	{
		b=a%2;
		a=a/2;
		ar[j++]=b;
	}
	for(i=j-1;i>=0;i--)
	{
	    printf("%d",ar[i]);
	}
	return 0;
}
int hex(int a)
{
	int b,i,j=0,ar[100];
	while(a!=0)
	{
		b=a%16;
		a=a/16;
        ar[j++]=b;
	}
	for(i=j-1;i>=0;i--)
	{
		if(ar[i]<=9)
		{
			printf("%d",ar[i]);
		}
		else if(ar[i]==10)
			printf("A");
		else if(ar[i]==11)
			printf("B");
        else if(ar[i]==12)
			printf("C");
		else if(ar[i]==13)
			printf("D");
        else if(ar[i]==14)
			printf("E");
	   	else if(ar[i]==15)
			printf("F");

	}
	return 0;
}
int oct(int a)
{
	int b,i,j=0,ar[100];
    while(a!=0)
	{
		b=a%8;
		a=a/8;
		ar[j++]=b;
	}
	for(i=j-1;i>=0;i--)
	{
		if(ar[i]<=7)
		{
			printf("%d",ar[i]);
		}
        else if(ar[i]==8)
			printf("10");
		else if(ar[i]==9)
			printf("11");
        else if(ar[i]==10)
			printf("12");
		else if(ar[i]==11)
			printf("13");
        else if(ar[i]==12)
			printf("14");
	   	else if(ar[i]==13)
			printf("14");
        else if(ar[i]==14)
			printf("16");
	   	else if(ar[i]==15)
			printf("17");

	}
	return 0;
}
int main()
{
	int a,b,i,r,h,res,v,c,x;
	printf("\n\t\t\t\t*****WELCOME*****\n");
	printf("\n\tINPUT 1 OCTAL TO OTHER NUMBER CONVERT:\n"); 
	printf("\tINPUT 2 DECIMAL TO OTHER NUMBER CONVERT:\n");
	printf("\tINPUT 3 BINARY TO OTHER NUMBER CONVERT:\n");
	printf("\tINPUT 4 HEXADECIMAL TO OTHER NUMBER CONVERT:\n");
	printf("\tINPUT 0 FOR PROGRAM BREAK:\n");
	while(1)
	{
		printf("\n\n\twhich categary number you want to input:");
		scanf("%d",&v);
		i=0;r=0;
		if(v==0)
		{
			break;
		}
		while(v==1)
		{
			printf("INPUT A OCTAL NUMBER:");
			{
				c=0;
				scanf("%d",&a);
				x=a;
				while(a!=0)
				{
					b=a%10;
					a=a/10;
					r=r+pow(8,i)*b;
					i++;
				}
				printf("\n\t\tRESULTENT VALUE OF %d NUMBER:\n",x);
				printf("\noctal to decimal: %d",r);
				c++;
				printf("\noctal to binary:");
				res=bin(r);
				c++;
				printf("\noctal to hexadecimal:");
				h=hex(r);
				c++;
				if(c==3)
				{
					break;
				}
			}
		}
		while(v==2)
		{
			printf("\nINPUT A DECIMAL NUMBER:");
			{
				c=0;
				scanf("%d",&a);
				printf("\n\t\tRESULTENT VALUE OF %d NUMBER:\n",a);
				printf("\ndecemel to octal :");
				oct(a);
				c++;
				printf("\ndecemel to binary :");
				bin(a);
				c++;
				printf("\ndecemel to hexadecimal :");
				hex(a);
				c++;
				if(c==3)
				{
					break;
				}
			}
		}
		while(v==3)
		{
			printf("INPUT A BINARY NUMBER:");
			{
				c=0;
				scanf("%d",&a);
				x=a;
				while(a!=0)
				{
					b=a%10;
					a=a/10;
					r=r+pow(2,i)*b;
					i++;
				}
				printf("\n\t\tRESULTENT VALUE OF %d NUMBER:\n",x);
				printf("\nbinary to decimel: %d",r);
				c++;
				printf("\nbinary to octal:");
				oct(r);
				c++;
				printf("\nbinary to hexadeiemal:");
				hex(r);
				c++;
				if(c==3)
				{
					break;
				}
			}
		}
		while(v==4)
		{
			printf("INPUT A HEXADECIMAL NUMBER:");
			{
				c=0;
				scanf("%d",&a);
				x=a;
				while(a!=0)
				{
					b=a%10;
					a=a/10;
					r=r+pow(16,i)*b;
					i++;
				}
				printf("\n\t\tRESULTENT VALUE OF %d NUMBER:\n",x);
				printf("\nhexadecimal to decemel: %d",r);
				c++;
				printf("\nhexadecimal to octal:");
				oct(r);
				c++;
				printf("\nhexadecimal to binary:");
				bin(r);
				c++;
				if(c==3)
				{
					break;
				}
			}
		}
	}
	return 0;
}	

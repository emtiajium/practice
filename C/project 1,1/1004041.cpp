#include<stdio.h>
#include<string.h>
#include<math.h>
int con(long a,long e)
{
	long i,c;
	char b[100];
	for(i=0;a>0;i++)
	{
		c=a%e;
		if(c<=9)
		{
			c=c+48;
			b[i]=c;
		}
		else if(c==10)
		{
			b[i]='A';
		}
		else if(c==11)
		{
			b[i]='B';
		}
		else if(c==12)
		{
			b[i]='C';
		}
		else if(c==13)
		{
			b[i]='D';
		}
		else if(c==14)
		{
			b[i]='E';
		}
		else if(c==15)
		{
			b[i]='F';
		}
		a=a/e;
	}
	i--;
	while(i>=0)
	{
		printf("%c",b[i]);
		i--;
	}
	return 0;
}
int con_dec(long a,long e)
{
	long b,c,d=0;
	for(b=1;a>=1;b=b*e)
	{
		c=a%10;
		a=a/10;
		c=c*b;
		d=d+c;
	}
	return d;
}






int main()
{
	long a,b,c,d,i=0,j,k,l=0,g,n=0,z;
	char e[20],f,h,y[]="y",x[5];
	while(2)
	{
		printf("\n\n\n\tTo Input Decimal Number Press   1\n\n\tTo Input Binary Number Press   2\n\n\tTo Input Octal Number Press   3\n\n\tTo Input Hexadecimal Number Press  4\n\n\t");
		scanf("%lld",&c);
		if(c==1)
		{
			printf("\n\n\n\n\n\t\tEnter a Decimal Number  : ");
			scanf("%lld",&a);
			b=2;
			printf("\n\n\t\t    Bionary  : ");
			con(a,b);
			b=8;
			printf("\n\n\t\t      Octal  : ");
			con(a,b);
			b=16;
			printf("\n\n\t\tHexadecimal  : ");
			con(a,b);
		}
		if(c==2)
		{
			printf("\n\n\n\n\n\t\tEnter a Binary Number  : ");
			scanf("%lld",&a);
			b=2;
			d=con_dec(a,b);
			printf("\n\n\t\t    Decimal  : %lld",d);
			a=d;
			b=8;
			printf("\n\n\t\t      Octal  : ");
			con(a,b);
			b=16;
			printf("\n\n\t\tHexadecimal  : ");
			con(a,b);
		}
		if(c==3)
		{
			printf("\n\n\n\n\n\t\tEnter a Octal Number  : ");
			scanf("%lld",&a);
			b=8;
			d=con_dec(a,b);
			printf("\n\n\t\t    Decimal  : %lld",d);
			a=d;
			b=2;
			printf("\n\n\t\t     Binary  : ");
			con(a,b);
			b=16;
			printf("\n\n\t\tHexadecimal  : ");
			con(a,b);
		}
		if(c==4)
		{
			getchar();
			printf("\n\n\n\n\n\t\tEnter a Hexadecimal Number  : ");
			while((f=getchar())!='\n')
			{
				e[i]=f;
				i++;
			}
			e[i]='\0';
			i--;
			for(j=i;j>=0;j--)
			{
				h=e[j];
				if(h=='A')
				{
					g=10;
				}
				else if(h=='B')
				{
					g=11;
				}
				else if(h=='C')
				{
					g=12;
				}
				else if(h=='D')
				{
					g=13;
				}
				else if(h=='E')
				{
					g=14;
				}
				else if(h=='F')
				{
					g=15;
				}
				else
				{
					g=h-48;
				}
				k=pow(16,n);
				g=g*k;
				l=l+g;
				n++;
			}
			printf("\n\n\t\t    Decimal  : %lld",l);
			a=l;
			b=2;
			printf("\n\n\t\t    Bionary  : ");
			con(a,b);
			b=8;
			printf("\n\n\t\t      Octal  : ");
			con(a,b);
		}
		printf("\n\n\n\tIf you want to quit this Program press \"Y\".\n\n\tTo continue this program press any other key.\n\n\n\n");
		scanf("%s",x);
		z=strcmp(x,y);
		if(z==0)
			break;
		else
			continue;
	}
	return 0;
}

#include<stdio.h>
#include<math.h>
main()
{
	int a,b,i,x,c[100];
	emtiaj:
	scanf("%d",&a);
	if(a==0)
	{
		printf("zero");
	    goto emtiaj;
	}
	x=log10(a)+1;
	for(i=0;i<x;i++)
	{
		b=a%10;
		c[i]=b;
		a/=10;
	}
	for(i=x-1;i>=0;i--)
	{
		switch(c[i])
		{
		case 0:
		printf("\tzero");break;
		case 1:
		printf("\tone");break;
		case 2:
		printf("\ttwo");break;
		case 3:
		printf("\tthree");break;
		case 4:
		printf("\tfour");break;
		case 5:
		printf("\tfive");break;
		case 6:
		printf("\tsix");break;
		case 7:
		printf("\tseven");break;
		case 8:
		printf("\teight");break;
		case 9:
		printf("\tnine");break;
		}
	}
	return 0;
}
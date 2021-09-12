#include<stdio.h>
#include<math.h>
void main()
{	
	double x,sum=0,f=1;	int j=0;
	printf("input x:");
	scanf("%lf",&x);
	x=x*(3.1416/180);
	for(int i=1;i<=20;i++)
	{
		if(i==1)
		{
			sum=sum+1;
		}
		else
		{
			if(i%2==0)
			{
				for(int k=1;k<=j;k++)
				{
					f=f*k;
				}
				sum=sum-x*x/f;
				f=1;
			}
			else
			{
				for(int k=1;k<=j;k++)
				{
					f=f*k;
				}
				sum=sum+x*x/f;
				f=1;
			}
		}
		j=j+2;
	}
	printf("cosx=%lf",sum);

}

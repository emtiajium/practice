#include<stdio.h>
#define n 2
main()
{
	int a[10][10],b[10][10],c[10][10],i,j,k,sum;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			scanf("%d",&b[i][j]);
		}
		printf("\n");
	}
	/*for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("a[%d][%d]=%d\n",i,j,a[i][j]);
		}printf("\n");
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("b[%d][%d]=%d\n",i,j,b[i][j]);
		}printf("\n");
	}*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			sum=0;
			for(k=0;k<n;k++)
				sum+=a[i][k]*b[k][j];
			c[i][j]=sum;
			printf("%4d",c[i][j]);
		}
		printf("\n");
	}
}



#include<stdio.h>
#define size 10
main()
{              
	int a[size][size],b[size][size],c[size][size],i,j,k;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
		    scanf("%d",&a[i][j]);
		    scanf("%d",&b[i][j]);
		}
	}
	printf("\n");
	/*for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
			printf("a[%d][%d]=%d\n",i,j,a[i][j]);
		}printf("\n");
	}
	
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
			printf("b[%d][%d]=%d\n",i,j,b[i][j]);
		}printf("\n");
	}*/
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		printf("\t%d",c[i][j]);
		}
		printf("\n");
	}               
}


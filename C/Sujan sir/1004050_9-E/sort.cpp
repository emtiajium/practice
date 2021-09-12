#include<stdio.h>
#define N 10
main()
{
	int i,j,temp;
	int a[N]={100,30,200,30,150,-100,500,20,55,177};
	for(i=1;i<N;i++)
	{
		for(j=0;j<N-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(i=0;i<N;i++)
		printf("%5d ",a[i]);
}

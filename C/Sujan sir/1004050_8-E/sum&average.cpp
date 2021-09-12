#include<stdio.h>
int main()
{
	int sum=0,a[5],average;
	for(int i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
		average=sum/5;
	}
	printf("\n");
	printf("%d",average);
	return 0;
}
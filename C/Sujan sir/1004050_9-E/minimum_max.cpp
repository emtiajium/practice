#include<stdio.h>
int main()
{
	int min,a[5],max,i;
	for(i=0;i<5;i++)
	{
	    scanf("%d",&a[i]);
	}
	min=max=a[0];
	for(i=1;i<5;i++)
	{
	    if(a[i]<min) min=a[i];
		if(a[i]>max) max=a[i];
	}
	printf("min %d max %d\n",min,max);
    return 0;
}

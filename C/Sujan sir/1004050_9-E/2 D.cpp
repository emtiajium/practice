#include<stdio.h>
#include<time.h>
int main()
{
    double t1,t2;
    t1=clock();
	int i,j,a[3][5]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    t2=clock();
    printf("%lf\n",(t2-t1)/1000);
    return 0;
}









































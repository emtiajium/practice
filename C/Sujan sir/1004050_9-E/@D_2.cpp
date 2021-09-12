#include<stdio.h>
#include<time.h>
int main()
{
    double t1,t2;
    t1=clock();
    int i,a[3][5]={
                    {1,2,3,4,5},
                    {6,7,8,9,10},
                    {11,12,13,14,15}
                  };
    for(i=0;i<3;i++)
    {
        printf("%2d %2d %2d %2d %2d\n",a[i][0],a[i][1],a[i][2],a[i][3],a[i][4]);
    }
    t2=clock();
    printf("%lf\n",(t2-t1)/1000);
    return 0;
}

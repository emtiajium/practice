//processor takes more time doing multiplication than addition
#include<stdio.h>
int main()
{
    int n,i,j,sum;
    //scanf("%d",&n);
    for(j=6;j<=6;j++)
    {
        sum=0;
        for(i=1;i<=10;i++)
        {
            sum+=j;
            printf("%d X %2d = %2d\n",j,i,sum);
        }
        printf("\n");
    }
    return 0;
}

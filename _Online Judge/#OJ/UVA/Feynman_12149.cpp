#include<stdio.h>

int sum[105],n;
int num;

int main()
{
    for(n=1;n<=101;n++)
        sum[n]=(n*(n+1)*(2*n+1))/6;

    while(scanf("%d",&num)&&num){
        printf("%d\n",sum[num]);
    }
    return 0;
}

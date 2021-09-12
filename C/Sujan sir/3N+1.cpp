#include<stdio.h>
int main(void)
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int count=0;
        do
        {
            if(n%2!=0)n=3*n+1;
            else n=n/2;
            count++;
            printf("%d ",n);
        }
        while(n!=1);
        printf("\ncount %d\n",count);
    }
    return 0;
}




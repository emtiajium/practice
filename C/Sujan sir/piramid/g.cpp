#include<stdio.h>
int main()
{
    int n=5,p=5;
    //scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("%4d",n+1-j);
        }
        printf("\n");
    }
    return 0;
}

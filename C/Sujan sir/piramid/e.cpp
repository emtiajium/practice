#include<stdio.h>
int main()
{
    int n=5,p=1;
    //scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
        printf("%4d",i+j);
        }
        printf("\n");
    }
    return 0;
}

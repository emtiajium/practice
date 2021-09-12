#include<stdio.h>
int main()
{
    int n=5,p=1;
    //scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if((i+j)%2==0) printf("%4d",1);
            else printf("%4d",0);
        }
        printf("\n");
    }
    return 0;
}

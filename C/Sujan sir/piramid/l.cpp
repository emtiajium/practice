#include<stdio.h>
int main()
{
    int n=5;
    for(int i=n;i>0;i--)
    {
        for(int j=i;j>=1;j--)
        {
         printf("%4d",n+j-i);
        }
        printf("\n");
    }
    return 0;
}

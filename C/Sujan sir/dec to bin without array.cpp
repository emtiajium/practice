#include<stdio.h>
#include<conio.h>
int main()
{
    int n,a,c=0,i=1;
    scanf("%d",&n);
    while(n>0)
    {
        a=n%2;
        n=n/2;
        c+=(a*i);
        i=i*10;
    }
    printf("Binary is=%d",c);
    getch();
}        

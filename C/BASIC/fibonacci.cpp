#include<stdio.h>
#include<conio.h>
int main()
{
    int f1=0,f2=1,i,x;

    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
              int f3=f1+f2;
              printf("%d\t",f1);
              f1=f2;
              f2=f3;

    }


              getch();
              return 0;
}

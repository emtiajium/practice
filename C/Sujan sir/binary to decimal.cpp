#include<stdio.h>
#include<conio.h>
#include<math.h>
main (void)
{
    int a,b,sum,d;
    scanf("%d",&a);
    d=0;sum=0;
    while(a!=0)
    {
        b=a%10;
        a=a/10;
        sum+=(b*pow(2,d));
        d++;
       
    }
     printf("%d",sum);
    getch();
}        
    

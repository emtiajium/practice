#include<stdio.h>
int main ()
{
    int a,b,c,d,e;
    printf("Enter the value  ");
    scanf("%d",&a);
    b=a%10;
    c=a/10;
    d=(b*10)+c;
    printf("%d",d);
    return 0;//status code
}



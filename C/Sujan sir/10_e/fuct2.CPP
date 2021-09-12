#include<stdio.h>
#include<conio.h>
int mul (int a,int b);
int main()
{

int a,b,x;
scanf("%d %d",&a,&b);
x=mul(a,b);
printf("%d",x);
getch();
return (0);
}
int mul(int y,int z)
{ int d;
d=y*z;
return (d);
}

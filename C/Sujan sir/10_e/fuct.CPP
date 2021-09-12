#include<stdio.h>
#include<conio.h>
int fact(int a);
int main()
{

int a,d;
scanf("%d",&a);
d=fact(a);
printf("%d",d);
getch();
return 0;
}
int fact(int x)
{
int c=1,i;
for(i=x;i>0;i--)
c=c*i;
return (c);
}

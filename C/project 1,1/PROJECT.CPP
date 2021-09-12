#include<stdio.h>
#include<conio.h>
void factorial1()
{
int a,b,c,d,n;
printf("enter a number:");
scanf("%d",&n);
a=1;
c=1;
while(a<n)
{
b=a+1;
d=b*c;
a=b;
c=d;
}
printf("%d",d);
getch();
}
void series2()
{
int a,n;
printf("Enter a number:");
scanf("%d",&n);
for(a=n;a>0;a--)
{
printf("%d ",a);
}
getch();
}
void armstrongnum3()
{
int a,b,c,d,f,sum;
sum=0;
printf("Enter a number:");
scanf("%d",&a);
f=a;
while(a!=0)
{
b=a/10;
c=a%10;
d=c*c*c;
sum=sum+d;
 a=b;
}
if(sum==f)
{
printf("\n%d is armstrong number",f);
}
else
{
printf("\n %d is not armstrong number",f);
}
getch();
}
void deci_to_binary4()
{
int a,b,c,d,e,sum;
e=1;sum=0;
printf("Enter a number:");
scanf("%d",&a);
while(a!=0)
{
b=a/10;
c=a%10;
d=c*e;
e=e*2;
sum=sum+d;
a=b;
}
printf("decimal number is %d",sum);
getch();
}
void fibonacci5()
{
int a,b,c,s,n;
printf("enter a number:");
scanf("%d",&n);
a=0;
b=1;
while(a<=n)
{
c=a+b;
printf("%d ",c);
b=c-b;
a=c;
}
getch();
}
void sum_of_square_series6()
{
int a,b,c,d,n;
char e;
e='+';
c=0;
printf("Enter a  number:");
scanf("%d",&a);
for(n=0;n<=a;n++)
{
 b=n*n;
 printf("%d %c\n",b,e);
 c=c+b;
}
printf("sum= %d",c);
getch();
}
void pyramid7()
{
int i,j,n;
n=5;
for(j=1;j<=n;j++)
{
printf("\n");
for(i=1;i<=n;i++)
{
printf("%d ",i*j);
}
}
getch();
}
void value_n8()
{
int n;
printf("Enter a number:");
scanf("%d",&n);
if(n%2==0)
{
while(n>=1)
{
n=n/2;
printf("%d ",n);
}
}
else
{
while(n>=1)
{
n=(3*n)-1;
printf("%d ",n);
}
}
getch();
}
void marks_calculation9()
{
int a,b,c,d,e,n;
printf("enter a number ofattendence:");
scanf("%d",&a);
if((a>=35)&&(a<39))
  printf("mark is 30");
  if((a>=33)&&(a<35))
  printf("mark is 27");
  if((a>=31)&&(a<33))
  printf("mark is 24");
  if((a>=29)&&(a<31))
  printf("mark is 21");
  if((a>=27)&&(a<29))
  printf("mark is 18");
  if((a>=25)&&(a<27))
  printf("mark is 15");
  if((a>=23)&&(a<25))
  printf("mark is 12");
  if(a<23)
  printf("mark=0");
  getch();
  }
void sum_count_digit10()
{
int a,b,c,d,n;
printf("Enter a number:");
scanf("%d",&a);
n=0;
c=0;
while(a!=0)
{
b=a/10;
d=a%10;
c=d+c;
n++;
a=b;
}
printf("sum=%d",c);
printf("number of digit is %d",n++);
getch();
}
 main()
{
int variable;
/*printf("press a int type value to see output by following information");
scanf("%d",&variable);*/
printf("PLEASE PRESS 1 TO GET THE FACTORIAL VALUE\n\n\nPLEASE PRESS 2 TO SEE a SIMPLE SERIES \n\n\n  PLEASE PRESS 3 S TO CHEAK ARMSTRONG NUMber\n\n\n   PLEASE PRESS  4 TO CONVERT A DECIMAL NUMBER TO BINARY\n\n\n PLEASE PRESS 5 TO SEE FIBONACCI SERIES\n\n\n PLEASE PRESS 6 TO SEE SUM OF SQUARE DIGIT\n PLEASE PRESS 7 TO SEE a PYRAMID\n\n\n PLEASE PRESS 8 TO determine the value of n(when n is odd or even)\n\n\n PLEASE PRESS 9 TO calculate the marks of attendence\n\n\n PLEASE PRESS 10 TO sum the digit of a number & count the digit\n\n\n");
printf("\n\npress a int type value to see output by following information\n\n");
scanf("%d",&variable);
if(variable==1)
{
factorial1();
}
if(variable==2)
{
series2();
}
if(variable==3)
{
armstrongnum3();
}
if(variable==4)
{
deci_to_binary4();
}
if(variable==5)
{
fibonacci5();
}
if(variable==6)
{
 sum_of_square_series6();
 }
 if(variable==7)
 {
 pyramid7();
 }
if(variable==8)
{
value_n8();
}
if(variable==9)
{
marks_calculation9();
}
if(variable==10)
{
sum_count_digit10();
}
}

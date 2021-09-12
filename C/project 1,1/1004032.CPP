#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{

int n,i,a[20],s=0,fact,d,f,b,c,e,j;
float l,m,o,g,h,x;
printf("****CALCULATOR***\npress 1 for sum:\n prss 2 for multiplication:\n press 3 for substract:\n press 4 for divission ");
printf("\npress 5 for square:\n press 6 for root:\n press 7 for desimel to bainary:\n press 8 factorial \n press 9 for bainary to desimel\n press 10 for permutation\n press 11 for combination\npress 12 for Exit ");
samiul:
printf("\n\tEnter your choice\n\a\a");
scanf("%d",&n);
while(n>=1&&n<=12)
{
if(n==1)
{
printf("\nEnter how many number do you want to input(For sum)\n");
scanf("%d",&d);
for(i=0;i<d;i++)
{
scanf("%d",&a[i]);
s+=a[i];
}
printf("T0tal=%d\n",s);
goto samiul;
}
else if(n==2)
{
 printf("\nEnter how many number do you want to input\n");
scanf("%d",&d);
s=1;
for(i=0;i<d;i++)
{
scanf("%d",&a[i]);
s*=a[i];
}
printf("Result of multplication=%d\n",s);
goto samiul;
}
else if(n==3)
{
printf("\nEnter number for sub\n");
scanf("%d %d",&b,&c);
e=b-c;
printf("%d\n",e);
goto samiul;
}

else if(n==4)
{
printf("\nEnter two number for divission according to 1st 2nd\n");
scanf("%f %f",&o,&m);
 l= o/m;
printf("%.3f\n",l);
goto samiul;
}
else if(n==5)
{
printf("\nEnter number  for square \n");
scanf("%f",&h);
x=pow(h,2);
printf("%.3f\n",x);
goto samiul;
}
else if(n==6)
{
printf("\nEnter a number for root \n");
scanf("%f",&h);
x=sqrt(h);
printf("%.3f",x);
goto samiul;
}
else if(n==7)
{
int t=0,d=1,c=1,p,a[10];
printf("Enter a decimal number\n");
scanf("%d",&b);i=0;
//for(i=0;i<10;i++)
while(b!=0)
{
a[i]=b%2;
b=b/2;
i++;
t=t+1;
}
for(i=0,j=t-1;i<j;i++,j--)
{
p=a[i];
a[i]=a[j];
a[j]=p;
}
for(i=0;i<t-1;i++)
printf("%d",a[i]);
goto samiul;
}


else if(n==8)
{
printf("\nEnter a number for factorial\n");
 long long z,d,fact=1;
 scanf("%lld",&d);

 for(i=1;i<=d;i++)
 fact*=i;
 printf("%d\n",fact);
 goto samiul;
 }
 if(n==9)
 {
 printf("\nEnter bainary number\n");
 long a,b,c,d,e;
c=0; e=1;
scanf("%ld",&a);
while(a!=0)

{
b=a%10;
a=a/10;
c=c+b*e;
e=e*2;
//goto samiul;
}
printf("desimel number=%d\n",e);
goto samiul;
}
if(n==10)
{
printf("Enter numberof npr According to n r\n");
long long z,d,fact=1,s,r,fact1;
 scanf("%lld  %lld",&d,&z);
 s=d-z;
 for(i=1;i<=d;i++)
 fact*=i;
 z=fact;
  for(i=1, fact1=1;i<=s;i++)
 fact1*=i;
 r=z/fact1;

 printf("%lld\n",r);
 goto samiul;
 }
 if(n==11)
 {
  printf("Enter number of nCr According to n r  \n");
long long z,d,fact=1,s,r,fact1,fact2,p;
 scanf("%lld  %lld",&d,&z);
 s=d-z;
 for(i=1;i<=d;i++)
 fact*=i;
// z=fact;
  for(i=1, fact1=1;i<=s;i++)
 fact1*=i;
  for(i=1, fact2=1;i<=z;i++)
 fact2*=i;
r=fact1*fact2;
p=fact/r;
 printf("%lld\n",p);
 goto samiul;
 }
if (n==12)
printf("\t\tThanks for using calculator(Exit)\a");
break;
}
getch();
return 0;
}

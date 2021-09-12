#include<stdio.h>
#include<conio.h>
#include<math.h>
double sum(float ,float );
double sub(float ,float );
double multi(float ,float );
double divi(float ,float );
long long comb(long long ,long long );
long long perm(long long ,long long );
long long fact(long long );
long long decimal(long int ,long int );
long long binary(long int  );
float b[10],t,v;
int x,y,u;
int main()
{
clrscr();
int   a;
float c,d,e;
printf("\n\t\t\tCALCULATOR \n\tSelect from the following menu:\n\n\t1.Sum\t\t6.Permutation\t11.tanx\n\t2.Subtract\t7.Factorial\t12.decimal to binary\n\t3.Multiply\t8.square\t13.square root\n\t4.Divide\t9.sinx\t\t14.binary to decimal\n\t5.Combination\t10.cosx\t\t15.Exit\n");
while(scanf("%d",&a),a!=15)
{
switch(a)
{

case 1:
{   printf("Enter two number:");
scanf("%f%f",&d,&e);
 b[0]=sum(d,e);
 printf("Sum result=%.3f\n",b[0]);
 }
 break;
 case 2:
 {
 printf("Enter two number:");
 scanf("%f%f",&d,&e);
  b[1]=sub(d,e);
 printf("Subtract result=%.3f\n",b[1]);
 }
 break;
 case 3:
 {
 printf("Enter two number:");
 scanf("%f%f",&d,&e);
 b[2]=multi(d,e);
 printf("Multiply result=%.3f\n",b[2]);
 }
 break;
 case 4:
 {
 printf("Enter two number:");
 scanf("%f%f",&d,&e);
 b[3]=divi(d,e);
 printf("Divide result=%.3f\n",b[3]);
 }
 break;
 case 5:
 {
 long long n,r;
 printf("Enter two numbers:");
 scanf("%lld%lld",&n,&r);
 printf("%lldC%lld=%lld\n",n,r,comb(n,r));
 }
 break;
 case 6:
  {
 long long n,r;
 printf("Enter two numbers:");
 scanf("%lld%lld",&n,&r);
 printf("%lldP%lld=%lld\n",n,r,perm(n,r));
 }
 break;
 case 7:
 {
 long long n;
 printf("Enter one number:");
 scanf("%lld",&n);
 printf("%lld!=%lld\n",n,fact(n));
 }
 break;
 case 8:
 {
 long long b[4],t;
 printf("Enter a number:");
 scanf("%lld",&t);
 b[4]=t*t;
 printf("square result=%lld",b[4]);
 }
 break;
 case 9:
 {
 int  x,y;
 float v,t;
 printf("Enter a number: ");
 scanf("%d",&x);
 v=x*3.1416/180;
 t=sin(v);
 printf("sin%d=%.3f\n",x,t);

 }
 break ;
 case 10:
 {
 int x,y;
 float v,t;
 printf("Enter a number:");
 scanf("%d",&x);
 v=x*3.1416/180;
 t=cos(v);
 printf("cos%d=%.3f\n",x,t);
 }
 break ;
 case 11:
 {
 int x,y;
 float v,t;
 printf("Enter a number:");
 scanf("%d",&x);
 v=x*3.1416/180;
 t=tan(v);
 printf("tan%d=%.3f\n",x,t);
 }
 break;
 case 12:
 {
 long int u1;
 printf("Enter a decimal number:");
 scanf("%lld",&u1);
 printf("binary=%ld\n",binary(u1));
 }
 break;
 case 13:
 {
 double z,w;
 scanf("%lf",&w);
 z=sqrt(w);
 printf("%.3lf\n",z);
 }
 break;
 case 14:
 {
 long int u2,u3=2;
 printf("Enter a binary number:");
 scanf("%ld",&u2);
 printf("decimal=%ld",decimal(u2,u3));
 }
 break;
  }
   }
   return 0;
   }
 double sum(float x,float y)
 {
 float f;
 f=x+y;
 return(f);
 }
 double sub(float x,float y)
 {
 float g;
 g=x-y;
 return (g);
 }
 double multi(float x,float y)
 {
 float h;
 h=x*y;
 return (h);
 }
 double divi(float x,float y)
 {
 float i;
 i=x/y;
 return (i);
 }
 long long comb(long long k,long long l)
 {
 long long q;
 q=perm(k,l)/fact(l);
 return (q);
 }
 long long perm(long long k,long long l)
 {
 long long p;
 p=fact(k)/fact(k-l);
 return(p);
 }
 long long fact(long long k)
 {
 long long u,o;
 u=1;
 for(o=1;o<=k;o++)
 {
 u=u*o;
 }
 return(u);
 }
long long binary(long int l)
{
int c;
 int m=0,x=1,y=1;

while(l!=0)
{
c=l%2;
l=l/2;
x=1*y;
x=x*c;
y*=10;
m=m+x;
}
return m;
}
long long decimal(long int v,long int m)
{
int sum=0,j,k, i=0;
while(v!=0)
{
j=v%10;
k=j*pow(m,i);
i++;
sum=sum+k;
v=v/10;
}
return sum;
}

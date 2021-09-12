#include<stdio.h>
#include<conio.h>
int main()
{
 long int i,j,z,k,days,n,a;

 scanf("%ld",&i);
 a=i;
 j=1990;
 k=0;
 if((i<j)||(i>j) )
 {
  if(i>j)
  {z=i-j;}
  if(i<j)
  {z=j-i;}
  while(i>j)
  {
   if(((i%4)==0) || ((i%400)==0))
   {
    k=k+1;
   }
   i--;
  }
  while(i<j)
  {
   if(((i%4)==0) || ((i%400)==0))
   {
    k=k+1;
   }
   i++;
  }
  days =(z * 365) + k;
  n = ( days % 7 );
  }
 if(a>j)
  {
  if(((a%4)==0) || ((a%400)==0))
  {
   n=n-1;
  }
  }
 if(a<j)
 {
  if(((a%4)==0) || ((a%400)==0))
  {
   n=n+0;
  }
 }
 if(a>j)
 {
  if(n==0)
  {
   printf("THE FIRST DAY OF FIRST MONTH IS MONDAY");
  }
  if(n==1)
  {
   printf("THE FIRST DAY OF FIRST MONTH IS TUESDAY");
  }
  if(n==2)
  {
   printf("THE FIRST DAY OF FIRST MONTH IS WEDNESDAY");
  }
  if(n==3)
  {
   printf("THE FIRST DAY OF FIRST MONTH IS THURSDAY");
  }
  if(n==4)
  {
   printf("THE FIRST DAY OF FIRST MONTH IS FRIDAY");
  }
  if(n==5)
  {
   printf("THE FIRST DAY OF FIRST MONTH IS SATURDAY");
  }
  if(n==6)
  {
   printf("THE FIRST DAY OF FIRST MONTH IS SUNDAY");
  }
  if((n==7)|| (n==8)||(n==9))
    printf("YOU PUT INVALID YEAR");
 }
 if(a<j)
 {  if(n==0)
  {
   printf("THE FIRST DAY OF FIRST MONTH IS MONDAY");
  }
  if(n==1)
  {
   printf("THE FIRST DAY OF FIRST MONTH IS SUNDAY");
  }
  if(n==2)
  {
   printf("THE FIRST DAY OF FIRST MONTH IS SATURDAY");
  }
  if(n==3)
  {
   printf("THE FIRST DAY OF FIRST MONTH IS FRIDAY");
  }
  if(n==4)
  {
   printf("THE FIRST DAY OF FIRST MONTH IS THURSDAY");
  }
  if(n==5)
  {
   printf("THE FIRST DAY OF FIRST MONTH IS WEDNESDAY");
  }
  if(n==6)
  {
   printf("THE FIRST DAY OF FIRST MONTH IS TUESDAY");
  }
  if((n==7)|| (n==8)||(n==9))
    printf("YOU PUT INVALID YEAR");
 }


 getch();

}

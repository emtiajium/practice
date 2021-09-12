#include<stdio.h>
#include<conio.h>
main()

{
      int a,b,c=0;
      printf("enter a number" );
      scanf("%d",&a);
      while(b>0){
                 b=a%10;
                 c=c+b;
                 a=a/10;
                 }
                 printf("the sum of the numbers is:%d",c);
                 getch();
                 }

#include<stdio.h>
#include<conio.h>
main ()
{
     float a;
     printf("Enter the price per KG : ",a);
     scanf("%f",&a);
     float b;
     printf("\nEnter the weight in KG : ",b);
     scanf("%f",&b);
     float c;
     c=a*b;
     printf ("\nPrice for KG : %f",c);
     
     float d;
     
     printf("\nEnter The weight (gram)  : ",d);
     scanf("%f",&d);
     float e;
     e=d/1000;
     printf("\nconverting gram to kg : %f",e);
     float f;
     f=a*e;
     printf("\nPrice  number 2 %f",f);
     float g;
     g=c+f;
     printf("\nTotal price is %f",g);
     
     getch();
     return 0;
}

#include<stdio.h>
#include<conio.h>
#define PERIOD 10 
#define PRINCIPAL 5000.00
main ()
{
     int year;
     float amount,value,interest;
     amount=PRINCIPAL;interest=0.11;
     year=0;
     while (year<=PERIOD)
     {
		 printf("%2d %8.2f\n",year,amount);
     value=amount+interest*amount;
     year=year+1;
     amount=value;
     
	 }
     getch();
     return 0;
}     


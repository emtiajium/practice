#include<stdio.h>
#include<conio.h>
main()
{
      int a,b,c,d;
      printf("Enter a four digit number : ");
      scanf("%d",&a);
      b=a/1000;
      c=a%10;
      d=b+c;
      printf("\nThe sum of the first & last digit of this number:%d",d);
      getch();
      return 0;
}
      

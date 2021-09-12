#include<stdio.h>
#include<conio.h>
#include<math.h>
main (void)
{
     float a,b;
     read:
          scanf("%f",&a);
          if(a<0)goto read;
          b=sqrt(a);
          printf("%f %f\n",a,b);
          goto read;
     getch();
}

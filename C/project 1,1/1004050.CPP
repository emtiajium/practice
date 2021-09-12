#include<stdio.h>
#include<math.h>
int main()
{
   double a,b,c,x1,x2;
   int emtiaj;
   __int64 z,fct=1,i;
   printf("\n G'day, this is Emtiaj Hasan. I have made a simple calculator using C language.\n\n");
   printf("\t\tWhat would you like to do?\n");
   printf("\t\t1.Addition\n\t\t2.Subtraction \n\t\t3.Multiplication\n\t\t4.Division\n\t\t5.Factorial\n\t\t6.Square root\n\t\t7.Roots of Quadratic equation\n\t\t8.Nothing\n\n");
   printf("\t\tPress corresponding number.\n\n");
   while(emtiaj!=8)
   {
   scanf("%d",&emtiaj);
   switch(emtiaj)
   {
              case 1://sum
                   printf("Enter two number for doing Addition\n");
                   scanf("%lf %lf",&a,&b);
                   printf("Sum is %.3lf\n",a+b);
                   break;

              case 2://subtraction
                   printf("Enter two number for doing Subtraction\n");
                   scanf("%lf %lf",&a,&b);
                   printf("Subtraction is %.3lf\n",a-b);
                   break;

              case 3://multiplication
                   printf("Enter two number for doing Multiplication\n");
                   scanf("%lf %lf",&a,&b);
                   printf("Multiplication is %.3lf\n",a*b);
                   break;

              case 4://division
                   printf("Enter two number for doing Division\n");
                   scanf("%lf %lf",&a,&b);
                   if(b==0) printf("Undefined\n");
                   else
                   printf("quotient is %.3lf\n",a/b);
                   break;

              case 5://factorial
                   printf("Enter a number for doing factorial\n");
                   scanf("%I64d",&z);
                   if(z<0&&z%2==0) printf("Factorial of negetive even number is -infinity\n");
                   else if(z<0&&z%2!=0) printf("Factorial of negetive odd number is +infinity\n");
                   else
                   {
                   for(i=2;i<=z;i++){
                    fct*=i;}
                   printf("Factorial is %I64d\n",fct);
                   }
                   break;
              case 6://square root
                   printf("Enter a number for doing square root of a number\n");
                   scanf("%lf",&a);
                   if(a<0) printf("Square root of %.3lf is an imaginary number\n",a);
                   else printf("Square root of %.3lf is %.3lf\n",a,sqrt(a));
                   break;
              case 7://roots of equation
                   printf("Quadratic equation is ax^2+bx+c=0\n");
                   printf("Enter co-efficient of x^2, x & constant.\n");
                   scanf("%lf %lf %lf",&a,&b,&c);
                   if((b*b-4*a*c)<0) printf("Since Discriminant of this equation is negetive,the roots are imaginary.\n");
                   else
                   {
                   x1=(-b+sqrt(b*b-4*a*c))/(2*a);
                   x2=(-b-sqrt(b*b-4*a*c))/(2*a);
                   printf("%.3lf, %.3lf\n",x1,x2);
                   }
                   break;
              case 8://break
                      printf("Thank you");
                      break;
   }
   }
return 0;
}


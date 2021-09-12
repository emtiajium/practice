#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
int x;
printf("\t*****************Enter your option*****************\n");
printf("\t\tPress 1 for Calculator\n\t\tPress 2 for Quiz\n\t\tPress 0 to exit\n");
while(scanf("%d",&x)!=EOF)
{
if(x==0)
break;
if (x==1){
double a,b,c,x1,x2;
int jahir;
long int z,fct=1,i;
printf("\t*****************Enter your option*****************\n");
printf("\t\t\t1.Sum\n\t\t\t2.Subtraction \n\t\t\t3.Multiplication\n\t\t\t4.Division\n\t\t\t5.Factorial\n\t\t\t6.Square Root\n\t\t\t7.Square\t\n\t\t\t8.Go to main menu\t\t\n");
printf("\t\tPress corresponding number.\n\n");

scanf("%d",&jahir);
switch(jahir)
{
case 1://sum
printf("Enter two number for doing Sum\n");
scanf("%lf %lf",&a,&b);
printf("Sum is %.3lf\n",a+b);
printf("\t\tIf you go to calculator again press 1\n\t\tPress 2 for Quiz\n\t\tPress 0 to exit\n");
break;

case 2://subtraction
printf("Enter two number for doing Subtraction\n");
scanf("%lf %lf",&a,&b);
printf("Subtraction is %.3lf\n",a-b);
printf("\t\tIf you go to calculator again press 1\n\t\tPress 2 for Quiz\n\t\tPress 0 to exit\n");
break;

case 3://multiplication
printf("Enter two number for doing Multiplication\n");
scanf("%lf %lf",&a,&b);
printf("Multiplication is %.3lf\n",a*b);
printf("\t\tIf you go to calculator again press 1\n\t\tPress 2 for Quiz\n\t\tPress 0 to exit\n");
break;

case 4://division
printf("Enter two number for doing Division\n");
scanf("%lf %lf",&a,&b);
printf("Division is %.3lf\n",a/b);
printf("\t\tIf you go to calculator again press 1\n\t\tPress 2 for Quiz\n\t\tPress 0 to exit\n");
break;

case 5://factorial
printf("Enter a number for doing factorial\n");
scanf("%ld",&z);
for(i=1;i<=z;i++)
{
fct*=i;
}
if(z<0)
printf("Math Error\n");
else if(z>=0)
printf("Factorial is %ld\n",fct);
printf("\t\tIf you go to calculator again press 1\n\t\tPress 2 for Quiz\n\t\tPress 0 to exit\n");
break;

case 6://sqrt
printf("Enter a number for squar root\n");
scanf("%lf",&a);
if(a<0)
printf("Math Error\n");
else
printf("Square root of given number is %.3lf\n",sqrt(a));
printf("\t\tIf you go to calculator again press 1\n\t\tPress 2 for Quiz\n\t\tPress 0 to exit\n");
break;

case 7://
printf("Enter a number for squar\n");
scanf("%lf",&a);
printf("Square of given number is %.3lf\n",a*a);
printf("\t\tIf you go to calculator again press 1\n\t\tPress 2 for Quiz\n\t\tPress 0 to exit\n");
break;

case 8://break
printf("\t*****************Enter your option*****************\n");
printf("Press 1 for Calculator\nPress 2 for Quiz\nPress 0 to exit\n");
break;
}
}
/*Code of Quiz*/
if(x==2)
{
int a,b,c,w;
c=0;w=0;
printf("\t#####Press 1 to participate in quiz######\n\t#####press 9 to main menu#####\n");
scanf("%d",&b);
if(b==9)
{
printf("\t*****************Enter your option*****************\n");
printf("Press 1 for Calculator\nPress 2 for Quiz\nPress 0 to exit\n");
}
if(b==1){
printf("*****Press 1,2 or 3 for choose the write answer from the given questoin*****\n\n ");

printf("\t\tQ.1::What is called as ' THE ROOF OF THE WORLD '?\n1.Nepal\n2.Rome\n3.Tibet\n");
scanf("%d",&a);
if(a==3)
{
printf("Right.");
c++;
}
else
{
printf("Wrong.\nCorrect answer is Tibet.");
w++;
}

printf("\n\n\n\t\tQ.2::What is called as ' THE LAND OF RISING SUN '?\n1.Chicago\n2.Japan\n3.Tibet\n");
scanf("%d",&a);
if(a==2)
{
printf("Right.");
c++;
}
else
{
printf("Wrong.\nCorrect answer is Japan.");
w++;
}

printf("\n\n\n\t\tQ.3::What is called as ' THE THE LAND OF WHITE ELEPHANTS '?\n1.Bangladesh\n2.Thailand\n3.India\n");
scanf("%d",&a);
if(a==2)
{
printf("Right.");
c++;
}
else
{
printf("Wrong.\nCorrect answer is Thailand.");
w++;
}

printf("\n\n\n\t\tQ.4::What is the capital of ' BANGLADESH '?\n1.Dhaka\n2.Chittagong\n3.Rajshahi\n");
scanf("%d",&a);
if(a==1)
{
printf("Right.");
c++;
}
else
{
printf("Wrong.\nCorrect answer is Dhaka.");
w++;
}

printf("\n\n\n\t\tQ.5::What is called as ' THE WINDY CITY '?\n1.Jerusalem\n2.Japan\n3.Chicago\n");
scanf("%d",&a);
if(a==3)
{
printf("Right.");
c++;
}
else
{
printf("Wrong.\nCorrect answer is Chicago.");
w++;
}

printf("\n\n\n\t\tQ.6::What is called as ' THE LAND OF THUNDERBOLT '?\n1.Bhutan\n2.Canada\n3.Arab\n");
scanf("%d",&a);
if(a==1)
{
printf("Right.");
c++;
}
else
{
printf("Wrong.\nCorrect answer is Bhutan.");
w++;
}

printf("\n\n\n\t\tQ.7::What is called as ' THE DARK CONTIENENT '?\n1.Asia\n2.Australia\n3.Africa\n");
scanf("%d",&a);
if(a==3)
{
printf("Right.");
c++;
}
else
{
printf("Wrong.\nCorrect answer is Africa.");
w++;
}

printf("\n\n\n\t\tQ.8::What is called as ' THE LAND OF MIDNIGHT SUN '?\n1.Norway\n2.Japan\n3.Australia\n");
scanf("%d",&a);
if(a==1)
{
printf("Right.");
c++;
}
else
{
printf("Wrong.\nCorrect answer is Norway.");
w++;
}

printf("\n\n\n\t\tQ.9::What is called as ' THE HOLY LAND '?\n1.Jerusalem\n2.Mecca\n3.Mathura\n");
scanf("%d",&a);
if(a==1)
{
printf("Right.");
c++;
}
else
{
printf("Wrong.\nCorrect answer is Jerusalem.");
w++;
}

printf("\n\n\n\t\tQ.10::What is called as ' THE LAND OF MIDNIGHT SUN '?\n1.Norway\n2.Japan\n3.Australia\n");
scanf("%d",&a);
if(a==1)
{
printf("Right.");
c++;
}
else
{
printf("Wrong.\nCorrect answer is Norway.");
w++;
}
printf("\n\tTotal right answer is %d\n",c);
printf("\tTotal wrong answer is %d\n",w);
printf("\nPress 2 for quiz main menu\n");
}
}
}
getch();
return 0;
}

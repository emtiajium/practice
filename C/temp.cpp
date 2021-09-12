#include<stdio.h>
#include<conio.h>
int main()
{
    float t;
    int c;
    printf("Enter value\n");
    scanf("%f",&t);
    printf("1: Fahrenheit to Celsius,\n2: Celsius to Fahrenheit\n");
    printf("Enter choice\n");
    scanf("%d",&c);
    if(c==1) printf("%.3f",(5*(t-32))/9);
    if(c==2) printf("%.3f",((9*t)/5)+32);
    getch();
    return 0;
}
    

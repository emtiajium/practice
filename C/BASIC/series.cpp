//1/1!+2/2!+3/3!+4/4!.....+n/n!=?
#include<stdio.h>
//const double accuracy=0.001;
int factorial(int a)
{
    int f=1;
    for(int i=2;i<=a;i++)
        f=f*i;
return f;
}
int main()
{
    int x,i;
    double sum;
    while(scanf("%d",&x)==1){
        sum=1.0;
        for(i=2;i<=x;i++){
            sum+=(double)i/(double)factorial(i);
        }
    printf("Sum is %0.4lf\n",sum);
    }
return 0;
}

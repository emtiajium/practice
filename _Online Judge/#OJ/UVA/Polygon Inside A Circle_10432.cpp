#include<stdio.h>
#include<math.h>
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
double r,n,x,a;
int main()
{
    while(scanf("%lf %lf",&r,&n)==2)
    {
        x=PI*2;// PI*360/180
        a=0.5*n*r*r*sin(x/n);
        printf("%.3lf\n",a);
    }
    return 0;
}

#include<stdio.h>
#include<math.h>
int main()
{
    int k,cs=1;
    register double a,b,c,x,y;
    while(scanf("%d",&k)&&k)
    {
        scanf("%lf %lf %lf",&a,&b,&c);
        switch(k)
        {
            case 1:
                y=(b-a)/c;
                x=a*c+0.5*c*c*y;
                break;
            case 2:
                y=(b-a)/c;
                x=a*y+0.5*c*y*y;
                break;
            case 3:
                x=sqrt(a*a+2*b*c);
                y=(x-a)/b;
                break;
            case 4:
                x=sqrt(a*a-2*b*c);
                y=(a-x)/b;
                break;
        }
        printf("Case %d: %0.3lf %0.3lf\n",cs++,x,y);
    }
    return 0;
}

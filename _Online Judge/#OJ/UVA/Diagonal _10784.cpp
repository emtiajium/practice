// xC2-x=n
//The number of diagonals in a polygon with N sides = [N*(N-3)] / 2
#include<stdio.h>
#include<math.h>
int t;
long long dio,edg,a,b,c;
double dis,r,x1,x2,z;
int main()
{
    t=1;
    while(scanf("%lld",&dio)&&dio!=0){
        a=1;
        b=-3;
        c=(-1)*(2*dio);
        dis=b*b-4*a*c;
        r=sqrt(dis);
        x1=(-b+r)/(2*a);
        x2=(-b-r)/(2*a);
        if((int)x1>0) z=x1;
        else if((int)x2>0) z=x2;
        z=ceil(z);
        edg=z;
        printf("Case %d: %lld\n",t,edg);
        t++;
    }
    return 0;
}

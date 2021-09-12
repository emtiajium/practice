///http://www.codeforces.com/contest/106/problem/E

#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>

using namespace std;

double x[100],y[100],z[100];

double cal(double x,double y,double z){
    return x*x+y*y+z*z;
}

void HullClimbing(int n)
{
    int i,j,t;
    double x0,y0,z0,p,dis,mx;

    p=1;
    x0=y0=z0=0;

    for(i=0;i<20000;i++)
    {
        mx=-1;
        t=0;

        for(j=0;j<n;j++)
        {
            dis=cal(x0-x[j],y0-y[j],z0-z[j]);
            if(dis>mx)  mx=dis,t=j;
        }
        x0+=p*(x[t]-x0);
        y0+=p*(y[t]-y0);
        z0+=p*(z[t]-z0);
        p*=0.999;
    }

    printf("%.10lf %.10lf %.10lf\n",x0,y0,z0);

}


int main()
{
    int n,i,j,t;

    scanf("%d",&n);

    for(i=0;i<n;i++)    scanf("%lf%lf%lf",x+i,y+i,z+i);
    HullClimbing(n);

    return 0;
}

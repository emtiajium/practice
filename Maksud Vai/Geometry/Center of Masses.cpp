#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<utility>
#include<functional>
#include <deque>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <assert.h>


#include<cmath>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

double  sqr(double a){    return a*a;}
typedef struct {double x,y;}P;

P p[101],pvt;

double cross(P a,P b,P c,P d) {
    return  (b.x-a.x)*(d.y-c.y) - (b.y-a.y)*(d.x-c.x)  ;
}

bool com(P a,P b)
{
    double c = cross(pvt,a,pvt,b);

    if(fabs(c)>1e-5)
    {
       if(c>0) return true;
       else return false;
    }
    else if(sqrt(sqr(pvt.x-a.x)+sqr(pvt.y-a.y)) < sqrt(sqr(pvt.x-b.x) +sqr(pvt.y-b.y)))
    return true;
    return false;
}

int convex(int n)
{
    int i,j;

    j=0;
    pvt=p[0];
    for(i=1;i<n;i++)    if(pvt.y>p[i].y)    {pvt=p[i]; j=i; }
    else if(fabs(pvt.y-p[i].y )<0.0001&& pvt.x>p[i].x)  {pvt=p[i]; j=i; }
    p[j]=p[0];
    p[0]=pvt;
    sort(&p[1],&p[n],com);
    j=1;

    for(i=2;i<n;i++)
    {
        while(cross(p[j-1],p[j],p[j-1],p[i]) < 0 && j > 0) j--;
        p[++j] = p[i];
    }

    return j+1;
}



pair<double,double> CentreOfMess(P p[],int n)
{
    int i;
    double X,Y,area;

    ///n = convexHull(p,n); //Calculate ConvexHull;

    X = Y = 0;
    p[n].x=p[0].x;
    p[n].y=p[0].y;


    area=0;
    for(i=0;i<n;i++)
        area+=(p[i].x*p[i+1].y -p[i+1].x*p[i].y );
    area = fabs(area);
    area*=3;
    for(i=0;i<n;i++){
        X+=(p[i].x+p[i+1].x) * (p[i].x*p[i+1].y -p[i+1].x*p[i].y ) ;
        Y+=(p[i].y+p[i+1].y) * (p[i].x*p[i+1].y -p[i+1].x*p[i].y ) ;
    }

    X /=area;     Y/=area;

    return make_pair(X,Y);
}



int main()
{
    double area,X,Y;
    int n,i;
    pair<double,double> ret;

    while(scanf("%d",&n)==1 && n>2)
    {
        for(i=0;i<n;i++)    scanf("%lf%lf",&p[i].x,&p[i].y);
        X = Y = 0;
        n = convex(n);
        if(n>2)
        {

            ret = CentreOfMess(p,n);
            X = ret.first;
            Y = ret.second;
        }
        else
        {
            X= p[0].x+p[1].x;
            Y= p[0].y+p[1].y;
            X/=2.0;Y/=2.0;
        }

        if(fabs(X)<0.000001)  X=0.000;        if(fabs(Y)<0.000001)  Y=0.000;
        printf("%.3lf %.3lf\n",X+1e-15,Y+1e-15);
    }

    return 0;
}


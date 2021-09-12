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

#define oo          (1<<30)
#define ERR         1e-5
#define PRE         1e-8

#define SZ(a)       ((int)a.size())
#define X           first
#define Y           second
#define PB          push_back
#define LL          double
#define MP          make_pair



const double eps = 1e-9;
template<class TT>TT sqr(TT a){return a*a;}
template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
template<class ZZ>ZZ max(ZZ a,ZZ b,ZZ c){return max(a,max(b,c));}
template<class ZZ>ZZ min(ZZ a,ZZ b,ZZ c){return min(a,min(b,c));}


struct P{
    LL x,y;
    P(LL xx=0,LL yy=0){x=xx,y=yy;}

    void Rotate()
    {
        LL xi=x,yi=y;
        y = xi;
        x = -yi;
    }
};


P MV(P a,P b){return P(b.x-a.x,b.y-a.y);}
LL CP(P a,P b){return a.x*b.y-a.y*b.x;}
LL DP(P a,P b){return a.x*b.x+a.y*b.y;}
double ABS(P a){return sqrt(DP(a,a));}
const int S = 100101;

P pvt,p[S];

bool operator<(const P &a,const P &b){
    LL c = CP(MV(pvt,a),MV(pvt,b));
    if(fabs(c)>eps)   return c>0;
    return DP(MV(pvt,a),MV(pvt,a))<DP(MV(pvt,b),MV(pvt,b));
}

P operator - (const P &a,const P &b){return P(b.x-a.x,b.y-a.y);}


int Convexhull(P a[],int n)
{
    int i,j;
    pvt=a[0];
    for(i=1;i<n;i++)
        if((pvt.y>a[i].y) || (pvt.y==a[i].y&&pvt.x>a[i].x)) pvt=a[i];

    sort(a,a+n);

    j=1;
    for(i=2;i<n;i++)
    {
        while(j && CP(MV(a[j-1],a[j]),MV(a[j-1],a[i]))<=0) j--;
        a[++j]=a[i];
    }
    return j+1;
}



pair<double,double>Rotating_Cleaper(P po[],int n)
{
    double h,w,a,b,area=1e15,per=1e15;
    P tmp;
    int i,j,k,l,ii;

    for(i=j=k=l=0;i<n;i++)
    {
        ii = (i+1)%n;
        tmp = MV(po[i],po[ii]);///L
        for(;DP(tmp,po[j]-po[(j+1)%n])>0;j = (j+1)%n);

        if((j-i+n)%n>(k-i+n)%n) k=j;
        tmp.Rotate();///U
        for(;DP(tmp,po[k]-po[(k+1)%n])>0;k = (k+1)%n);

        if((k-i+n)%n>(l-i+n)%n) l=k;
        tmp.Rotate();///R
        for(;DP(tmp,po[l]-po[(l+1)%n])>0;l = (l+1)%n);

        tmp.Rotate();
        /**
        i = Low Point.
        j = Left Point.
        k = Top Point.
        l = Right Point.
        */

        h = fabs(DP(tmp,po[k]-po[i])/ABS(tmp));
        tmp.Rotate();
        w = fabs(DP(tmp,po[j]-po[l])/ABS(tmp));
        area = min(area,h*w);
        per = min(per,h+w);
    }

    return MP(area,2*per);
}


int main()
{
    int i,j,k,l,tks,ks=1,n,m;
    pair<double ,double>re;

    while(scanf("%d",&n)==1&&n)
    {
        for(i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        n = Convexhull(p,n);
        re = Rotating_Cleaper(p,n);
        printf("%.2lf %.2lf\n",re.X,re.Y);
    }

    return 0;
}




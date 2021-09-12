#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>

using namespace std;

#define oo          (1<<28)
#define ERR         1e-5
#define PI          3.141592653589793
#define pi          2*acos(0)
#define PB          push_back
#define INS         insert
#define ISS         istringstream
#define OSS         ostringstream
#define LL          long long
#define LD          long double
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<LL>
#define IR          iterator
#define SZ          size()
#define fi(i,a,b)   for(i=a;i<b;i++)
#define fd(i,a,b)   for(i=a;i>b;i--)
#define fii(a,b)   for(i=a;i<b;i++)
#define fdi(a,b)   for(i=a;i>b;i--)
#define fij(a,b)   for(j=a;j<b;j++)
#define fdj(a,b)   for(j=a;j>b;j--)
#define fik(a,b)   for(k=a;k<b;k++)
#define fdk(a,b)   for(k=a;k>b;k--)
#define fil(a,b)   for(l=a;l<b;l++)
#define fdl(a,b)   for(l=a;l>b;l--)
#define ri(i,a)    for(i=0;i<a;i++)
#define rd(i,a)    for(i=a;i>-1;i--)
#define rii(a)     for(i=0;i<a;i++)
#define rdi(a)     for(i=a;i>-1;i--)
#define rij(a)     for(j=0;j<a;j++)
#define rdj(a)     for(j=a;j>-1;j--)
#define rik(a)     for(k=0;k<a;k++)
#define rdk(a)     for(k=a;k>-1;k--)
#define ril(a)     for(l=0;l<a;l++)
#define rdl(a)     for(l=a;i>-1;l--)
#define sqr(a)     ((a)*(a))
#define EQ(a,b)    (fabs((a)-(b))<ERR)
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))

typedef struct{double x,y;}P;
P p[100000],mp,fp;
double mi;

P MV(P a,P b)
{
    P r;
    r.x = b.x-a.x;
    r.y = b.y-a.y;
    return r;
}

double ABS(P a) {return sqrt(sqr(a.x)+sqr(a.y));}

double D(P a, P b)
{
    return a.x*b.x+ a.y*b.y;
}

double DOT(int a,int b){
    return (mp.x-p[a].x)*(p[b].x-p[a].x) + (mp.y-p[a].y)*(p[b].y-p[a].y);
}

void COM(int i)
{
    double do1,do2,a,b,c,a1,a2,b1,b2,c2,c1,d,d1,d2,l;

    l=sqrt(sqr(p[i].x-p[i+1].x)+sqr(p[i].y-p[i+1].y));
    do1 = DOT(i,i+1);
    do2 = DOT(i+1,i);
    if((do1>0 || EQ(0,do1)) && (do2>0 || EQ(0,do2)))
    {
        P t;
        a1 = p[i].y-p[i+1].y;
        b1 = p[i+1].x-p[i].x;
        c1 = p[i].x*p[i+1].y - p[i].y*p[i+1].x;
        a2 = b1;
        b2 = -a1;
        c2 = -(a2*mp.x+b2*mp.y);
        t.x = (b1*c2-b2*c1)/(a1*b2 - a2*b1);
        t.y = (c1*a2-c2*a1)/(a1*b2 - a2*b1);
        d = sqrt(sqr(t.x-mp.x)+sqr(t.y-mp.y));
        if(d<mi)
        {
            mi = d;
            fp=t;

        }
    }
    else if(do1<0 )
    {
        d = sqrt(sqr(p[i].x-mp.x)+sqr(p[i].y-mp.y));
        if(d<mi)
        {
            mi = d;
            fp=p[i];

        }
    }
    else
    {
        d = sqrt(sqr(p[i+1].x-mp.x)+sqr(p[i+1].y-mp.y));
        if(d<mi)
        {
            mi = d;
            fp=p[i+1];
        }
    }
}

int main()
{
    int i,n;

    while(scanf("%lf%lf%d",&mp.x,&mp.y,&n)==3)
    {
        rii(n+1)  scanf("%lf%lf",&p[i].x,&p[i].y);
        mi = 99999999999.0;
        rii(n)  COM(i);
        printf("%.4lf\n%.4lf\n",fp.x,fp.y);
    }
    return 0;
}


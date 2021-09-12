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

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

using namespace std;

#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          2*acos(0)
#define ERR         1e-10
#define PRE         1e-8
#define SZ          size()
#define PB          push_back
#define LL          long long
#define ISS         istringstream
#define OSS         ostringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define SII         set<int>::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define fi(i,a,b)   for(i=a;i<b;i++)
#define fd(i,a,b)   for(i=a;i>b;i--)
#define fii(a,b)    for(i=a;i<b;i++)
#define fdi(a,b)    for(i=a;i>b;i--)
#define fij(a,b)    for(j=a;j<b;j++)
#define fdj(a,b)    for(j=a;j>b;j--)
#define fik(a,b)    for(k=a;k<b;k++)
#define fdk(a,b)    for(k=a;k>b;k--)
#define fil(a,b)    for(l=a;l<b;l++)
#define fdl(a,b)    for(l=a;l>b;l--)
#define ri(i,a)     for(i=0;i<a;i++)
#define rd(i,a)     for(i=a;i>-1;i--)
#define rii(a)      for(i=0;i<a;i++)
#define rdi(a)      for(i=a;i>-1;i--)
#define rij(a)      for(j=0;j<a;j++)
#define rdj(a)      for(j=a;j>-1;j--)
#define rik(a)      for(k=0;k<a;k++)
#define rdk(a)      for(k=a;k>-1;k--)
#define ril(a)      for(l=0;l<a;l++)
#define rdl(a)      for(l=a;i>-1;l--)
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define pair<int,int>   PII
#define pair<int,PII>   PIP


typedef struct {double x,y,z;}P,V;
P p[102],cp[15000],pvt;
int sa[102],sb[102];

V MV(P a,P b){V r;r.x=b.x-a.x;r.y=b.y-a.y;r.z=b.z-a.z;return r;}
double Abs(V a){return sqrt(sqr(a.x)+sqr(a.y)+sqr(a.z));}

bool com(P a,P b)
{
    double c = CROSS(pvt,b,pvt,a);

    if(EQ(c,0.))
    {
        if( sqrt(sqr(pvt.x-a.x)+sqr(pvt.y-a.y)) > sqrt(sqr(pvt.x-b.x)+sqr(pvt.y-b.y) ))
            return false;
        else return true;
    }
    else if(c>0.)    return false;
    return true;
}

int ConvexHull(int n)
{
    int i,k;
    double c;
    P tmp;

    pvt=cp[0];
    k=0;

    fii(1,n)
        if(cp[i].y<pvt.y)
        {
            pvt=cp[i];
            k=i;
        }
        else if( EQ(cp[i].y,pvt.y) && cp[i].x<pvt.x )
        {
            pvt = cp[i] ;
            k=i;
        }
        tmp = cp[0];
        cp[0] = cp[k];
        cp[k] = tmp;

        sort(cp,cp+n,com);

        k=1;

        fii(2,n)
        {
            c  = CROSS(cp[k-1],cp[k],cp[k-1],cp[i]);
            while(k>1 && (c < 0. || EQ(0.,c)))
            {
                k--;
                c  = CROSS(cp[k-1],cp[k],cp[k-1],cp[i]);
            }
            cp[++k] = cp[i];
        }
        k++;
    return k;
}


P FindCP(int z,int ia,int ib)
{
    P r;
    double ratio,dz;
    dz = fabs(p[ia].z - z);

    r = MV(p[ia],p[ib]);

    ratio = dz/r.z;

    r.x *= ratio;
    r.y *= ratio;
    r.z *= ratio;

    r.x += p[ia].x;
    r.y += p[ia].y;
    r.z += p[ia].z;

    return r;
}


double Area(int n)
{
    if(n<3) return 0.0;
    n = ConvexHull(n);
    if(n<3) return 0.0;

    double area=0.;
    int i;
    cp[n] = cp[0];
    rii(n)  area += cp[i].x*cp[i+1].y - cp[i].y*cp[i+1].x;

    return fabs(area/2.);
}

int main()
{
    //freopen("in.in","r",stdin);
    int n,m,i,j,k,zmx,zmn,nsa,nsb,ncp;

    while(scanf("%d%d%d",&n,&zmn,&zmx)==3)
    {
        rii(n)  scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
        zmx++;

        fii(zmn,zmx)
        {
            nsa=nsb=ncp=0;
            rij(n)
                if( EQ(p[j].z,i) )
                    cp[ncp++] = p[j];
                else if(p[j].z<i)
                    sa[nsa++] = j ;
                else sb[nsb++] = j ;


            rij(nsa)rik(nsb)    cp[ncp++] = FindCP(i,sa[j],sb[k]);
            printf("%.5lf\n",Area(ncp));
        }

    }
    return 0;
}



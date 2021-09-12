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

#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          2*acos(0)
#define ERR         1e-5
#define SZ          size()
#define PB          push_back
#define LL          long long
#define ISS         istringstream
#define OSS         ostringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
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
#define PP(a)       (cout<<a<<endl)
#define APPRO(a,b)  ( (fabs(a-b)<ERR)?true:false )

typedef struct {double x,y,z;}P;
inline double  sqr(double a){return a*a;}
inline double CROSS(P a ,P b){return ((a.x*b.y)-(a.y*b.x)) + ((a.y*b.z)-(a.z*b.y)) - ((a.x*b.z)-(a.z*b.x));}
inline double DOT(P a,P b){return  ((a.x*b.x) + (a.y*b.y) + (a.z*b.z)); }
inline double ABS(P a){  return sqrt(sqr(a.x)+sqr(a.y)+sqr(a.z));}
inline P CAB(P a ,P b){P r;    r.x=a.y*b.z-a.z*b.y;  r.y = a.z*b.x-a.x*b.z;    r.z=a.x*b.y - a.y*b.x;  return r;}


int main()
{
    double dis,po,h,r,cur,l,cro,base,ta,tb,c,aa,bb,A,B,C,pro;
    P a,b,p,ac,bc,ab,ba;
    bool chk;
    int n;
    char cty[10];


    while(scanf("%s",cty)==1)
    {
        printf("%s\n",cty);
        scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&a.z,&b.x,&b.y,&b.z);
        ab.x = b.x-a.x; ab.y = b.y-a.y; ab.z = b.z-a.z;
        ba.x = -ab.x; ba.y = -ab.y; ba.z = -ab.z;
        dis = ABS(ab);
        chk=true;
        if(APPRO(dis,0.0))  chk=false;
        po=0;
        scanf("%d",&n);

        while(n--)
        {
            scanf("%lf%lf%lf%lf",&p.x,&p.y,&p.z,&r);
            if(!chk)    continue;
            ac.x = p.x-a.x; ac.y = p.y-a.y; ac.z = p.z-a.z;
            bc.x = p.x-b.x; bc.y = p.y-b.y; bc.z = p.z-b.z;
            l = ABS(CAB(ac,ab)) / ABS(ab);

            if(l<r )
            {
                c=0.00;
                base = sqrt(sqr(r)-sqr(l));
                pro = fabs(DOT(bc,ba)/dis)+fabs(DOT(ac,ab)/dis);
                if( ABS(ac) < r && ABS(bc) < r )    c=ABS(ab);
                else if( ABS(ac) < r )  c = base + dis - (DOT(bc,ba)/dis);
                else if( ABS(bc)<r )    c = base + dis - (DOT(ac,ab)/dis);
                else if(APPRO(dis,pro))  c = 2*base;
                po+=c;
            }
        }
        if(chk)     printf("%.2lf\n",(po*100.00/dis)+1e-7);
        else printf("0.00\n");
    }
    return 0;
}

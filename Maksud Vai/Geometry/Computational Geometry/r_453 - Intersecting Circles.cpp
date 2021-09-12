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


#include<cmath>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

#define deb(a)      cout<<" -> "<<#a<<"  "<<a<<endl;
#define oo          (1<<30)
#define ERR         1e-5
#define PRE         1e-8
#define popcount(a) (__builtin_popcount(a))
#define SZ(a)       ((int)a.size())
#define X           first
#define Y           second
#define PB          push_back
#define LL          long long
#define MP          make_pair
#define ISS         istringstream
#define OSS         ostringstream
#define SS          stringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define IT          ::iterator
#define SI          set<int>
#define CON(a,b)  ((a).find(b)!=(a).end())
#define mem(a,b)    memset(a,b,sizeof(a))
#define memc(a,b)   memcpy(a,b,sizeof(b))
#define accu(a,b,c) accumulate((a),(b),(c))
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
#define fore(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define EQ(a,b)     (fabs((a)-(b))<ERR)
#define all(a)      (a).begin(),(a).end()
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define p2(a)       (1LL<<a)
#define EX(msk,a)   (msk&p2(a))
#define INC(a,b,c)   (b<=a&&a<=c)

const double pi=2*acos(0.);
//const double pi=acos(-1.0);

template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
template<class ZZ>ZZ max(ZZ a,ZZ b,ZZ c){return max(a,max(b,c));}
template<class ZZ>ZZ min(ZZ a,ZZ b,ZZ c){return min(a,min(b,c));}

//typedef pair< , > pi;
typedef struct {double x,y,r;
    void print(){printf("%lf %lf %lf\n",x,y,r);}
    int scan(){return scanf("%lf%lf%lf",&x,&y,&r);}
    void round(){
        if(fabs(x)<1e-4)  x=0;
        if(fabs(y)<1e-4)  y=0;
    }
}P;

//bool operator < (const P &a,const P &b){return a>b;}
//bool com(P a,P b){return;}
//struct pq{int n,w;  bool operator<(const pq &b)const{return w>b.w;}};

P MV(P a,P b){return (P){b.x-a.x,b.y-a.y,0};}
double ABS(P a){return sqrt(sqr(a.x)+sqr(a.y));}

P FindIntersectionPoint(P a,double t)
{
    a.x+=a.r*cos(t);
    a.y+=a.r*sin(t);
    return a;
}

P f[2];
bool com(P a,P b)
{
    if(!EQ(a.x,b.x)) return a.x<b.x;
    return a.y<b.y;
}


int main()
{
    //freopen("in1.in","r",stdin);
    //freopen("ou.out","w",stdout);
    //ios_base::sync_with_stdio(false);

    P a,b,c,v;
    double d,t,T;

    while(a.scan()+b.scan()==6)
    {
        if(b.r>a.r) swap(a,b);
        d = sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));

        /// IF CENTERS ARE SAME.
        if(EQ(d,0))
        {
            if(EQ(a.r+b.r,0))   printf("(%.3lf,%.3lf)\n",a.x,a.y);
            else if(EQ(a.r,b.r)) printf("THE CIRCLES ARE THE SAME\n");
            else //printf("(%.3lf,%.3lf)\n",a.x,a.y);
            printf("NO INTERSECTION\n");
            continue;
        }

        /// IF DON'T INTERSECT.
        if(d>a.r+b.r && !EQ(d,a.r+b.r)){
            printf("NO INTERSECTION\n");
            continue;
        }

        ///IF CIRCLE B IS IN A.
        if(d+b.r<a.r && !EQ(d+b.r,a.r)){
            printf("NO INTERSECTION\n");
            continue;
        }

        /// IF ONE INTERSECTION POINT.
        if(EQ(d,a.r+b.r))
        {
            c.x = (a.x*b.r+b.x*a.r)/(a.r+b.r);
            c.y = (a.y*b.r+b.y*a.r)/(a.r+b.r);
            c.round();
            printf("(%.3lf,%.3lf)\n",c.x,c.y);
            continue;
        }
        else if(EQ(a.r,d+b.r))
        {
            c.x = (b.x*a.r-a.x*b.r)/(a.r-b.r);
            c.y = (b.y*a.r-a.y*b.r)/(a.r-b.r);
            c.round();
            printf("(%.3lf,%.3lf)\n",c.x,c.y);
            continue;
        }

        ///IF TWO INTERSECTION POINTS.
        v = MV(a,b);

        T = atan2(v.y,v.x);
        t = acos((sqr(a.r)+sqr(d)-sqr(b.r))/(2*a.r*d));
        f[0]=FindIntersectionPoint(a,T+t);
        f[1]=FindIntersectionPoint(a,T-t);
        sort(f,f+2,com);

        f[0].round();
        f[1].round();

        printf("(%.3lf,%.3lf)",f[0].x,f[0].y);
        printf("(%.3lf,%.3lf)\n",f[1].x,f[1].y);
    }
    return 0;
}



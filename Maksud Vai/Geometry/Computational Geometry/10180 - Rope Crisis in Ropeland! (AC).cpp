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
#define deb1(a)      cout<<" -> "<<#a<<"  "<<a.x<<" "<<a.y<<endl;
#define oo          100
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

#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a)      (a).begin(),(a).end()
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define p2(a)       (1LL<<a)
#define INC(a,b,c)   (b<=a&&a<=c)

//const double pi=2*acos(0.);

template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
template<class ZZ>ZZ max(ZZ a,ZZ b,ZZ c){return max(a,max(b,c));}
template<class ZZ>ZZ min(ZZ a,ZZ b,ZZ c){return min(a,min(b,c));}

//typedef pair< , > pi;
//typedef struct {int x,y;    void print(){printf("%d %d\n",x,y);}}P;
//bool operator < (const P &a,const P &b){    return (a.x!=b.x?a.x<b.x:a.y<b.y);}
//bool com(P a,P b){return(a.x!=b.x?a.x<b.x:a.y<b.y);}
//struct pq{int n,w;  bool operator<(const pq &b)const{return w>b.w;}};


struct P
{
    long double x,y;
    P(long double xx=0,long double yy=0):x(xx),y(yy){};
    void scan(){
        //scanf("%lf%lf",&x,&y);
        cin>>x>>y;
    }
};

P MV(P a,P b){return P(b.x-a.x,b.y-a.y);}
long double DP(P a,P b){return a.x*b.x+a.y*b.y;}
long double CP(P a,P b){return a.x*b.y-a.y*b.x;}
long double ABS(P a){return sqrt(DP(a,a));}
long double dis(P a,P b){return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));}
long double eps=1e-7;
int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.in","w",stdout);
    //ios_base::sync_with_stdio(false);

    int tks;
    long double r,ans,oa,ob,vd,ab;
    P o,a,b;

    scanf("%d",&tks);
    while(tks--)
    {
        a.scan();
        b.scan();
        cin>>r;
        ab = dis(a,b);

        if(dis(a,b)<1e-8)  printf("%.3lf\n",(double)dis(a,b));
        else
        {
            vd=abs(CP(MV(a,b),MV(a,o))/ABS(MV(a,b)));
            if(vd<r)
            {
                if(DP(MV(a,b),MV(a,o)) * DP(MV(b,a),MV(b,o))<0)
                    printf("%.3lf\n",(double)dis(a,b));
                else
                {
                    oa=ABS(a);
                    ob=ABS(b);

                    ans=sqrt(sqr(oa)-sqr(r))+sqrt(sqr(ob)-sqr(r));
                    ans+=r*(acos((sqr(oa)+sqr(ob)-sqr(ab))/(2*oa*ob))-acos(r/oa)-acos(r/ob));
                    printf("%.3lf\n",(double)ans);
                }
            }
            else printf("%.3lf\n",(double)dis(a,b));
        }
    }
    return 0;
}



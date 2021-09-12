///http://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=&problem=1186&mosmsg=Submission+received+with+ID+10987670

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
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a)      (a).begin(),(a).end()
#define rall(a)      (a).rbegin(),(a).rend()
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
//#define sqr(a)      ((a)*(a))
#define p2(a)       (1LL<<a)
#define EX(msk,a)   (msk&p2(a))
#define INC(a,b,c)   (b<=a&&a<=c)

//const double pi=2*acos(0.);
//const double pi=acos(-1.0);
template<class TT>TT sqr(TT a){return a*a;}
//LL sqr(LL a){return a*a;}

template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
template<class ZZ>ZZ max(ZZ a,ZZ b,ZZ c){return max(a,max(b,c));}
template<class ZZ>ZZ min(ZZ a,ZZ b,ZZ c){return min(a,min(b,c));}


typedef pair<int,int> pii;

struct P{
    double x,y,z;
    P(double xt=0,double yt=0,int zt=0){x=xt,y=yt,z=zt;}
};

struct Comparator
{
    bool operator ()(const P &a,const P &b) const
    {
        if(a.y!=b.y)  return a.y<b.y;
        return a.x<b.x;
    }
};

const int S = 100000;
P p[S];

bool com(P a,P b){return(a.x!=b.x)?(a.x<b.x):(a.y<b.y);}
double SD(P a,P b){return sqr(a.x-b.x)+sqr(a.y-b.y);}


pii ClosestPair(P p[],int n)
{
    /// Return the index numbers of closest points.
    int left,right,ci,cj,i;
    double  dis,m;
    set<P,Comparator>st;
    P tmp;
    __typeof(st.begin())    itl,ith;

    sort(p,p+n,com);
    for(i=0;i<n;i++)    p[i].z = i;

    ci=p[0].z;
    cj=p[1].z;
    m = SD(p[0],p[1]);
    st.insert(p[0]);
    st.insert(p[1]);
    left=0;right=2;

    while(right<n)
    {
        while(left<right && sqr(p[left].x-p[right].x)>=m)
        {
            st.erase(p[left]);
            left++;
        }

        dis=sqrt(m)+ERR;

        itl = st.lower_bound(P(p[right].x,p[right].y-dis));
        ith = st.upper_bound(P(p[right].x,p[right].y+dis));

        while(itl!=ith)
        {
            dis = SD(*itl,p[right]);

            if(dis<m)
            {
                m=dis;
                ci=itl->z;
                cj = p[right].z;
            }
            itl++;
        }

        st.insert(p[right]);
        right++;
    }

    return pii(ci,cj);
}


int main()
{
    int i,j,k,l,tks,ks=1,n;
    pii pi;
    double D;

    while(scanf("%d",&n)==1 && n)
    {
        rii(n)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        if(n==1)
        {
            puts("INFINITY");
            continue;
        }

        pi = ClosestPair(p,n);
        D = sqrt(SD(p[pi.first],p[pi.second]));
        if(D<10000+ERR)   printf("%.4lf\n",D);
        else puts("INFINITY");
    }
    return 0;
}

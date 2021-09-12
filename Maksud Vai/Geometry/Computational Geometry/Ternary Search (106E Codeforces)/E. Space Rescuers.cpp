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
#define ERR         1e-4
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
typedef struct{long double x,y,z;}P;
//bool operator < (const P &a,const P &b){return a>b;}
//bool com(P a,P b){return;}
//struct pq{int n,w;  bool operator<(const pq &b)const{return w>b.w;}};


P p[100],Max,Min,f;
int n;


long double F(long double x,long double y,long double z)
{
    int i;
    long double mx=0;
    rii(n)
        mx=max(mx,sqr(p[i].x-x)+sqr(p[i].y-y)+sqr(p[i].z-z));

    return mx;

}

long double FZ(long double x,long double y)
{
    long double lx=Min.z,rx=Max.z,lp,rp,a,b;
    int i;

    rii(50)
    {
        lp=(2*lx+rx)/3.0;
        rp=(lx+2*rx)/3.0;
        a = F(x,y,lp);
        b = F(x,y,rp);
        if(a<b)   rx=rp;
        else lx=lp;
    }
    f.z=lp;
    return a;
}

long double FY(long double x)
{
    long double lx=Min.y,rx=Max.y,lp,rp,a,b;
    int i;

    rii(50)
    {
        lp=(2*lx+rx)/3.0;
        rp=(lx+2*rx)/3.0;

        a = FZ(x,lp);
        b = FZ(x,rp);
        if(a<b)   rx=rp;
        else lx=lp;
    }
    f.y=lp;
    return a;
}


void NestedTernarySearch()
{
    long double lx=Min.x,rx=Max.x,lp,rp,a,b;
    int i;

    rii(50)
    {
        lp=(2*lx+rx)/3.0;
        rp=(lx+2*rx)/3.0;
        a = FY(lp);
        b = FY(rp);
        if(a<b)   rx=rp;
        else lx=lp;
    }
    f.x=lp;
}



int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.out","w",stdout);
    //ios_base::sync_with_stdio(false);

    int i,j,k,tks,ks=1,m,l,o;
    double x,y,z;


    while(cin>>n)
    {

        rii(n)
        {
            cin>>p[i].x>>p[i].y>>p[i].z;
            if(!i)
            {
                Max=p[i];
                Min=p[i];
                continue;
            }
            Max.x=max(Max.x,p[i].x);
            Max.y=max(Max.y,p[i].y);
            Max.z=max(Max.z,p[i].z);

            Min.x=min(Min.x,p[i].x);
            Min.y=min(Min.y,p[i].y);
            Min.z=min(Min.z,p[i].z);
        }

        NestedTernarySearch();
        x=f.x;
        y=f.y;
        z=f.z;

        printf("%.8lf %.8lf %.8lf\n",x,y,z);
    }

    return 0;
}




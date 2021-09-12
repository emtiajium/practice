/**
    Lazy propagation.
    Problem: Codeforces Round #104 (Div. 1 : E. Lucky Queries)
    Link: http://codeforces.com/contest/145/problem/E
*/


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




#define debug(args...)          {cout<<" #--> ";dbg,args; cerr<<endl;}

struct debugger
{
    // Taken from rudradevbasak
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;




//const double pi=2*acos(0.);
const double pi=acos(-1.0);

const double eps=1e-7;

template<class TT>TT sqr(TT a){return a*a;}

template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
template<class ZZ>ZZ max(ZZ a,ZZ b,ZZ c){return max(a,max(b,c));}
template<class ZZ>ZZ min(ZZ a,ZZ b,ZZ c){return min(a,min(b,c));}

//typedef pair<int,int> pii;

//typedef double type;
//struct P{
//    type x,y,z;
//    P(type xi=0,type yi=0,type zi=0):x(xi),y(yi),z(zi){};
//    void scan(){cin>>x>>y>>z;}
//    void scan1(){scanf("%lf%lf%lf",&x,&y,&z);}
//};


//bool operator < (const P &a,const P &b){return a>b;}
//bool com(P a,P b){return;}

//struct pq{int n,w;
//    pq(int nn=0,int ww=0):n(nn),w(ww){}
//    bool operator<(const pq &b) const{return w<b.w;}
//};

char  in[1000010];
int  a4[4000010],a7[4000010],a47[4000010],a74[4000010],lp[4000010];

void build(int nod,int l,int r)
{
    if(l==r)
    {
        if(in[l]=='4')  a4[nod]=1;
        else a7[nod]=1;

        a47[nod]=1;
        a74[nod]=1;
        return ;
    }

    int mid=(l+r)/2,a=nod*2,b=nod*2+1;

    build(a,l,mid);
    build(b,mid+1,r);

    a4[nod] = a4[a] + a4[b];
    a7[nod] = a7[a] + a7[b];

    a47[nod] = max(a4[a]+a47[b],a47[a]+a7[b]);
    a74[nod] = max(a7[a]+a74[b],a74[a]+a4[b]);
}


void update(int nod,int l,int r,int ml,int mr)
{
    int mid=(l+r)/2,a=nod*2,b=nod*2+1;

    if(lp[nod])
    {

        {
            swap(a74[nod],a47[nod]);
            swap(a4[nod],a7[nod]);
        }
        if(r>l)
        {
            lp[a]=1-lp[a];
            lp[b]=1-lp[b];
        }

        lp[nod]=0;
    }

    if(r<ml || mr<l)    return ;


    if(ml<=l && r<=mr)
    {
        swap(a74[nod],a47[nod]);
        swap(a4[nod],a7[nod]);
        if(r>l)
        {
            lp[a]=1-lp[a];
            lp[b]=1-lp[b];
        }
        return ;
    }

    update(a,l,mid,ml,mr);
    update(b,mid+1,r,ml,mr);


    a4[nod] = a4[a] + a4[b];
    a7[nod] = a7[a] + a7[b];

    a47[nod] = max(a4[a]+a47[b],a47[a]+a7[b]);
    a74[nod] = max(a7[a]+a74[b],a74[a]+a4[b]);
}




int main()
{
//    freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    //ios_base::sync_with_stdio(false);
    //std::cout << std::setprecision(13)<<b<<std::endl;
    //assert(ks<0);

    int i,j,k,l,r,tks,ks=1,n,m;
    char q[10];

    while(scanf("%d%d",&n,&m)==2)
    {
        scanf("%s",in+1);
        memset(a4,0,sizeof a4);
        memset(a7,0,sizeof a7);
        memset(a47,0,sizeof a47);
        memset(a74,0,sizeof a74);
        memset(lp,0,sizeof lp);

        build(1,1,n);

        while(m--)
        {
            scanf("%s",q);

            if(q[0]=='s')
            {
                scanf("%d%d",&l,&r);
                update(1,1,n,l,r);

            }
            else
                printf("%d\n",a47[1]);

        }
    }

    return 0;
}



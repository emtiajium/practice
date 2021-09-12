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

template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
template<class ZZ>ZZ max(ZZ a,ZZ b,ZZ c){return max(a,max(b,c));}
template<class ZZ>ZZ min(ZZ a,ZZ b,ZZ c){return min(a,min(b,c));}

//typedef pair<int,int> pii;
//typedef struct {int x,y,z;}P;

//bool operator < (const P &a,const P &b){return a>b;}
//bool com(P a,P b){return;}

//struct pq{int n,w;
//    pq(int nn=0,int ww=0):n(nn),w(ww){}
//    bool operator<(const pq &b) const{return w<b.w;}
//};
const int S = 100001;

int par[S][18],mxe[S][18],mie[S][18],st[S],ft[S];
int lg,Time;
vector<int>g[S];

int mxv,miv;

void dfs(int u)
{
    int i,j,v,w;

    st[u]=Time++;

    for(i=1;i<=lg;i++)
    {
        par[u][i]=par[ par[u][i-1] ][i-1];
        mxe[u][i]=max(mxe[u][i],max(mxe[u][i-1],mxe[par[u][i-1]][i-1]));
        mie[u][i]=min(mie[u][i],min(mie[u][i-1],mie[par[u][i-1]][i-1]));
    }

    for(i=0;i<SZ(g[u]);i+=2)
    {
        v = g[u][i];
        w = g[u][i+1];

        if(v!=par[u][0])
        {
            par[v][0]=u;
            mxe[v][0]=w;
            mie[v][0]=w;
            dfs(v);
        }
    }
    ft[u]=Time++;
}

bool IsAncestor(int a,int u){return st[a]<=st[u] && ft[u]<=ft[a];}

int LCA(int u,int v)
{
    int i;
    if(IsAncestor(u,v))   return u;
    if(IsAncestor(v,u))   return v;

    for(i=lg;i>-1;i--)
        if(!IsAncestor(par[u][i],v))    u=par[u][i];
    return par[u][0];
}


void Path(int u,int v)
{

    for(int i=lg;i>-1;i--)
        if(ft[u]>ft[par[v][i]])
        {
            mxv=max(mxv,mxe[v][i]);
            miv=min(miv,mie[v][i]);
            v = par[v][i];
        }
    mxv=max(mxv,mxe[v][0]);
    miv=min(miv,mie[v][0]);

    return ;
}

int main()
{
    int i,j,k,l,tks,ks=1,n,m,u,v,w,q,lca;

    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);

        for(i=1;i<n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            g[u].PB(v);
            g[u].PB(w);
            g[v].PB(u);
            g[v].PB(w);
        }
        Time=0;
        lg = 1 + (log(n)/log(2));

        for(i=1;i<=n;i++)
            for(j=0;j<=lg;j++)
                mxe[i][j]=par[i][j]=-1,mie[i][j]=8000000;

        par[1][0]=1;
        dfs(1);

        printf("Case %d:\n",ks++);
        scanf("%d",&q);

        while(q--)
        {
            scanf("%d%d",&u,&v);
            mxv=-1;
            miv=8000000;
            lca=LCA(u,v);
            if(lca!=u)  Path(lca,u);
            if(lca!=v)  Path(lca,v);

            printf("%d %d\n",miv,mxv);
        }
        if(tks) for(i=1;i<=n;i++)   g[i].clear();
    }

    return 0;
}




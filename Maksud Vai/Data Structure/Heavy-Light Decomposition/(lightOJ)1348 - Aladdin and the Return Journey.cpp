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
#define pb          push_back
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


const int size=30010;

int grandpar[size],par[size],subtree[size],vertexid[size],gen[size],level[size],ar[size];
int idno;
int tree[4*size];
vector<int>g[size];

int dfs(int u)
{
    subtree[u]=1;
    int i,v;

    for(i=0;i<SZ(g[u]);i++)
    {
        v=g[u][i];
        if(v==par[u])   continue;
        par[v]=u;
        level[v]=level[u]+1;
        subtree[u]+=dfs(v);
    }
    return subtree[u];
}

void PrepareSegmentTree(int u)
{
    int max,maxid,i,v;
    max=maxid=-1;

    vertexid[u]=idno++;
    for(i=0;i<SZ(g[u]);i++)
    {
        v=g[u][i];
        if(v==par[u])   continue;
        if(subtree[v]>max)
        {
            max = subtree[v];
            maxid=v;
        }
    }

    if(max==-1) return ;
    grandpar[maxid]=grandpar[u];
    PrepareSegmentTree(maxid);

    for(i=0;i<SZ(g[u]);i++)
    {
        v=g[u][i];
        if(v==par[u] || v==maxid)   continue;
        grandpar[v]=v;
        PrepareSegmentTree(v);
    }
}

int Initialize(int nod,int l,int h)
{
    if(l==h)    return tree[nod]=ar[l];
    int mid=(l+h)>>1;
    return tree[nod]=Initialize(nod*2,l,mid)+Initialize(2*nod+1,mid+1,h);
}

void Update(int nod,int l,int h,int pos,int val)
{
    if(h<pos || pos<l)  return ;
    tree[nod]+=val;
    if(l==h)
    {
        ar[idno]+=val;
        return ;
    }
    int mid=(l+h)>>1;
    Update(nod*2,l,mid,pos,val);
    Update(nod*2+1,mid+1,h,pos,val);
}


int Query(int nod,int l,int r,int ml,int mr)
{
    if(r<ml||mr<l)  return 0;
    if(ml<=l&&r<=mr)    return tree[nod];
    int mid=(l+r)>>1;
    return Query(nod*2,l,mid,ml,mr)+Query(nod*2+1,mid+1,r,ml,mr);
}

int main()
{
    //freopen("in.in","a",stdin);
    //freopen("in.in","w",stdout);
    //ios_base::sync_with_stdio(false);
    //std::cout << std::setprecision(13)<<b<<std::endl;
    //assert(ks<0);

    int i,j,k,l,tks,ks=1,n,m,u,v,q,ans;

    scanf("%d",&tks);
    while(tks--)
    {
        idno=0;
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d",gen+i);
            g[i].clear();
        }

        for(i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            g[u].pb(v);
            g[v].pb(u);
        }
        par[0]=0;
        dfs(0);
        grandpar[0]=0;
        PrepareSegmentTree(0);

        for(i=0;i<n;i++)
            ar[vertexid[i]]=gen[i];

        Initialize(1,0,n-1);
        printf("Case %d:\n",ks++);
        scanf("%d",&q);

        while(q--)
        {
            scanf("%d",&j);
            if(j)
            {
                scanf("%d%d",&u,&v);
                idno=vertexid[u];
                Update(1,0,n-1,vertexid[u],v-ar[vertexid[u]]);
            }
            else
            {
                ans=0;
                scanf("%d%d",&u,&v);
                while(grandpar[u]!=grandpar[v])
                {
                    if(level[grandpar[v]]>level[grandpar[u]])   swap(u,v);
                    ans+=Query(1,0,n-1,vertexid[grandpar[u]],vertexid[u]);
                    u=par[grandpar[u]];
                }
                if(level[v]<level[u])   swap(u,v);
                ans+=Query(1,0,n-1,vertexid[u],vertexid[v]);
                printf("%d\n",ans);
            }
        }
    }

    return 0;
}




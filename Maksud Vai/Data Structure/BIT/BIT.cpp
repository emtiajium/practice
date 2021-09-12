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
//typedef struct {int x,y,z;}P;
//bool operator < (const P &a,const P &b){return a>b;}
//bool com(P a,P b){return;}
//struct pq{int n,w;  bool operator<(const pq &b)const{return w>b.w;}};


const int s=500;
int tree[s];


int Find(int cu,int mxind)
{
    int i,bitmask=1,ind=0,I;

    rii(28) if(mxind&p2(i))    bitmask=p2(i);

    while(bitmask && ind<mxind)
    {
        I=ind+bitmask;

        if(cu>=tree[I])
        {
            ind=I;
            cu-=tree[I];
        }
        bitmask>>=1;
    }

    if(cu)  return -1;
    return ind;
}

int Read(int ind)
{
    int sum=tree[ind],z;
    z=ind-(ind&-ind);
    ind--;
    while(ind!=z)
    {
        sum-=tree[ind];
        ind -=(ind&-ind);
    }
    return sum;
}


void Update(int ind,int val,int mxind)
{
    while(ind<=mxind)
    {
        tree[ind]+=val;
        ind+=(ind&-ind);
    }
}

int Query(int ind)
{
    int sum=0;

    while(ind)
    {
        sum+=tree[ind];
        ind-=(ind&-ind);
    }
    return sum;
}




int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.out","w",stdout);
    //ios_base::sync_with_stdio(false);
    //std::cout << std::setprecision(13)<<b<<std::endl;
    //assert(ks<0);

    int i,j,k,t,tks,ks=1,n,m,a,b;

    while(cin>>n)
    {
        memset(tree,0,sizeof tree);
        for(i=0;i<n;i++)
        {
            scanf("%d",&k);
            Update(i+1,k,n);
        }


        while(cin>>t && t)
        {
            switch(t)
            {
                ///Sum from a to b
                case 1:     cin>>a>>b;
                            deb(Query(b)-Query(a-1));
                            break;

                ///Update a valu of index a by b;
                case 2:     cin>>a>>b;
                            Update(a,b,n);
                            break;

                /// Valu of index a
                case 3:     cin>>a;
                            deb(Read(a));
                            break;

                ///Print the tree.
                case 4:     for(i=0;i<=n;i++)   cout<<tree[i]<<" "; cout<<endl;
                            break;

                case 5:     cin>>a;
                            deb(Find(a,n));
                            break;
            }
        }

    }
    return 0;
}




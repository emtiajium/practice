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
#include<list>
#include<utility>
#include<functional>
#include <deque>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <ctime>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

using namespace std;

#define deb(a)      cout<<" -> "<<#a<<"  "<<a<<endl;
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          2*acos(0)
#define ERR         1e-5
#define PRE         1e-8
#define popcount(a) (__builtin_popcount(a))
#define SZ(a)       ((int)a.size())
#define PB          push_back
#define LL          long long
#define ISS         istringstream
#define OSS         ostringstream
#define SS          stringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define SII         set<int>::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define memc(a,b)   memcpy(a,b,sizeof(b))
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
#define all(a)      (a).begin(),(a).end()
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define p2(a)       (1LL<<a)

typedef struct{int x,y;}P;
#define  NP 100200

P pa[NP],pb[NP],pvt,pc[NP];

P MV(P a,P b){b.x-=a.x;b.y-=a.y;return b;}
int C(P a,P b){return a.x*b.y-a.y*b.x;}

bool com(P a,P b)
{
    int c=C(MV(pvt,a),MV(pvt,b));
    if(c)   return c>0;
    return sqr(pvt.x-a.x)+sqr(pvt.y-a.y) < sqr(pvt.x-b.x)+sqr(pvt.y-b.y);
}

void PS(int n,P a[])
{
    int i;
    pvt = a[0];
    for(i=1;i<n;i++)
        if(pvt.y>a[i].y)    pvt=a[i];
        else if(pvt.y==a[i].y&& pvt.x>a[i].x)   pvt=a[i];

    sort(a,a+n,com);
}

bool CM(int n)
{
    P v=MV(pb[0],pc[0]),u;

    for(int i=1;i<n;i++)
    {
        u = MV(pb[i],pc[i]);
        if(u.x!=v.x || u.y!=v.y)    return false;
    }

    return true;
}

int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.in","w",stdout);

    int tks,i,j,n,tst;

    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)    scanf("%d%d",&pa[i].x,&pa[i].y);
        for(i=0;i<n;i++)    scanf("%d%d",&pb[i].x,&pb[i].y);

        PS(n,pb);
        //rii(n)  printf("%d %d\n",pb[i].x,pb[i].y);

        //R 1
        for(i=0;i<n;i++)    pc[i]=pa[i];
        PS(n,pc);
        if(CM(n)) {printf("MATCHED\n");continue;}

        //R 1
        for(i=0;i<n;i++)
        {
            pc[i].x=-pa[i].y;
            pc[i].y=pa[i].x;
        }
        PS(n,pc);
        if(CM(n)) {printf("MATCHED\n");continue;}

        //R 2
        for(i=0;i<n;i++)
        {
            pc[i].x=-pa[i].x;
            pc[i].y=-pa[i].y;
        }
        PS(n,pc);
        if(CM(n)) {printf("MATCHED\n");continue;}

        //R 3
        for(i=0;i<n;i++)
        {
            pc[i].x=pa[i].y;
            pc[i].y=-pa[i].x;
        }
        PS(n,pc);
        if(CM(n)) {printf("MATCHED\n");continue;}

        printf("NOT MATCHED\n");
    }


    return 0;
}


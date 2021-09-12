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
#define ERR         1e-7
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
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a)      (a).begin(),(a).end()
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define p2(a)       (1LL<<a)


typedef struct {double x,y,r;char a[3];}S;
typedef struct {double x,y;}V;

V MV(V a,V b){V re;re.x=b.x-a.x;re.y=b.y-a.y;return re;}
double DP(V a,V b){return a.x*b.x+a.y*b.y;}
double CP(V a,V b){return a.x*b.y-a.y*b.x;}
double ABS(V a){return sqrt(sqr(a.x)+sqr(a.y));}

S s[16];
int n,tru;
double mat[16][16],M;
bool mm[p2(15)][15];
double f[p2(15)][15];

double dis(double x,double y,double x1,double y1){return sqrt(sqr(x-x1)+sqr(y-y1));}

double P2S(double x1,double y1,double x2,double y2,double x3,double y3)
{
    V a,b,c;
    a.x=x1;
    a.y=y1;
    b.x=x2;
    b.y=y2;
    c.x=x3;
    c.y=y3;
    if(0>DP(MV(b,c),MV(b,a)))   return dis(x1,y1,x2,y2);
    if(0>DP(MV(c,b),MV(c,a)))   return dis(x1,y1,x3,y3);
    double mx;

    mx = CP(MV(b,c),MV(b,a))/ABS(MV(b,c));
    return fabs(mx);
}

double S2S(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)
{

    double mx;
    mx = P2S(x1,y1,x3,y3,x4,y4);
    mx <?= P2S(x2,y2,x3,y3,x4,y4);
    mx <?= P2S(x3,y3,x1,y1,x2,y2);
    mx <?= P2S(x4,y4,x1,y1,x2,y2);

    return mx;
}

double DIS(S u,S v)
{
    double mx=1e10;
    int xx[]={0,1,1,0,0},i,j;
    int yy[]={0,0,1,1,0};

    if(u.a[0]==v.a[0] && u.a[0]=='C')   return dis(u.x,u.y,v.x,v.y)-u.r-v.r;
    if(u.a[0]!=v.a[0] && v.a[0]=='S')
    {
        rii(4)
            mx<?=P2S(u.x,u.y,v.x+xx[i]*v.r,v.y+yy[i]*v.r,v.x+xx[i+1]*v.r,v.y+yy[i+1]*v.r)-u.r;
    }
    else if(u.a[0]!=v.a[0] && u.a[0]=='S')
    {
        swap(u,v);
        rii(4)
            mx<?=P2S(u.x,u.y,v.x+xx[i]*v.r,v.y+yy[i]*v.r,v.x+xx[i+1]*v.r,v.y+yy[i+1]*v.r)-u.r;
    }
    else
    {
        rii(4)rij(4)
        {
            mx<?=S2S(u.x+xx[i]*u.r,u.y+yy[i]*u.r,u.x+xx[i+1]*u.r,u.y+yy[i+1]*u.r,
                     v.x+xx[j]*v.r,v.y+yy[j]*v.r,v.x+xx[j+1]*v.r,v.y+yy[j+1]*v.r);
        }
    }

    return mx;
}


double go(int msk,int l)
{

    if(msk==p2(n)-1)    return 0;
    if(mm[msk][l])    return f[msk][l];
    mm[msk][l]=true;
    int i;
    double cur;
    f[msk][l]=1e10;

    rii(n)
        if((p2(i)&msk)==0)
        {
            cur  = max(mat[l][i],10.*go(msk|p2(i),i)/9.);
            f[msk][l]<?=cur;
        }

    return f[msk][l];
}


int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.in","w",stdout);
    int tks,i=0,it,j;
    double H,L;

    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d",&n);
        rii(n)
            scanf("%s%lf%lf%lf",s[i].a,&s[i].x,&s[i].y,&s[i].r);


        rii(n)
            fij(i+1,n)
                mat[i][j]=mat[j][i]=DIS(s[i],s[j]);

        mem(mm,false);
        printf("%.6lf\n",go(1,0));


    }
    return 0;
}



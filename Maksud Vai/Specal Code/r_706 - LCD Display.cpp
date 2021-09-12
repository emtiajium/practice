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

string dig[]={"012456","56","12345","23456","0356","02346","012346","256","0123456","023456"};
char o[23][105];

int dx1[]={0,1,0,1,2,0,1};
int dx2[]={1,2,0,1,2,1,2};
int dy1[]={0,0,0,0,0,1,1};
int dy2[]={0,0,1,1,1,1,1};

void go(int p,int d,int s)
{
    int i,m,j;

    rii(SZ(dig[d]))
    {
        m = dig[d][i]-48;
        if(m>=2 && m<=4)    rij(s)  o[dx1[m]*s+dx2[m]][p+dy1[m]*s+dy2[m]+j]='-';
        else rij(s) o[dx1[m]*s+dx2[m]+j][p+dy1[m]*s+dy2[m]]='|';
    }
}

int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.in","w",stdout);
    //ios_base::sync_with_stdio(false);
    char in[10];
    int s,i,l,j;

    while(scanf("%d%s",&s,in)==2 && s)
    {
        mem(o,' ');
        l = strlen(in);

        rii(l)  go(i*(s+3),in[i]-48,s);

        rii(2*s+3)
        {
            rij((l-1)*(s+3)+s+2)   printf("%c",o[i][j]);
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}




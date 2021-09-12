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

const int sz=2004;

char t[2004];
char pr[2004];
char po[2004];
bool ch[2][2004];
int mm[sz][sz],pf[sz],L,lpr,lpo;

int go(int i,int j)
{
    if(i==L||j==L)  return 0;
    if(i==j)    return 0;
    if(i>j) swap(i,j);
    int &re=mm[i][j];

    if(re>-1)    return re;

    return re=(t[i]==t[j])?1+go(i+1,j+1):0;
}

void KMP(char *txt,char *pat,int no)
{
    int i,j,ltxt=strlen(txt),lpat=strlen(pat);

    pf[0]=-1;
    j=-1;
    for(i=1;i<lpat;i++)
    {
        while(j>-1&&pat[j+1]!=pat[i]) j=pf[j];
        if(pat[j+1]==pat[i])    j++;
        pf[i]=j;
    }

    j=-1;
    for(i=0;i<ltxt;i++)
    {
        while(j>-1&&pat[j+1]!=txt[i]) j=pf[j];
        if(pat[j+1]==txt[i])    j++;
        if(j+1==lpat)
        {
            if(no)  ch[no][i]=true;
            else  ch[no][i-j]=true;
            j = pf[j];
        }
    }
}

int main()
{
    int i,j,k,l,cnt,m;

    while(scanf("%s%s%s",t,pr,po)==3)
    {
        mem(mm,-1);
        mem(ch,false);

        L = strlen(t);
        lpo=strlen(po);
        lpr=strlen(pr);

        KMP(t,pr,0);
        KMP(t,po,1);


        cnt=0;
        m = max(lpo,lpr);

        rii(L)  if(ch[0][i])
        {
            k = m-1;
            fij(i+1,L)  if(ch[0][j])    k = max(k,go(i,j));
            fij(i+k,L)  if(ch[1][j])    cnt++;
        }


        printf("%d\n",cnt);
    }
}



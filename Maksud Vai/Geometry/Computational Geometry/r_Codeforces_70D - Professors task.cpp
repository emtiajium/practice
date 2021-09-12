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


//#include<cmath>
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

const double pi=2*acos(0.);

template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}

typedef struct {
    LL x,y;    double an;   int t;
    void read(){    scanf("%d%I64d%I64d",&t,&x,&y);}
    void print(){printf("x:%I64d  y:%I64d  an:%lf\n",x,y,an);}
}P;

P p[100020];
set<P>s;

bool operator<(const P &a,const P &b){    return a.an<b.an;}

//P MV(P a,P b){return (P){b.x-a.x,b.y-a.y,0,0};}
P MV(P a,P b){return (P){b.x-a.x,b.y-a.y};}

LL CP(P a,P b){return a.x*b.y-a.y*b.x;}

P Pre(P a)
{
    if(s.count(a)>0)    return *s.find(a);
    set<P>IT i=s.lower_bound(a);
    if(i!=s.begin())    return *--i;
    return *--s.end();
}

P Nxt(P a)
{
    set<P> IT i=s.upper_bound(a);

    if(i!=s.end())    return *i;
    return *s.begin();
}


bool Isinside(P c){
    P a=Pre(c),b=Nxt(c);
    return (CP(MV(c,b),MV(c,a))<=0);
}

void add(P a)
{
    if(Isinside(a)) return ;

    P b,c;

    while(true)
    {
        b = Nxt(a);
        s.erase(b);
        c = Nxt(a);
        if(CP(MV(c,b),MV(c,a))<0)
        {
            s.insert(b);
            break;
        }
    }

    while(true)
    {
        b = Pre(a);
        s.erase(b);
        c = Pre(a);
        if(CP(MV(c,b),MV(c,a))>0)
        {
            s.insert(b);
            break;
        }
    }

    s.insert(a);
}


int main()
{
    int i,j,k,l,n,m,cnt,a;
    double x,y;

    while(cin>>n)
    {
        s.clear();
        rii(n)
            p[i].read();

        p[0].an=0;
        x=y=0;
        rii(3)  x+=p[i].x,y+=p[i].y;

        x/=3;
        y/=3;

        rii(n)
            p[i].an=atan2(p[i].y-y,p[i].x-x)+(atan2(p[i].y-y,p[i].x-x)<0?2*pi:0);

        rii(3)  s.insert(p[i]);

        fii(3,n)
        {
            if(p[i].t==1)   add(p[i]);
            else
            {
                if(Isinside(p[i])) puts("YES");
                else puts("NO");
            }
        }
    }

    return 0;
}

/*

Notice, that any point from the triangle based on first three points will be into the area bounded with the convex hull in the future. Let choose one of these points ad set it as the origin. All points of convex hull will keep in structure like map in C++, where the key is the angle of vector from the origin to a point. No two points from the hull will have the same angle.

How to answer the second-type queries? For the point from the query (A) let's find the closest point clockwise (B) and the closest point anticlockwise (C). If the vectors AB and AC make up a clockwise rotation, then point A doesn't lay into the convex or on it's bounds.

How to answer the first-type queries? If the point from the query (C) lays into the convex hull, then do nothing else let's find two closest points clockwise relative to point C (the closest will be named A, tho other will be named B). If rotation from the vector AB to the vector AC is a counterclockwise rotation then processing points laying clockwise relative to point C in ended, else you have to delete point A from the structure and repeat the same actions. The similar actions you should apply to points anticlockwise relative to point C.

All points will be added and deleted in the structure not more than once. These operations need O(log(h)) time, where h is a number of point in convex hull. Total  asymptotic form is O(q * log(h)).

*/

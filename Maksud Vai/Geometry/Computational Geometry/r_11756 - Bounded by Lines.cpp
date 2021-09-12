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



typedef struct {double x,y;    void print(){printf(" -> x:%lf y:%lf\n",x,y);}}P;

typedef struct {
    double a,b,c;
    void print(){printf(" -> a:%lf b:%lf c:%lf\n",a,b,c);}
    }L;

typedef struct {
    double m;
    L l;
    P p;
    void print(){printf(" -> m:%lf\n",m);p.print();l.print();}
    }D;


const int NL = 1000100;
D ar[NL];
P fp[2*NL];
int n,nf,top,stk[NL];
double xh,xl;


double find_y(L l,double x){return (-l.c-l.a*x)/l.b;}
double find_x(L l,double y){return (-l.c-l.b*y)/l.a;}

P IP(L l1,L l2)
{
    double v = l1.a*l2.b - l2.a*l1.b;
    return (P){(l1.b*l2.c - l2.b*l1.c)/v , (l1.c*l2.a - l2.c*l1.a)/v };
}

bool operator < (const D &a,const D &b){

    if(!EQ(a.p.y,b.p.y))    return a.p.y>b.p.y;
    return a.m>b.m;
}

//bool com(P a,P b){return;}
//struct pq{int n,w;  bool operator<(const pq &b)const{return w>b.w;}};


int main()
{
    //freopen("i.in","r",stdin);
    //freopen("ou.in","w",stdout);
    //ios_base::sync_with_stdio(false);

    int i,j,tks,ks=1,m;
    double x1,x2,y1,y2,ans;
    P p;

    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d",&n);


        for(m=i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            if(x1==x2)  continue;
            ar[m].m = (y1-y2)/(x1-x2);
            ar[m].l = (L){y1-y2,x2-x1,x1*y2-x2*y1};
            m++;
        }
        n = m;
        scanf("%lf%lf",&x1,&x2);
        xl = min(x1,x2);
        xh = max(x1,x2);

        for(i=0;i<n;i++)    ar[i].p = (P) {xh+1,find_y(ar[i].l,xl)};

        sort(ar,ar+n);

        //rii(n)  ar[i].print();


        ar[0].p.x=xl;
        top = 0;
        stk[top]=0;

        for(i=1;i<n;i++)
            if(ar[stk[top]].m<ar[i].m)
            {
                while(true)
                {
                    p = IP(ar[stk[top]].l,ar[i].l);
                    if(p.x<ar[stk[top]].p.x)    top--;
                    else
                    {
                        if(p.x<xh)
                        {
                            stk[++top] = i;
                            ar[i].p.x=p.x;
                        }
                        break;
                    }
                }
            }


        for(nf=i=0;i<=top;i++)
            fp[nf++] = (P){ar[stk[i]].p.x , find_y(ar[stk[i]].l,ar[stk[i]].p.x) };

        fp[nf++] = (P){xh , find_y(ar[stk[top]].l,xh)};


        //deb("First:");  rii(nf) fp[i].print();

        ar[n-1].p.x=xl;
        top=0;
        stk[top] = n-1;

        for(i=n-1;i>-1;i--)
            if(ar[stk[top]].m>ar[i].m)
            {
                while(true)
                {
                    p = IP(ar[stk[top]].l,ar[i].l);
                    if(p.x<ar[stk[top]].p.x)    top--;
                    else
                    {
                        if(p.x<xh)
                        {
                            stk[++top] = i;
                            ar[i].p.x=p.x;
                        }
                        break;
                    }
                }
            }

        //deb(top);
        fp[nf++] = (P){xh , find_y(ar[stk[top]].l,xh)};

        for(i=top;i>-1;i--)
            fp[nf++] = (P){ar[stk[i]].p.x , find_y(ar[stk[i]].l,ar[stk[i]].p.x) };

        //deb("Final");   rii(nf) fp[i].print();

        ///Triangulation
        ans = 0.0;
        fp[nf]=fp[0];

        for(i=0;i<nf;i++)
            ans += fp[i].x*fp[i+1].y - fp[i].y*fp[i+1].x;

        ans = fabs(ans)/2.0;


        printf("%lf\n",ans);
    }


    return 0;
}




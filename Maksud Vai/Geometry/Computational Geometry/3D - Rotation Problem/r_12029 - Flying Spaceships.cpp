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

////const double pi=2*acos(0.);
const double pi=acos(-1.0);

template<class TT>TT sqr(TT a){return a*a;}

template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
template<class ZZ>ZZ max(ZZ a,ZZ b,ZZ c){return max(a,max(b,c));}
template<class ZZ>ZZ min(ZZ a,ZZ b,ZZ c){return min(a,min(b,c));}

//typedef pair<int,int> pii;

typedef double type;
struct P{
    type x,y,z;
    P(type xi=0,type yi=0,type zi=0):x(xi),y(yi),z(zi){};
    void scan(){scanf("%lf%lf%lf",&x,&y,&z);}
    //void scan(){cin>>x>>y>>z;}
};


double Abs(P a){return sqrt(sqr(a.x)+sqr(a.y)+sqr(a.z));}
P MV(P a,P b){return P(b.x-a.x,b.y-a.y,b.z-a.z);}
double DP(P a,P b){return a.x*b.x+a.y*b.y+a.z*b.z;}
P CP(P a,P b){return P(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);}
P Add(P a,P b){return P(a.x+b.x,a.y+b.y,a.z+b.z);}
P U(P a){double l = Abs(a);return P(a.x/l,a.y/l,a.z/l);}
P Rev(P a){return P(-a.x,-a.y,-a.z);}
double Angle(P a,P b){return acos(DP(a,b)/Abs(a)/Abs(b));}
double Dis(P a,P b){return Abs(MV(a,b));}
P LV(P a,double l){return P(a.x*l,a.y*l,a.z*l);}

///Rotation
P Rotate(P a,P b,double th){
    double bth,tot;
    if(th>90)
    {
        th -=90;
        swap(a,b);
        b = Rev(b);
    }
    th = th/180.0*pi;
    bth=cos(th);
    th=sin(th);
    tot=th+bth;

    return U(P((a.x*bth+b.x*th)/tot,
               (a.y*bth+b.y*th)/tot,(a.z*bth+b.z*th)/tot));
}

double minSegmentToPoint(P a,P b,P c)
{
    if(DP(MV(a,b),MV(a,c))<0)   return Dis(a,c);
    if(DP(MV(b,a),MV(b,c))<0)   return Dis(b,c);
    return abs(Abs(CP(MV(a,b),MV(a,c)))/Abs(MV(a,b)));
}

double maxSegmentToPoint(P a,P b,P c){return max(Dis(a,c),Dis(b,c));}

void FORWARD(P &U,P &F,double v,double &minD,double &maxD,P &A,P &B,P &C)
{
    B = Add(A,LV(F,v));
    minD = min(minD,minSegmentToPoint(A,B,C));
    maxD = max(maxD,maxSegmentToPoint(A,B,C));
    A=B;
}

void YAW(P &Up,P &F,int v)
{
    if(v>=0)    F=Rotate(F,U(CP(F,Up)),v);
    else F=Rotate(F,U(CP(Up,F)),-v);
}


void ROLL(P &Up,P &F,int v)
{
    if(v<0)    Up=Rotate(Up,U(CP(Up,F)),-v);
    else Up=Rotate(Up,U(CP(F,Up)),v);
}


void PITCH(P &Up,P &F,int v)
{
    P up,f;
    if(v>=0)
    {
        f = Rotate(F,Up,v);
        up = Rotate(Up,Rev(F),v);
    }
    else
    {
        f = Rotate(F,Rev(Up),-v);
        up = Rotate(Up,F,-v);
    }
    Up=up;F=f;
}



int main()
{
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    //ios_base::sync_with_stdio(false);
    //std::cout << std::setprecision(13)<<b<<std::endl;
    //assert(ks<0);

    int i,j,k,l,tks,ks=1,n,m,v;
    P U,F,A,B,C;
    double minD,maxD;
    char str[10];

    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        A.scan();
        C.scan();
        U = P(0,0,1.0);
        F = P(1.0,0,0);
        minD=maxD=Dis(A,C);


        while(n--)
        {
            scanf("%s%d",str,&v);

            switch(str[0])
            {
                case 'F':   FORWARD(U,F,v,minD,maxD,A,B,C);   break;
                case 'Y':   YAW(U,F,v); break;
                case 'R':   ROLL(U,F,v); break;
                case 'P':   PITCH(U,F,v); break;
            }
        }
        printf("Case %d: %.10lf %.10lf\n",ks++,minD,maxD);
    }

    return 0;
}




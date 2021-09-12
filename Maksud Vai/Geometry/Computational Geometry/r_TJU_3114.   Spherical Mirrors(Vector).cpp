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
    void print(){printf("%.4lf %.4lf %.4lf\n",x,y,z);}
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
P LV(P a,double l){a=U(a);return P(a.x*l,a.y*l,a.z*l);}

///Rotation
P O[101];
double r[101];

int main()
{
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    //ios_base::sync_with_stdio(false);
    //std::cout << std::setprecision(13)<<b<<std::endl;
    //assert(ks<0);

    int i,tks,ks=1,n,pre,cur;
    P F,A,B,C,D,E,BE,BA,AB,BD;
    double dis,oc,be,bc,ac,ab;



    while(scanf("%d",&n)==1&&n)
    {
        F.scan();
        A=P();
        rii(n)
        {
            O[i].scan();
            scanf("%lf",&r[i]);
        }

        tks=0;


        pre=-1;

        while(tks++<6)
        {
            //deb(tks);
            dis=1e10;
            cur=-1;

            for(i=0;i<n;i++)
                if(pre!=i)
                {
                    oc=Abs(CP(MV(A,O[i]),F))/Abs(F);

                    if(oc>r[i]) continue;
                    bc = sqrt(sqr(r[i])-sqr(oc));
                    ac = DP(MV(A,O[i]),F)/Abs(F);

                    if(ac<0)    continue;

                    ab = ac-bc;
                    if(ab<dis)
                    {
                        dis=ab;
                        cur=i;
                    }
                }

            if(cur==-1)     break;


            AB = LV(F,dis);
            B = Add(A,AB);
            BA = MV(B,A);
            be = abs(DP(MV(O[cur],B),BA)/Abs(MV(O[cur],B)));
            BE = LV(MV(O[cur],B),be);
            BD = P(2*BE.x-BA.x,2*BE.y-BA.y,2*BE.z-BA.z);
            F = BD;
            A=B;

            pre=cur;
        }


        A.print();
    }

    return 0;
}




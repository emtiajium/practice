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

bool operator *(string a,string b)
{
    while(SZ(a) && a[0]=='0')   a.erase(0,1);
    while(SZ(b) && b[0]=='0')   b.erase(0,1);

    if(SZ(a)!=SZ(b))    return SZ(a)<SZ(b);
    return a<=b;
}
string Mul(string a,int x)
{
    reverse(all(a));
    int i,l=SZ(a),c,v;
    string r;

    c=0;
    for(i=0;i<l;i++)
    {
        c+=x*(a[i]-48);
        r+=c%10+48;
        c/=10;
    }
    while(c)
    {
        r+=c%10+48;
        c/=10;
    }
    reverse(all(r));
    return r;
}

string Sub(string a,string b)
{
    int i,la=SZ(a),lb=SZ(b),u,l,c;

    reverse(all(a));
    reverse(all(b));

    string re;

    for(c=i=0;i<la;i++)
    {
        u=a[i]-48;
        l=c;
        if(i<lb)    l+=b[i]-48;

        if(l>u)     {u+=10;c=1;}
        else    c=0;
        u-=l;
        re+=u+48;
    }
    while(SZ(re)>1 && re[SZ(re)-1]=='0')   re.erase(SZ(re)-1);
    reverse(all(re));

    return re;
}


string Sqrt(string s)
{
    string a,b,an,re,tm;
    int l,c,t,i;

        l = SZ(s);
        t = 2;
        if(l&1)    t=1;

        an="";
        re="";
        c=0;

        while(c<l)
        {
            a=s.substr(c,t);
            c+=t;
            re+=a;
            b=Mul(an,2);

            for(i=9;i>-1;i--)
            {
                b+=i+48;
                tm=Mul(b,i);
                if(tm * re)
                {
                    an+=i+48;
                    re=Sub(re,tm);

                    while(SZ(re) && re[0]=='0')  re.erase(0,1);

                    break;
                }
                b.erase(SZ(b)-1);
            }
            if(i==-1)   break;
            t=2;
        }

    return an;
}


int main()
{

    string s,an;
    int tks;

    scanf("%d",&tks);

    while(tks--)
    {
        cin>>s;
        an=Sqrt(s);

        cout<<an<<endl;
        if(tks) printf("\n");
    }

    return 0;
}



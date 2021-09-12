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

using namespace std;


#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          2*acos(0)
#define ERR         1e-5
#define PRE         1e-8
#define SZ          size()
#define PB          push_back
#define LL          long long
#define ISS         istringstream
#define OSS         ostringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
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
#define PP(a)       (cout<<a<<endl)
#define sqr(a)      ((a)*(a))
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))

typedef struct{int x,y,no;}P;

P p[1010],pvt;

bool com(P a,P b)
{
    if(CROSS(pvt,a,pvt,b)>0)    return true;
    else if(CROSS(pvt,a,pvt,b)<0)    return false;
    else if(sqr(pvt.x-a.x)+sqr(pvt.y-a.y)<sqr(pvt.x-b.x)+sqr(pvt.y-b.y))    return true;
    else return false;
}

int main(){
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int n,i,j,s,pv;
    double cir;

    while(scanf("%d",&n)==1 && n )
    {
        rii(n){scanf("%d%d",&p[i].x,&p[i].y);p[i].no=i;}
        pvt=p[0];
        pv=0;
        fii(1,n)
            if(p[i].y<pvt.y)    {pvt=p[i];pv=i;}
            else if(p[i].y== pvt.y&& p[i].x<pvt.x)  {pvt=p[i];pv=i;}
        p[pv] = p[0];
        p[0] = pvt;
        sort(p,p+n,com);
        //rii(n)  printf("%d %d i:%d\n",p[i].x,p[i].y,p[i].no);
        cir=0.0;
        p[n]=p[0];
        rii(n)  cir+=sqrt(sqr(p[i].x-p[i+1].x)+sqr(p[i].y-p[i+1].y));
        if( EQ(cir,(2*sqrt(sqr(p[0].x-p[n-1].x)+sqr(p[0].y-p[n-1].y)))) )
            printf("no solution\n");
        else
        {
            if(!CROSS(pvt,p[n-1],pvt,p[n-2]))
            {
                queue<P>S;
                S.push(p[n-1]);
                i=n-2;
                while(!CROSS(pvt,p[n-1],pvt,p[i]))
                {
                    S.push(p[i]);
                    i--;
                }
                while(!S.empty())
                {
                    p[++i] = S.front();S.pop();
                }
            }


            rii(n)  if(!p[i].no)    break;

            fij(i,n)    printf("%d ",p[j].no);
            rij(i)    printf("%d ",p[j].no);
            printf("0\n");
        }
    }
    return 0;
}

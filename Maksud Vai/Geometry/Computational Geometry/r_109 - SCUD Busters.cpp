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

#define oo        (1<<30)
#define PI          3.141592653589793
#define pi          2*acos(0)
#define PB          push_back
#define ERR         1e-5
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define fi(i,a,b)   for(i=a;i<b;i++)
#define fd(i,a,b)   for(i=a;i>b;i--)
#define fii(a,b)   for(i=a;i<b;i++)
#define fdi(a,b)   for(i=a;i>b;i--)
#define fij(a,b)   for(j=a;j<b;j++)
#define fdj(a,b)   for(j=a;j>b;j--)
#define fik(a,b)   for(k=a;k<b;k++)
#define fdk(a,b)   for(k=a;k>b;k--)
#define fil(a,b)   for(l=a;l<b;l++)
#define fdl(a,b)   for(l=a;l>b;l--)
#define ri(i,a)    for(i=0;i<a;i++)
#define rd(i,a)    for(i=a;i>-1;i--)
#define rii(a)     for(i=0;i<a;i++)
#define rdi(a)     for(i=a;i>-1;i--)
#define rij(a)     for(j=0;j<a;j++)
#define rdj(a)     for(j=a;j>-1;j--)
#define rik(a)     for(k=0;k<a;k++)
#define rdk(a)     for(k=a;k>-1;k--)
#define ril(a)     for(l=0;l<a;l++)
#define rdl(a)     for(l=a;i>-1;l--)

typedef long long LL;typedef vector<string>VS;typedef vector<int>VI;typedef vector<double>VD;typedef vector<long long>VLL;

typedef struct{int x,y;}P;
typedef struct{P p[101];int n;double area;bool al;}CITY;
P pvt,tmp;
CITY cty[21];

bool comp(P a,P b){
    int c = CROSS(pvt,a,pvt,b);
    if(c<0)    return false;
    else if(c>0)   return true;
    else if((pvt.x - b.x)*(pvt.x - b.x) + (pvt.y - b.y)*(pvt.y - b.y) > (pvt.x - a.x)*(pvt.x - a.x) + (pvt.y - a.y)*(pvt.y - a.y))   return true;
    else return false;
}

void ConvexHull(CITY &C)
{
    int i,j;
    j=0;
    pvt = C.p[0];
    fii(1,C.n)    if(C.p[i].y<pvt.y)    {pvt=C.p[i];j=i;}
    else if(C.p[i].y==pvt.y && C.p[i].x<pvt.x)    {pvt=C.p[i];j=i;}

    tmp = C.p[0];C.p[0]=pvt; C.p[j] = tmp;

    sort(&C.p[1],&C.p[C.n],comp);

    j=1;
    fii(2,C.n)
    {
        while(CROSS(C.p[j-1],C.p[j],C.p[j-1],C.p[i])<0 )
            j--;
        C.p[++j] = C.p[i];
    }
    C.area = 0;
    C.p[++j] = C.p[0];
    C.n = j;
    rii(C.n)  C.area+= (C.p[i].x * C.p[i+1].y - C.p[i].y * C.p[i+1].x);
    C.area = fabs(C.area/2.0);
}

bool IS_INCITY(P q,CITY C)
{
    int i,j;
    double area=0;
    rii(C.n)  area+= fabs(C.p[i].x*C.p[i+1].y+C.p[i+1].x*q.y+q.x*C.p[i].y -(C.p[i].y*C.p[i+1].x+C.p[i+1].y*q.x+q.y*C.p[i].x))/2.0;

    if(fabs(area-C.area)<ERR)   return true;

    return false;
}

int main(){

    int t=0,i,j;
    P p;
    double area;

    while(scanf("%d",&cty[t].n)==1  && cty[t].n!=-1){
        cty[t].al=true;

        rii(cty[t].n)  scanf("%d%d",&cty[t].p[i].x,&cty[t].p[i].y);
        ConvexHull(cty[t]);
        t++;
    }

    while(scanf("%d%d",&p.x,&p.y)==2)
       rii(t)if(cty[i].al && IS_INCITY(p,cty[i]))    cty[i].al=false;

    area = 0.0;
    rii(t)  if(!cty[i].al)   area += cty[i].area;

    printf("%.2lf\n",area);

    return 0;
}



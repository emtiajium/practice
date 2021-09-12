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
P p[1500],pvt,tmp;

bool comp(P a,P b){
    int c = CROSS(pvt,a,pvt,b);
    if(c<0)    return false;
    else if(c>0)   return true;
    else if((pvt.x - b.x)*(pvt.x - b.x) + (pvt.y - b.y)*(pvt.y - b.y) > (pvt.x - a.x)*(pvt.x - a.x) + (pvt.y - a.y)*(pvt.y - a.y))   return true;
    else return false;
}

int ConvexHull(int n)
{
    int i,j;
    j=0;
    pvt = p[0];
    fii(1,n)    if(p[i].y<pvt.y)    {pvt=p[i];j=i;}
    else if(p[i].y==pvt.y && p[i].x<pvt.x)    {pvt=p[i];j=i;}

    tmp = p[0];p[0]=pvt; p[j] = tmp;

    sort(&p[1],&p[n],comp);

    j=1;
    fii(2,n)
    {
        while(CROSS(p[j-1],p[j],p[j-1],p[i])<=0 && j>0)
            j--;
        p[++j] = p[i];
    }
    p[++j] = p[0];

    return j+1;
}

int main(){

    int t,i,j,n;
    //freopen("in.in","r",stdin);

    scanf("%d",&t);
    printf("%d\n",t);

    while(t--)
    {
        scanf("%d",&n);
        rii(n)  scanf("%d%d",&p[i].x,&p[i].y);
        n = ConvexHull(n);
        printf("%d\n",n);

        rii(n)  printf("%d %d\n",p[i].x,p[i].y);

        if(t){
            scanf("%d",&n);
            printf("-1\n");
        }
    }
    return 0;
}


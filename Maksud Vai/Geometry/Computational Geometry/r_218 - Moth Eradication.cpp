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

#define oo          (1<30)
#define ERR         1e-5
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


typedef struct{double x,y;}P;
P p[1000000],pvt;

bool comp(P a,P b){
    double x;
    x = CROSS(pvt,a,pvt,b);
    if(fabs(x)<ERR)
    {
        if(pow(pvt.x-a.x,2)+pow(pvt.y-a.y,2) < pow(pvt.x-b.x,2)+pow(pvt.y-b.y,2))return true;
        return false;
    }
    else if(x>0)return true;
    return false;
}

void ConvexHull(int n,int* sz)        //GRAHAM'S SCAN
{
    int i,j;
    double area;

    //FINDING PEVOT POINT
    pvt=p[0];j=0;
    fii(1,n)if(p[i].y<pvt.y){pvt=p[i];j=i;}
    else if(fabs(p[i].y-pvt.y)<ERR && p[i].x<pvt.x) {pvt=p[i];j=i;}
    p[j] = p[0]; p[0] = pvt;

    sort(&p[1],&p[n],comp);

    //GRAHAM'S SCAN
    j=1;
    fii(2,n){
        while(CROSS(p[j-1],p[j],p[j],p[i])<0)
        //if(CROSS(p[j-1],p[j],p[j],p[i])<0)
            j--;
        p[++j] = p[i];
    }

    *sz=j;
}

int main(){
    int t=1,i,n,sz,j;
    double perimeter,x;
    //freopen("in.in","r",stdin);

    while(scanf("%d",&n)==1 && n)
    {
        rii(n)  scanf("%lf%lf",&p[i].x,&p[i].y);
        sz=n-1;
        if(n>2) ConvexHull(n,&sz);

        if(t-1)   printf("\n");

        printf("Region #%d:\n",t++);
        printf("(%.1lf,%.1lf)",p[0].x,p[0].y);

        n = sz;
        rdi(sz)printf("-(%.1lf,%.1lf)",p[i].x,p[i].y);

        //CALCULATING PEREMETER:
        if(n>1)
        {
            p[++n] = p[0];n++;
            perimeter = 0;
            fii(1,n)
                perimeter+=sqrt(pow(p[i-1].x-p[i].x,2)+pow(p[i-1].y-p[i].y,2));
        }
        else if(n == 1 )
            perimeter = 2*sqrt(pow(p[1].x-p[0].x,2)+pow(p[1].y-p[0].y,2));
        else perimeter = 0 ;
        printf("\nPerimeter length = %.2lf\n",perimeter);
    }
    return 0;
}


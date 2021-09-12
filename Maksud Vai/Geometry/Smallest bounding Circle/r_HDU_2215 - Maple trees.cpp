#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>

using namespace std;

const double pi=2.*acos(0);
typedef int LL;
typedef struct{LL x,y;
void scan(){scanf("%d%d",&x,&y);}
void print(){printf("x:%d y:%d\n",x,y);}
}P;

P MV(P a,P b){b.x-=a.x;b.y-=a.y;return b;}
LL C(P a,P b){return a.x*b.y-a.y*b.x;}
LL D(P a,P b){return a.x*b.x+a.y*b.y;}
double ABS(P a){return sqrt(a.x*a.x+a.y*a.y);}

P p[102],pvt;

bool com(P a,P b)
{
    LL c=C(MV(pvt,a),MV(pvt,b));
    if(c<0) return false;
    else if(c>0)    return true;
    return ABS(MV(pvt,a)) < ABS(MV(pvt,b));
}

int ConvexHull(int n)
{
    if(n==1)    return 1;
    pvt=p[0];
    int i,j;
    for(i=0;i<n;i++)
        if(p[i].y < pvt.y)  pvt = p[i];
        else if(pvt.y==p[i].y && p[i].x<pvt.x)  pvt=p[i];
    sort(p,p+n,com);
    j=1;
    for(i=2;i<n;i++)
    {
        while(C(MV(p[j-1],p[j]),MV(p[j-1],p[i]))<=0 && j>0)
            j--;
        p[++j] = p[i];
    }
    return j+1;
}

double TRI(P a,P b,P c)
{
    double j;
    j = acos((double)D(MV(a,b),MV(a,c))/(ABS(MV(a,b))*ABS(MV(a,c))));
    return ABS(MV(b,c))/(2.*sin(j));
}

double Applet_s_Algorithm(int n)
{
    int i,j=2,a=0,b=1,k=0;
    double ma,J;

    while(true)
    {
        ma=2*pi;
        for(i=0;i<n;i++)
            if(i!=a && i!=b)
            {
                J = acos((double)D(MV(p[i],p[b]),MV(p[i],p[a]))/(ABS(MV(p[i],p[b]))*ABS(MV(p[i],p[a]))));
                if(J<ma)
                {
                    ma=J;
                    j=i;
                }
            }
        i=j;
        if(D(MV(p[i],p[a]),MV(p[i],p[b]))<=0)
            return ABS(MV(p[a],p[b]))/2.;
        else if( D(MV(p[a],p[i]),MV(p[a],p[b])) > 0 && D(MV(p[b],p[i]),MV(p[b],p[a])) > 0)
            return TRI(p[i],p[a],p[b]);
        else if(D(MV(p[a],p[i]),MV(p[a],p[b])) <=0)
            a=i;
        else if(D(MV(p[b],p[i]),MV(p[b],p[a])) <=0)
            b=i;
    }
}

int main()
{
    //freopen("in.in","r",stdin);
    LL i,j,k,n,m;
    double ret;

    while(scanf("%d",&n)==1 && n )
    {
        for(i=0;i<n;i++)    p[i].scan();
        ret=0.5;
        n = ConvexHull(n);
        if(n==2)    ret += ABS(MV(p[0],p[1]))/2.;
        else  if(n>2)   ret+=Applet_s_Algorithm(n);
        printf("%.2lf\n",ret);
    }

    return 0;
}

/*
INPUT:
------
2
1 0
-1 0

3
1 0
0 1
1 1

1
0 0

8
0 5
0 -5
3 3
2 2
1 1
0 0
-5 0
4 0
OUTPUT:
-------
1.50
1.21
0.50
5.50

*/



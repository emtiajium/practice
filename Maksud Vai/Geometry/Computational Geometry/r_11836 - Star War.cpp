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

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

using namespace std;

template<class T>T sqr(T a){return a*a;}
const double OO=9e10;
const double ERR=1e-6;
typedef double CDT;
typedef struct{CDT x,y,z;}P;
P MV(P a,P b){P r; r.x=b.x-a.x; r.y=b.y-a.y; r.z=b.z-a.z; return r;}
CDT D(P a,P b){ return a.x*b.x+a.y*b.y+a.z*b.z;}
P C(P a,P b){P r; r.x=a.y*b.z-a.z*b.y; r.y=a.z*b.x-a.x*b.z; r.z=a.x*b.y-a.y*b.x; return r;}
double ABS(P a){return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);}
P VADD(P a,P b){a.x+=b.x;a.y+=b.y;a.z+=b.z;return a;}
P VSUB(P a,P b){a.x-=b.x;a.y-=b.y;a.z-=b.z;return a;}
P VMUL(P a,double mm){a.x*=mm;a.y*=mm;a.z*=mm;return a;}

P p[8];

double dist3D_Segment_to_Segment(P p1,P p2,P p3,P p4)
{
    const double SMALL_NUM = 0.00000001;
    P u = MV(p1,p2);
    P v = MV(p3,p4);
    P w = MV(p3,p1);
    double    a = D(u,u);        // always >= 0
    double    b = D(u,v);
    double    c = D(v,v);        // always >= 0
    double    d = D(u,w);
    double    e = D(v,w);
    double    D = a*c - b*b;       // always >= 0
    double    sc, sN, sD = D;      // sc = sN / sD, default sD = D >= 0
    double    tc, tN, tD = D;      // tc = tN / tD, default tD = D >= 0

    // compute the line parameters of the two closest points
    if (D < SMALL_NUM) { // the lines are almost parallel
        sN = 0.0;        // force using point P0 on segment S1
        sD = 1.0;        // to prevent possible division by 0.0 later
        tN = e;
        tD = c;
    }
    else {                // get the closest points on the infinite lines
        sN = (b*e - c*d);
        tN = (a*e - b*d);
        if (sN < 0.0) {       // sc < 0 => the s=0 edge is visible
            sN = 0.0;
            tN = e;
            tD = c;
        }
        else if (sN > sD) {  // sc > 1 => the s=1 edge is visible
            sN = sD;
            tN = e + b;
            tD = c;
        }
    }

    if (tN < 0.0) {           // tc < 0 => the t=0 edge is visible
        tN = 0.0;
        // recompute sc for this edge
        if (-d < 0.0)
            sN = 0.0;
        else if (-d > a)
            sN = sD;
        else {
            sN = -d;
            sD = a;
        }
    }
    else if (tN > tD) {      // tc > 1 => the t=1 edge is visible
        tN = tD;
        // recompute sc for this edge
        if ((-d + b) < 0.0)
            sN = 0;
        else if ((-d + b) > a)
            sN = sD;
        else {
            sN = (-d + b);
            sD = a;
        }
    }

    sc = (fabs(sN) < SMALL_NUM ? 0.0 : sN / sD);
    tc = (fabs(tN) < SMALL_NUM ? 0.0 : tN / tD);

    P   dP = VADD(w, VSUB(VMUL(u,sc),VMUL(v,tc)) );
    return ABS(dP);
}


double Segment_to_Point_Distance(P a,P b,P c){
    if(D(MV(a,b),MV(a,c))<0)    return ABS(MV(a,c));
    if(D(MV(b,a),MV(b,c))<0)    return ABS(MV(b,c));
    return ABS(C(MV(a,b),MV(a,c)))/ABS(MV(a,b));
}

bool Same_Side(P plane,P a,P b,P c,P d){
    P ab = MV(a,b),np;
    np=C(ab,plane);
    return (D(np,MV(a,c))*D(np,MV(a,d))) >= 0;
}

double Plane_to_Point_Distance(P a,P b,P c,P d){
    double m=OO;
    m<?=Segment_to_Point_Distance(a,b,d);
    m<?=Segment_to_Point_Distance(a,c,d);
    m<?=Segment_to_Point_Distance(b,c,d);

    P plane=C(MV(a,b),MV(a,c));
    if(Same_Side(plane,a,b,c,d) && Same_Side(plane,b,c,a,d) && Same_Side(plane,a,c,b,d))
    {
        P ad=MV(a,d);
        double x,y;
        y=ABS(ad);
        x=D(plane,ad)/ABS(plane);
        m <?= fabs(x);
    }
    return m;
}

double CD(P a[],P b[]){
    int i,j,k,l;
    double m =OO;
    for(i=0;i<4;i++)
        for(j=i+1;j<4;j++)
            for(k=j+1;k<4;k++)
                for(l=0;l<4;l++)
                    m<?=Plane_to_Point_Distance(a[i],a[j],a[k],b[l]);

    for(i=0;i<4;i++)
        for(j=i+1;j<4;j++)
            for(k=0;k<4;k++)
                for(l=k+1;l<4;l++)
                    m<?=dist3D_Segment_to_Segment(a[i],a[j],b[k],b[l]);

    return m;
}

int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.in","w",stdout);
    int tst,i;
    scanf("%d",&tst);

    while(tst--)
    {
        for(i=0;i<8;i++)    scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
        printf("%.2lf\n",min(CD(p,&p[4]),CD(&p[4],p))+1e-8);
    }
    return 0;
}


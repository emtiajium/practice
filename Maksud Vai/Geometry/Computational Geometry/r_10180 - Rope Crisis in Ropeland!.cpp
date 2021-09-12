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
template<class T>T sqr(T a) {return a*a;}

typedef long long LL;typedef vector<string>VS;typedef vector<int>VI;typedef vector<double>VD;typedef vector<long long>VLL;

int main(){
    double a,b,c,fa,fb,ta,tb,t,f,ca,cb,x1,x2,y1,y2,r,rr,ab,xl,yl,cros1,cros2,vd;
    int T;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&r);

        a = y1-y2;
        b = x2-x1;
        c = x1*y2 - x2*y1;
        ab = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
        vd = fabs(c/sqrt(a*a+b*b));
        xl = -c*a/(a*a+b*b);

        if( fabs(a) > ERR )	yl = b*xl/a;
        else	yl = -(a*xl+c)/b;
        cros1 = xl*y1-yl*x1;
        cros2 = xl*y2-yl*x2;

        if( (cros1*cros2<0 || ( fabs(c) < ERR && (b*x1 - a*y1)*(b*x2 - a*y2)<0 )) && vd<r )
        {
            ca = sqrt(pow(x1,2)+pow(y1,2));
            cb = sqrt(pow(x2,2)+pow(y2,2));
            fa = sqrt(ca*ca-r*r);
            fb = sqrt(cb*cb-r*r);
            ta = acos(r/ca);tb = acos(r/cb);
            t = acos((ca*ca +cb*cb -ab*ab)/(2*ca*cb)) - ta-tb;
            f = fa+fb+r*t;
            printf("%.3lf\n",f);
        }
        else printf("%.3lf\n",ab);


    }
    return 0;
}


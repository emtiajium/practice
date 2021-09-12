#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;
const double TOLL=1e-9;
struct point{ double x,y; point(double xx=0,double yy=0){x=xx;y=yy;} };
double dist(point a,point b){return sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) ); }
bool operator<(const point& a,const point& b){if(fabs(a.x-b.x)>TOLL) return a.x+TOLL<b.x; return a.y+TOLL<b.y;}
/* Ax+By=C, draws line ab */
struct line{ double x,y, A,B,C; line(point a,point b){ x=b.x-a.x, y=b.y-a.y; A=b.y-a.y; B=a.x-b.x; C=A*a.x+B*a.y;} line(){/*EMPTY*/} };
double cross(line a, line b) { return a.x*b.y-b.x*a.y; }
double cross(point a, point b) { return a.x*b.y-b.x*a.y; }
double dot(line a,line b) { return a.x*b.x+a.y*b.y; }

point line_intersection(line ab,line cd)
{
    double x=-1e100,y=x;
    double det = ab.A*cd.B - cd.A*ab.B;
    if(det == 0)
    {
        //Lines are parallel
    }
    else
    {
        x = (cd.B*ab.C - ab.B*cd.C)/det;
        y = (ab.A*cd.C - cd.A*ab.C)/det;
    }
    return point(x,y);
}

line perpendicular(line a, point ref) { line rv; rv.A=-a.B; rv.B=a.A; rv.C=rv.A*ref.x+rv.B*ref.y; return rv; }
struct circle{point cen; double radius; circle(point cc,double r){cen=cc; radius=r;} };

circle from2points(point a,point b)
{
    point cen; cen.x=(a.x+b.x)/2; cen.y=(a.y+b.y)/2; double rad=dist(cen, a);
    return circle(cen,rad);
}

circle from3points(point a,point b,point c)
{
    point midab; midab.x=(a.x+b.x)/2; midab.y=(a.y+b.y)/2;
    point midbc; midbc.x=(b.x+c.x)/2; midbc.y=(b.y+c.y)/2;
    line ab(a,b), bc(b,c);
    if(fabs(cross(ab,bc) )<TOLL)
    {
        vector<point> tmp; tmp.push_back(a); tmp.push_back(b); tmp.push_back(c);
        sort(tmp.begin(),tmp.end());
        return from2points(tmp[0],tmp[2]);
    }
    line first=perpendicular(ab,midab), second=perpendicular(bc,midbc);
    point cen=line_intersection(first,second);
    double r=dist(cen,a);
    circle rv(cen,r);
    return rv;
}

bool insidecircle(circle g,point t) { double d=dist(g.cen,t); if(d>g.radius+TOLL) return false; return true; }

circle smallestEnclosingCircle(vector<point>& p)
{
    random_shuffle(p.begin(),p.end());
    circle rv=from2points(p[0],p[1]);
    for(int i=2;i<p.size();i++) if(!insidecircle(rv,p[i]))
    {
        rv=from2points(p[0],p[i]);
        for(int j=1;j<i;j++) if(!insidecircle(rv,p[j]))
        {
            rv=from2points(p[j],p[i]);
            for(int k=0;k<j;k++) if(!insidecircle(rv,p[k])) rv=from3points(p[i],p[j],p[k]);
        }
    }
    return rv;
}

vector<point> v;
int main()
{
    int t; scanf("%d",&t);
    while(t--)
    {
        int n; scanf("%d",&n); v.resize(n);
        for(int i=0;i<n;i++) scanf("%lf %lf",&v[i].x,&v[i].y);
        circle rv=smallestEnclosingCircle(v);
        printf("%.2lf\n%.2lf %.2lf\n",rv.radius,rv.cen.x,rv.cen.y);
    }

    return 0;
}






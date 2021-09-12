struct P
{
    double x,y;
    P(double xa=0,double ya=0):x(xa),y(ya){}
    void scan(){scanf("%lf%lf",&x,&y);}
};

P MV(P a,P b){return P(b.x-a.x,b.y-a.y);}
double CP(P a,P b){return a.x*b.y-a.y*b.x;}
double DP(P a,P b){return a.x*b.x+a.y*b.y;}
double VA(P a){return sqrt(DP(a,a));}
P VL(P a,double l){double v=VA(a);return P(a.x*l/v,a.y*l/v);}
P VR(P a,double t){return P(a.x*cos(t)-a.y*sin(t),a.x*sin(t)+a.y*cos(t));}
double sqr(double a){return a*a;}
double Dis(P a,P b){return VA(MV(a,b));}
P VAdd(P a,P b){return P(a.x+b.x,a.y+b.y);}
double Angle(P a,P b){return acos(DP(a,b)/VA(a)/VA(b));}

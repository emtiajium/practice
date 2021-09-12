///Vector 3D

typedef double type;
struct P{
    type x,y,z;
    P(type xi=0,type yi=0,type zi=0):x(xi),y(yi),z(zi){};
    void scan(){scanf("%lf%lf%lf",&x,&y,&z);}
    //void scan(){cin>>x>>y>>z;}
};


double Abs(P a){return sqrt(sqr(a.x)+sqr(a.y)+sqr(a.z));}
P MV(P a,P b){return P(b.x-a.x,b.y-a.y,b.z-a.z);}
double DP(P a,P b){return a.x*b.x+a.y*b.y+a.z*b.z;}
P CP(P a,P b){return P(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);}
P Add(P a,P b){return P(a.x+b.x,a.y+b.y,a.z+b.z);}
P U(P a){double l = Abs(a);return P(a.x/l,a.y/l,a.z/l);}
P Rev(P a){return P(-a.x,-a.y,-a.z);}
double Angle(P a,P b){return acos(DP(a,b)/Abs(a)/Abs(b));}
double Dis(P a,P b){return Abs(MV(a,b));}
P LV(P a,double l){a=U(a);return P(a.x*l,a.y*l,a.z*l);}

/**
    3D Rotation
    a and b suould be Unit Vector.
    th :: -180<= th <=180
*/

P Rotate(P a,P b,double th){
    double bth,tot;
    if(th>90)
    {
        th -=90;
        swap(a,b);
        b = Rev(b);
    }
    th = th/180.0*pi;
    bth=cos(th);
    th=sin(th);
    tot=th+bth;

    return U(P((a.x*bth+b.x*th)/tot,
               (a.y*bth+b.y*th)/tot,(a.z*bth+b.z*th)/tot));
}

#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

#define sqr(a)	((a)*(a))
#define ERR		1e-5
#define EQ(a,b)		fabs(a-b)<ERR

typedef struct{	double x,y,z;}P;
P c[102];
double ra[102];

P Make(P a,P b){P r; r.x = b.x - a.x; r.y = b.y - a.y; r.z = b.z - a.z; return r;}
double Abs(P a){ return sqrt(sqr(a.x)+sqr(a.y)+sqr(a.z));}
double Dot(P a,P b){return a.x*b.x+a.y*b.y+a.z*b.z;}
P Cro(P a,P b){P r;	r.x=a.y*b.z-b.y*a.z; r.y= a.z*b.x-b.z*a.x;r.z= a.x*b.y-b.x*a.y;	return r;}
P Rev(P a){P r;r.x=-a.x; r.y=-a.y; r.z=-a.z; return r;}

P FindP(P s,P c,P r,double d,double rr)
{
    double kx,ky,kz,K,A,B,C,vb,vu,K1;
    P p;
    kx = 2.*(c.x-s.x);
    ky = 2.*(c.y-s.y);
    kz = 2.*(c.z-s.z);

	K1 =  sqr(s.x)+sqr(s.y)+sqr(s.z) - sqr(c.x) - sqr(c.y) - sqr(c.z) ;
    K = sqr(d)-sqr(rr)- K1;

    A = r.y*s.z-r.z*s.y;
    B = r.x*s.y-r.y*s.x;
    C = r.z*s.x-r.x*s.z;

    if( !EQ(r.x,0.) )    {
        vb=kx+(r.y/r.x)*ky+(r.z/r.x)*kz;
        vu=K-ky*(B/r.x)+kz*(C/r.x);
        p.x = vu/vb;
        p.y=(B/r.x)+(r.y/r.x)*p.x;
        p.z = (r.z/r.x)*p.x-(C/r.x);
    }
    else if( !EQ(r.y,0.) )    {
        vb=ky+(r.x/r.y)*kx+(r.z/r.y)*kz;
        vu=K+kx*(B/r.y)-kz*(A/r.y);
        p.y = vu/vb;
        p.x=(r.x/r.y)*p.y-(B/r.y);
        p.z = (A/r.y)+(r.z/r.y)*p.y;
    }
    else    {
        vb=kz+(r.x/r.z)*kx+(r.y/r.z)*ky;
        vu=K-kx*(C/r.z)+ky*(A/r.z);
        p.z = vu/vb;
        p.y=(r.y/r.z)*p.z-(A/r.z);
        p.x = (C/r.z)+(r.x/r.z)*p.z;
    }
    return p;
}

P RefP(P a,P b)
{
	P c;
	double d,ab;

	ab = Abs(b);
	d = Dot(a,b)/ab;
	b.x *= d/ab;
	b.y *= d/ab;
	b.z *= d/ab;

    c.x = b.x*2.-a.x;
    c.y = b.y*2.-a.y;
    c.z = b.z*2.-a.z;

	return c;
}

int main()
{
	//freopen("in.in","r",stdin);
    int n,i,j,k;
	P s,v,r,p,f;
	double d,d1,d2,d3,mi;

	while(scanf("%d",&n)==1 && n)
	{
		scanf("%lf%lf%lf",&s.x,&s.y,&s.z);
		for(i=0;i<n;i++)
			scanf("%lf%lf%lf%lf",&c[i].x,&c[i].y,&c[i].z,&ra[i]);
		p.x=p.y=p.z=0;
        k=1;
        j=7;
		while(k!=-1 && j--)
		{
            k=-1;
            mi = 1e8;

            for(i=0;i<n;i++)
            {
                v=Make(p,c[i]);
                d2 = Abs(Cro(v,s))/Abs(s);     //  Hight
				d1 = Dot(v,s)/Abs(s);          //  Base
                if(d2<=ra[i] && d1 > 0.)
                {
                    d = d1 - sqrt(sqr(ra[i])-sqr(d2));
                    if(d<mi)
                    {
                        mi = d;
                        k = i;
                    }
                }
            }
            if(k!=-1)
            {
                p = FindP(p,c[k],s,mi,ra[k]);
                s = RefP(Rev(s),Make(c[k],p));
            }
            else break;
		}

        printf("%.4lf %.4lf %.4lf\n",p.x,p.y,p.z);
	}
	return 0;
}

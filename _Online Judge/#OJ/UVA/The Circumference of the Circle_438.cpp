#include<stdio.h>
#include<math.h>

double x1,e1,x2,y2,x3,y3;
double g1,f1,c1,d1,g2,f2,c2,d2,g3,f3,c3,d3,circum;
double det,dx,dy,dz,x,y,z;
const double PI=3.1415926535897932384626433832795028841972;

int main()
{
    //freopen("input.txt","r",stdin);
    while(~scanf("%lf %lf %lf %lf %lf %lf",&x1,&e1,&x2,&y2,&x3,&y3))
    {
        d1=-(x1*x1+e1*e1);
        g1=2*x1;
        f1=2*e1;
        c1=1;

        d2=-(x2*x2+y2*y2);
        g2=2*x2;
        f2=2*y2;
        c2=1;

        d3=-(x3*x3+y3*y3);
        g3=2*x3;
        f3=2*y3;
        c3=1;

        det= g1*(f2*c3-c2*f3)-f1*(g2*c3-c2*g3)+c1*(g2*f3-g3*f2);

        dx=(d1*(f2*c3-c2*f3)-f1*(d2*c3-c2*d3)+c1*(d2*f3-d3*f2));
        dy=(g1*(d2*c3-c2*d3)-d1*(g2*c3-c2*g3)+c1*(g2*d3-g3*d2));
        dz=(g1*(f2*d3-d2*f3)-f1*(g2*d3-d2*g3)+d1*(g2*f3-g3*f2));

        x=dx/det;
        y=dy/det;
        z=dz/det;
        //printf("coordinate %lf,%lf,%lf\n",x,y,z);
        circum=sqrt(x*x+y*y-z)*2.0*PI;
        printf("%.2lf\n",circum);
    }
    return 0;
}

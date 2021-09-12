#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

const double pi=2*acos(0.);
double sqr(double a){return a*a;}

int main()
{
    int a,i;
    double h1,h2,h3,h4,h5,h6,x,y,z,h,l,m,H;

    while(scanf("%lf",&z)==1 )
    {
        if(z==-1)   break;
        h = 3*z;
        l= 2.5*z;
        i=0;
        while(h>=l)
        {
            m=(h+l)/2.;
            //printf("m: %.10lf\n",m);
            if(i++==100)   break;
//            z=1000;
//            m=2640.5593003588;
            h1 = m-sqrt(m*m-z*z);
            h6 = m-sqrt(m*m-z*z/2.);
            h5 = z*sqrt(4.5);
            h2=2.*z;
            x=sqrt(m*m-sqr(h1+4.*z-m));
            if(x<2.*z){l=m;continue;}
            x-=2.*z;
            h3=z-x;
//            printf("%.10lf\n",h1+h2+h3+h5+h6);
//            printf("%.10lf\n",2*m);
            if(h1+h2+h3+h5+h6<2*m)  h=m;
            else l=m;
        }
        printf("%.10lf\n",m);
    }

    return 0;
}


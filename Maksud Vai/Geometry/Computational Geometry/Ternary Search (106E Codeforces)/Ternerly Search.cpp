#include <iostream>
#include <cstdio>
#include <cmath>

#define EPS 1e-8

using namespace std;

int n, x[100], y[100], z[100];
double p[3];

double f()
{
        double maxD = 0;
        for(int i=0; i<n; i++)
                maxD = max(maxD, (x[i]-p[0])*(x[i]-p[0]) + (y[i]-p[1])*(y[i]-p[1]) + (z[i]-p[2])*(z[i]-p[2]));
        return maxD;
}

void doit(int k)
{
        if(k < 3)
        {
                double lo = -1e4, hi = 1e4;

                for(int i=0; i<60; i++)
                {
                        double a = (2*lo + hi)/3.0, b = (lo + 2*hi)/3.0;

                        p[k] = a;
                        doit(k+1);
                        double n1 = f();

                        p[k] = b;
                        doit(k+1);
                        double n2 = f();

                        if(n1 < n2) hi = b;
                        else lo = a;
                }

                p[k] = (lo + hi)/2;
        }
}

int main()
{
        while(cin>>n)
        {
                for(int i=0; i<n; i++)
                        cin>>x[i]>>y[i]>>z[i];

                if(n==1) printf("%d %d %d\n", x[0], y[0], z[0]);
                else if(n==2) printf("%lf %lf %lf\n", (x[0] + x[1])/2.0, (y[0] + y[1])/2.0, (z[0] + z[1])/2.0);
                else
                {
                        doit(0);

                        printf("%.6lf %.6lf %.6lf\n", p[0], p[1], p[2]);
                }
        }

        return 0;
}

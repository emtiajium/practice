#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;
const double PI=3.14159265358979323846264338327950288419716939937511;
double r,dia,sha;
int t,c;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    for(c=1;c<=t;c++){
        scanf("%lf",&r);
        dia=r+r;
        sha=(dia*dia-PI*r*r)+ 1e-9 ;
        printf("Case %d: %.2lf\n",c,sha);
    }
    return 0;
}

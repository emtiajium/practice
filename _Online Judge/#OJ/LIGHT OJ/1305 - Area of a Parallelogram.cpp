#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;
//const double PI=3.14159265358979323846264338327950288419716939937511;
double ax,ay,bx,by,cx,cy,dx,dy,area;
int cases,t;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy);
        dx=(ax+cx)-bx;
        dy=(ay+cy)-by;
        area=0.5*(ax*by+bx*cy+cx*dy+dx*ay-ax*dy-dx*cy-cx*by-bx*ay);
        if(area<0) area=(-1)*area;
        printf("Case %d: %.0lf %.0lf %.0lf\n",++cases,dx,dy,area);
    }
    return 0;
}

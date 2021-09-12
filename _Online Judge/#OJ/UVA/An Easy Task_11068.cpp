#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;

int a1,a2,b1,b2,c1,c2,det,dx,dy;
double x,y;

int main()
{
    //freopen("input.txt","r",stdin);
    while(1){
        scanf("%d %d %d %d %d %d",&a1,&b1,&c1,&a2,&b2,&c2);
        if(a1==0&&b1==0&&c1==0&&a2==0&&b2==0&&c2==0) break;
        det=a1*b2-a2*b1;
        if(det==0) puts("No fixed point exists.");
        else{
            dx=(c1*b2-b1*c2);
            dy=(c2*a1-a2*c1);
            x=(double)dx/(double)det;
            y=(double)dy/(double)det;
            printf("The fixed point is at %.2lf %.2lf.\n",x,y);
        }
    }
    return 0;
}

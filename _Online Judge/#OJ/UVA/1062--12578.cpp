#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
const double PI=acos(-1.0);
int t;
double x,y,z,red,green;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%lf",&x);
        y=(6.0*x)/10.0;
        z=y/3.0;
        red=PI*z*z;
        green=x*y-red;
        printf("%.2lf %.2lf\n",red,green);
    }
    return 0;
}

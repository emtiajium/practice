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
using namespace std;
const double PI=2*acos(0.0);
int n,cases;
double z,p,q,ap,ac,rad2;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d%lf",&n,&ap)&&n>2){
        //spec
        z=n;
        p=ap/(0.5*z);
        q=360/z;
        q=(PI*q)/180.0;
        q=sin(q);
        rad2=p/q;
        ac=PI*rad2;
        printf("Case %d: %.5lf ",++cases,ac-ap);
        //offi
        p=ap/z;
        q=180/z;
        q=(PI*q)/180.0;
        q=tan(q);
        rad2=p/q;
        ac=PI*rad2;
        printf("%.5lf\n",ap-ac);
    }
    return 0;
}

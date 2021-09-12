#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;

const double PI=2*acos(0.0), ACC=1e-12;
double a,b,c,S,area;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    while(scanf("%lf%lf%lf",&a,&b,&c)==3){
        if(fabs(a-ACC)<=ACC || fabs(b-ACC)<=ACC || fabs(c-ACC)<=ACC)
            puts("The radius of the round table is: 0.000");
        else{
            S=(a+b+c)/2.0;
            area=sqrt(S*(S-a)*(S-b)*(S-c));
            printf("The radius of the round table is: %.3lf\n",area/S);
        }
    }
    return 0;
}

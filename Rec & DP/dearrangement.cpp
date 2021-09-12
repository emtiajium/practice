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
//const double PI=3.14159265358979323846264338327950288419716939937511;

long long dp[25]={1,0,1};
long long n;
long long dearr(long long n){
    if(n<3) return (n-1);
    if(dp[n]!=0) return dp[n];
    dp[n]=(n-1)*(dearr(n-1)+dearr(n-2));
    return dp[n];
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    dearr(22);
    while(scanf("%lld",&n)==1){
        printf("%lld\n",dp[n]);
    }
    return 0;
}

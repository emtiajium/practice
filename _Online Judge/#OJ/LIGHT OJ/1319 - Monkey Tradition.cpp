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
int t,cases;
long long n,B,i,X,temp,tt;
long long p[14],r[14];
long long bigmod(long long b,long long p,long long m){
    if(b==1) return 1;
    long long r=1;
    while(p){
        if(p&1) r=(r*b)%m;
        b=(b*b)%m;
        p=p>>1;
    }
    return r;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        for(i=0,B=1;i<n;i++){
            scanf("%lld%lld",&p[i],&r[i]);
            B*=p[i];
        }
        for(i=X=0;i<n;i++){
            tt=B/p[i];
            temp=tt%p[i];
            X+=tt*bigmod(temp,p[i]-2,p[i])*r[i];
        }
        X=X%B;
        printf("Case %d: %lld\n",++cases,X);
    }
    return 0;
}

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
//const double PI=3.14159265358979323846264338327950288419716939937511;
long long cases,c[4],i,d,X,y;
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
    //freopen("input.txt","r",stdin);//input.in
    //freopen("output.txt","w",stdout);//output.out
    while(scanf("%lld%lld%lld%lld",&c[1],&c[2],&c[3],&d)==4){
        if(c[1]==-1 && c[2]==-1 && c[3]==-1 && d==-1) break;
        long long phi[]={0,22,12,20};
        long long p[]={0,23,28,33};
        long long b[]={0,924,759,644};
        for(i=1,X=0;i<=3;i++){
            X+=b[i]*bigmod(b[i]%p[i],phi[i]-1,p[i])*c[i];
        }
        X=X%21252;// all solutions are X+B*t; t>0
        if(X==0) X=X+21252;
        y=X-d;
        if(y<0){
            X=X+21252;
            y=X-d;
        }
        if(y==0) y=21252;
        printf("Case %lld: the next triple peak occurs in %lld days.\n",++cases,y);
    }
    return 0;
}
/*
210 44 270 348
152 37 4 148
365 290 231 89
365 365 365 365
364 364 364 364
363 363 363 363
1 1 1 1
-1 -1 -1 -1
*/

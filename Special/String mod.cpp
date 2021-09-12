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
char num[1005];
long long bigmod(long long ,long long,long long);
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long long base,mod,deci,res,p,i,m,sum,emti,k;
    while(scanf("%s %lld",num,&base)==2){
        res=0;
        p=strlen(num)-1;
        for(i=0;num[i];i++){
            res+=bigmod(10,p,base)*((num[i]-48)%base);
            res%=base;
            p--;
        }
        res%=base;
        printf("%lld\n",res);
    }
    return 0;
}
long long bigmod(long long b,long long p,long long m){
    long long r=1;
    while(p!=0){
        if(p%2==1) r=(r*b)%m;
        b=(b*b)%m;
        p/=2;
    }
    return r;
}

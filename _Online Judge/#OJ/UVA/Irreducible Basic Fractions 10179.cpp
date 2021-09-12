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
const int SIZE=1000005;
bool flag[SIZE]={1,1},xlag;
int prime[78502]={2};
int i,j,r,cnd;
long long n;
double ans;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=3;i<1001;i+=2){
        r=i+i;
        if(flag[i]==false){
            for(j=i*i;j<SIZE;j+=r)
                flag[j]=true;
        }
    }
    for(i=3,j=1;i<SIZE;i+=2){
        if(flag[i]==false) prime[j++]=i;
    }
    while(scanf("%lld",&n)&&n){
        if(n==1){
            puts("1");
            continue;
        }
        cnd=sqrt(n)+1;
        ans=n;
        for(j=0;prime[j]<cnd&&n!=1;j++){
            xlag=false;
            while(n%prime[j]==0){
                n/=prime[j];
                xlag=true;
            }
            if(xlag) ans*=(1.0-1.0/(double)prime[j]);
        }
        if(n>1) ans*=(1.0-1.0/(double)n);
        printf("%lld\n",(long long)ans);
    }
    return 0;
}

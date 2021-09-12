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
bool flag[46352]={true,true};
int prime[4795]={2};
int t,cases,i,j,r,cnd;
long long sum,n,m;

long long bigmod(long long b,long long p){
    if(b==1) return 1;
    long long r=1;
    while(p){
        if(p&1) r=(r*b)%1000000007;
        b=(b*b)%1000000007;
        p=p>>1;
    }
    return r;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=3;i<216;i+=2){
        if(flag[i]==false){
            r=i<<1;
            for(j=i*i;j<46352;j+=r)
                flag[j]=true;
        }
    }
    for(i=3,j=1;i<46352;i+=2){
        if(flag[i]==false) prime[j++]=i;
    }
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&n,&m);
        cnd=sqrt(n)+1;
        sum=1;
        for(i=0;n!=1&&prime[i]<cnd;i++){
            flag[0]=false;
            r=0;
            while(n%prime[i]==0){
                n/=prime[i];
                flag[0]=true;
                r++;
            }
            if(flag[0]){
                sum*=bigmod(prime[i],r*m + 1)-1;
                if(sum<0) sum=(sum+2000000014)%1000000007;
                else if(sum>0) sum=sum%1000000007;
                sum*=bigmod(prime[i]-1,1000000005);//inverse mod
                sum=sum%1000000007;
            }
        }
        if(n>1){
            sum*=(bigmod(n,m+1)-1);
            if(sum<0) sum=(sum+2000000014)%1000000007;
            else if(sum>0)sum=sum%1000000007;
            sum*=bigmod(n-1,1000000005);
            sum=sum%1000000007;
        }
        sum=sum%1000000007;
        printf("Case %d: %lld\n",++cases,sum);
    }
    return 0;
}

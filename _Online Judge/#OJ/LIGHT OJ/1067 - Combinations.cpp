#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int t,cases,n,r;
long long res;
long long fact[1000005]={1};

long long bigmod(long long b,long long p=1000001){
    if(b==1) return 1;
    long long r=1;
    while(p){
        if(p&1) r=((r%1000003)*(b%1000003))%1000003;
        b=((b%1000003)*(b%1000003))%1000003;
        p=p>>1;
    }
    return r;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(n=1;n<1000001;n++)
        fact[n]=((fact[n-1]%1000003)*(n%1000003))%1000003;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&r);
        res=(fact[r]*fact[n-r]);
        res=((fact[n]%1000003)*bigmod(res))%1000003;
        printf("Case %d: %lld\n",++cases,res);
    }
    return 0;
}

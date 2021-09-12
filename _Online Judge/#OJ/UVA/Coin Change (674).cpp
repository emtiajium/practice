#include <bits/stdc++.h>
using namespace std;

//const double PI=2*acos(0.0);
const int SIZE=7491;
typedef long long LL;
#define SLL(a) scanf("%lld",&a)
#define PLL(a) printf("%lld",a)

int coin[]={50,25,10,5,1},dp[7][SIZE];
int t,cases,make;

int cchng(int i,int amount){
    if(i>=5){
        if(amount==0) return 1;
        return 0;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];
    int ret=0,ret2;
    if(amount-coin[i]>=0) ret=cchng(i,amount-coin[i]);
    ret2=cchng(i+1,amount);
    dp[i][amount]=ret+ret2;
    return dp[i][amount];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&make)==1){
        printf("%d\n",cchng(0,make));
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
using namespace std;

//const double PI=2*acos(0.0);
typedef long long LL;
#define SLL(a) scanf("%lld",&a)
#define PLL(a) printf("%lld",a)

int coin[53],use[53],visited[53];
LL dp[53][1003];
int t,cases,n,k,MOD=100000007;

LL cchng(int i,int amount){
    if(i>=n){
        if(amount==0) return 1;
        return 0;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];
    LL ret=0,ret2;
    //if(use[i]>=0 && amount-coin[i]>=0){
    if(visited[i]<=use[i] && amount-coin[i]>=0){
        //use[i]--;
        visited[i]++;
        ret=cchng(i,amount-coin[i])%MOD;
    }
    ret2=cchng(i+1,amount)%MOD;
    dp[i][amount]=(ret+ret2)%MOD;
    return dp[i][amount];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    scanf("%d",&t);
    while(t--){
        memset(dp,-1,sizeof(dp));
        memset(visited,0,sizeof(visited));
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%d",&coin[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&use[i]);
        printf("Case %d: ",++cases);
        PLL(cchng(0,k)%MOD); puts("");
    }
    return 0;
}

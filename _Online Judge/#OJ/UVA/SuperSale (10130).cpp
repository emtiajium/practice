#include <bits/stdc++.h>
using namespace std;

//const double PI=2*acos(0.0);
const int SIZE=1005;
typedef long long LL;
#define SLL(a) scanf("%lld",&a)
#define PLL(a) printf("%lld",a)

int price[SIZE],weight[SIZE],dp[SIZE][35];
int t,cases,i,n,q,cp,ans;

int sack(int i,int w){
    if(i==n) return 0;
    if(dp[i][w]!=-1) return dp[i][w];
    int profit,profit2;
    if(w-weight[i]>=0) profit=price[i]+sack(i+1,w-weight[i]);
    else profit=0;
    profit2=sack(i+1,w);
    dp[i][w]=max(profit,profit2);
    return dp[i][w];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d",&price[i],&weight[i]);
        }
        scanf("%d",&q);
        ans=0;
        memset(dp,-1,sizeof(dp));
        while(q--){
            scanf("%d",&cp);
            ans+=sack(0,cp);
        }
        printf("%d\n",ans);
    }
    return 0;
}

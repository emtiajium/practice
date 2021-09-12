#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
long long way[10005],coin[105];
int t,cases,n,k,i,j,x;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        way[0]=1;
        for(i=0;i<n;i++)
            scanf("%lld",&coin[i]);

        for(i=0;i<n;i++){
            for(j=coin[i];j<=k;j++){
                x=j-coin[i];
                way[j]+=way[x]%100000007;
            }
        }
        printf("Case %d: %lld\n",++cases,way[k]%100000007);
        memset(way,0,sizeof(way));
        //memset(coin,0,sizeof(coin));
    }
    return 0;
}

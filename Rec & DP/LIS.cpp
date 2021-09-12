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

//const double PI=2*acos(0.0);
const int SIZE=1005;
int n;
int value[SIZE]={-2147483647};
int dp[SIZE],dir[SIZE];

int longest(int u){
    int high=0,v;
    if(dp[u]!=-1) return dp[u];
    for(v=u+1;v<=n;v++){
        if(value[v]>value[u]){
            if(longest(v)>high){
                high=longest(v);
                dir[u]=v;
            }
        }
    }
    dp[u]=1+high;
    return dp[u];
}

void print_LIS(int u){
    printf("%d\n",value[u]);
    if(dir[u]==-1) return;
    print_LIS(dir[u]);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    memset(dp,-1,sizeof dp);
    memset(dir,-1,sizeof dir);
    int LIS=0,start,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&value[i]);
    }
    for(i=1;i<=n;i++){
        int mm=longest(i);
        if(mm>LIS){
            LIS=mm;
            start=i;
        }
        printf("longest path from %d: %d\n",i,longest(i));
    }
    printf("%d\n\n",LIS);
//    for(i=0;i<=n;i++) printf("%d %d\n",value[i],dir[i]);
    print_LIS(start);
    return 0;
}

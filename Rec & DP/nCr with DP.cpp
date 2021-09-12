#include<stdio.h>
#include<string.h>
int ncr(int,int);
int a,b,p;
int dp[100][100];
int main()
{
    memset(dp,-1,sizeof(dp));
    while(scanf("%d%d",&a,&b)==2){
        p=ncr(a,b);
        printf("%d\n",p);
    }
    return 0;
}
int ncr(int n,int r){
    if(r==0||r==n) return 1;
    else if(r==1) return n;
    if(dp[n][r]!=-1) return dp[n][r];
    else {
        dp[n][r]=ncr(n-1,r-1)+ncr(n-1,r);
        return dp[n][r];
    }
}

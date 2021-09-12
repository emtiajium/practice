#include<stdio.h>
#include<math.h>
#include<string.h>
int ncr(int,int);
int GCD( int,int);
int n,i,j,cnd,coun,C,gcd,arr[32770];
double PI;
int dp[32770][4];
int main()
{
    while(scanf("%d",&n)&&n){
        C=ncr(n,2);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        cnd=n-1;
        coun=0;
        for(i=0;i<cnd;i++){
            for(j=i+1;j<n;j++){
                gcd=GCD(arr[i],arr[j]);
                if(gcd==1) coun++;
            }
        }
        if(coun==0) puts("No estimate for this data set.");
        else{
            PI=sqrt(6.0*C/coun);
            printf("%.6lf\n",PI);
        }
    }
    return 0;
}
int ncr(int n,int r){
    if(r==0||r==n) return 1;
    else if(r==1) return n;
    if(dp[n][r]!=0) return dp[n][r];
    else {
        dp[n][r]=ncr(n-1,r-1)+ncr(n-1,r);
        return dp[n][r];
    }
}
int GCD( int first, int second)
{
    int mod ;
    while( second != 0 ){
        mod = first % second ;
        first=second;
        second=mod;
    }
    return first;
}

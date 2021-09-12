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
const int SIZE=107;
char prin[SIZE][SIZE],str[SIZE],str2[SIZE];
int dp[SIZE][SIZE];
int m,n,i,j;
void lcs(int m,int n){
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(str[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                prin[i][j]='D';
            }
            else if(dp[i-1][j]>=dp[i][j-1]){
                dp[i][j]=dp[i-1][j];
                prin[i][j]='U';
            }
            else{
                dp[i][j]=dp[i][j-1];
                prin[i][j]='L';
            }
        }
    }
}
void print(int m,int n){
    if(m==0 || n==0) return;
    if(prin[m][n]=='D'){
        print(m-1,n-1);
        putchar(str[m-1]);
    }
    else if(prin[m][n]=='U') print(m-1,n);
    else print(m,n-1);
}
int main()
{
    freopen("input.txt","r",stdin);//input.in
    //freopen("output.txt","w",stdout);//output.out
    while(scanf("%s%s",str,str2)==2){
        m=strlen(str);
        n=strlen(str2);
        lcs(m,n);
        print(m,n);
        puts("");
        memset(dp,0,sizeof(dp));
        memset(prin,NULL,sizeof(prin));
    }
    return 0;
}
/*
emths emxythzs
springtime printing
person compression
compression person
*/

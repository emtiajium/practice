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
int dp[SIZE][SIZE];
char str[SIZE],str2[SIZE];
int p,q,i,len;

int lcs(int m,int n){
    //printf("(%d, %d)\n",m,n);
    if(m==p || n==q) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    if(str[m]==str2[n]) dp[m][n]=lcs(m+1,n+1)+1;
    else{
        int x=lcs(m+1,n);
        int y=lcs(m,n+1);
        dp[m][n]=max(x,y);
    }
    return dp[m][n];
}

void print_lcs(int m,int n){
    //printf("\n(%d, %d) ",m,n);
    if(m==p || n==q) return;
    if(dp[m][n]==dp[m+1][n+1]+1 && str[m]==str2[n]){ //str[m]==str2[n] দরকার আছে,  springtime printing ইনপুট দিয়ে দেখ।
        putchar(str[m]);
        print_lcs(m+1,n+1);
    }
    else if(dp[m][n]==dp[m][n+1]) print_lcs(m,n+1);
    else print_lcs(m+1,n);
}

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%s%s",str,str2)==2){
        printf("%s %s\n",str,str2);
        memset(dp,-1,sizeof(dp));
        p=strlen(str);
        q=strlen(str2);
        for(i=0;i<=q;i++) dp[p][i]=0;
        for(i=0;i<=p;i++) dp[i][q]=0; // দরকার আছে,  emths emxythzs ইনপুট দিয়ে দেখ।
        len=lcs(0,0);
        /*for(int i=0;i<=p;i++){
            for(int j=0;j<=q;j++){
                printf("%2d ",dp[i][j]);
            }
            puts("");
        }*/
		print_lcs(0,0);
        printf(" %d\n",len);
    }
    return 0;
}
/*
emths emxythzs
springtime printing
person compression
compression person
*/

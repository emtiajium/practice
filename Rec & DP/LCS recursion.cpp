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
bool visited[SIZE][SIZE];
char str[SIZE],str2[SIZE];
int m,n,len;

int lcs(int m,int n){
    //printf("%d %d\n",m,n);
    if(m==-1 || n==-1) return 0;
    if(visited[m][n]==true) return dp[m][n];
    else{
        visited[m][n]=true;
        if(str[m]==str2[n]) dp[m][n]=lcs(m-1,n-1)+1;
        else dp[m][n]=max(lcs(m,n-1),lcs(m-1,n));
        return dp[m][n];
    }
}

void print_lcs(int m,int n){
    //printf("%d %d\n",m,n);
    if(m==-1 || n==-1) return;
    if(dp[m][n]==dp[m-1][n-1]+1 && str[m]==str2[n]){
        print_lcs(m-1,n-1);
        putchar(str[m]);
    }
    else if(dp[m][n]==dp[m][n-1]) print_lcs(m,n-1);
    else print_lcs(m-1,n);
}

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%s%s",str,str2)==2){
        printf("%s %s\n",str,str2);
        m=strlen(str);
        n=strlen(str2);
        len=lcs(m-1,n-1);
		/*for(int i=0;i<m;i++){
			for(int j=0;j<n;j++)
				printf("%d ",dp[i][j]);
			puts("");
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++)
				cout<<visited[i][j]<<" ";
			puts("");
		}*/
        print_lcs(m-1,n-1);
        printf(" %d\n",len);
        memset(visited,false,sizeof(visited));
    }
    return 0;
}
/*
emths emxythzs
springtime printing
person compression
compression person
*/

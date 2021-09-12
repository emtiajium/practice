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

const int SIZE=103;
int dp[SIZE][SIZE];
bool visited[SIZE][SIZE];
int arr[SIZE],arr2[SIZE];
int cases,i,m,n,len;

int lcs(int m,int n){
    if(m==-1 || n==-1) return 0;
    if(visited[m][n]==true) return dp[m][n];
    visited[m][n]=true;
    if(arr[m]==arr2[n]) dp[m][n]=lcs(m-1,n-1)+1;
    else dp[m][n]=max(lcs(m,n-1),lcs(m-1,n));
    return dp[m][n];
}

void print_lcs(int m,int n){
    if(m==-1 || n==-1) return;
    if(dp[m][n]==dp[m-1][n-1]+1 && arr[m]==arr2[n]){
        print_lcs(m-1,n-1);
        //cout<<arr[m]<<" ";
    }
    else if(dp[m][n]==dp[m][n-1]) print_lcs(m,n-1);
    else print_lcs(m-1,n);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    while(scanf("%d%d",&m,&n)){
        if(!m && !n) break;
        for(i=0;i<m;i++) scanf("%d",&arr[i]);
        for(i=0;i<n;i++) scanf("%d",&arr2[i]);
        len=lcs(m-1,n-1);
		print_lcs(m-1,n-1);
		printf("Twin Towers #%d\n",++cases);
        printf("Number of Tiles : %d\n",len);
        puts("");
        memset(visited,false,sizeof(visited));
    }
    return 0;
}

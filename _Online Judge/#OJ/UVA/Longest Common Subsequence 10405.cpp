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
const int SIZE=1007;
int dp[SIZE][SIZE];
bool visited[SIZE][SIZE];
char str[SIZE],str2[SIZE];
int m,n,len;

int lcs(int m,int n){
    if(m==-1 || n==-1) return 0;
    if(visited[m][n]==true) return dp[m][n];
    else{
        visited[m][n]=true;
        if(str[m]==str2[n]) dp[m][n]=lcs(m-1,n-1)+1;
        else dp[m][n]=max(lcs(m,n-1),lcs(m-1,n));
        return dp[m][n];
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(gets(str)){
        gets(str2);
        m=strlen(str);
        n=strlen(str2);
        len=lcs(m-1,n-1);
        printf("%d\n",len);
        memset(visited,false,sizeof(visited));
    }
    return 0;
}

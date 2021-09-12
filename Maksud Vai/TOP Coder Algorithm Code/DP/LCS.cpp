//Longest Common Subsequence(LCS)
#include <iostream>
#include <string>
using namespace std;
#define SIZE 100

int LCS(string str1,string str2);
int main()
{
    string str1,str2;
    int len;

    while(cin>>str1>>str2)
    {
        len=LCS(str1,str2);
        printf("%d\n",len);
    }
}
int LCS(string str1,string str2)
{
    int dp[SIZE][SIZE],i,j;

    str1=" "+str1;
    str2=" "+str2;
    for(i=0;i<str1.size();i++)
        dp[i][0]=0;
    for(i=0;i<str2.size();i++)
        dp[0][i]=0;
    for(i=1;i<str1.size();i++)
    {
        for(j=1;j<str2.size();j++)
            if(str1[i]==str2[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    }
    return dp[i-1][j-1];
}

/*
Input:
BDCABA
ABCBDAB
Output:
lcs:4
*/

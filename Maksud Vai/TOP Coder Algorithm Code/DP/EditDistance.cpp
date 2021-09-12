//Edit Distance
#include <iostream>
#include <string>

using namespace std;

int EditDistance(string str1,string str2)
{
    int i,j,cost,dp[100][100];
    str1=" "+str1;
    str2=" "+str2;
    for(i=0;i<str1.size();i++)
        dp[i][0]=i;
    for(j=0;j<str2.size();j++)
        dp[0][j]=j;

    for(i=1;i<str1.size();i++)
        for(j=1;j<str2.size();j++)
        {
            if(str1[i]==str2[j])
                dp[i][j]=dp[i-1][j-1];
            else
            {
                dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1);
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    //deletion dp[i-1][j]+1
    //insertion dp[i][j-1]+1
    //substitution dp[i-1][j-1]+1
    return dp[i-1][j-1];
}
/*
kitten
sitting
3
Saturday
Sunday
3
*/

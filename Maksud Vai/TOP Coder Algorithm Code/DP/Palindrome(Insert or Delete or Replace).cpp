#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 1010
#define INF 1000000

int dp[SIZE][SIZE];

int Palindrome(string str);

int main()
{
    char s[SIZE];
    string str;
    int val,test,Case=1;

    scanf("%d",&test);
    getchar();
    while(test--)
    {
        gets(s);
        str=s;
        val=Palindrome(str);
        printf("Case %d: %d\n",Case++,val);
    }
    return 0;
}

int Palindrome(string str)
{
    int i,j,minv;

    for(i=0;i<str.size();i++)
    {
        for(j=0;j<str.size();j++)
        {
            dp[i][j]=INF;
        }
    }
    dp[0][str.size()-1]=0;
    minv=INF;
    for(i=0;i<str.size();i++)
    {
        for(j=str.size()-1;j>-1;j--)
        {
            if(i>=j)    //this is one solution
            {
                minv=min(minv,dp[i][j]);
            }
            else
            {
                if(str[j]==str[i])
                {
                    dp[i+1][j-1]=min(dp[i][j],dp[i+1][j-1]);
                }
                else
                {
                    dp[i][j-1]=min(dp[i][j]+1,dp[i][j-1]);//Insert or Delete
                    dp[i+1][j]=min(dp[i][j]+1,dp[i+1][j]);//Insert or Delete
                    dp[i+1][j-1]=min(dp[i][j]+1,dp[i+1][j-1]);//Replace
                }
            }
        }
    }
    return minv;
}


//Ugly Number Generator
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 2147483647

vector<int> Generate(vector<int>num);

int main()
{
    int n,val,i;
    vector<int>num,dp;

    while(scanf("%d",&n)==1)
    {
        num.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d",&val);
            num.push_back(val);
        }
        dp=Generate(num);
        printf("SIZE:%d %d\n",dp.size(),dp[1499]);
    }
    return 0;
}

vector<int> Generate(vector<int>num)
{
    vector<int>dp;
    int i,j,n,high;
    dp.push_back(1);

    for(i=0;i<num.size();i++)
    {
        high=dp.size();
        n=num[i];
        while(n<MAX)
        {
            for(j=0;j<high;j++)
            {
                if(dp[j]>MAX/n)
                    continue;
                dp.push_back(dp[j]*n);
            }
            if(n>MAX/num[i])
                break;
            n=n*num[i];
        }
    }
    sort(dp.begin(),dp.end());
    return dp;
}
/*
Input:
3
2 3 5
Output:
The 1500'th Ugly Number Is:859963392
*/

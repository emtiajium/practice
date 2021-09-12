//SubSetSum Generate by DP
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int SubSetSum(vector<int>num);
int main()
{
    int n,val,i;
    vector<int>num;

    while(scanf("%d",&n)==1)
    {
        num.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d",&val);
            num.push_back(val);
        }
        SubSetSum(num);
    }
    return 0;
}
int SubSetSum(vector<int>num)
{
    int i,j,high;
    vector<int>dp;

    dp.push_back(0);
    for(i=0;i<num.size();i++)
    {
        high=dp.size();
        for(j=0;j<high;j++)
            dp.push_back(num[i]+dp[j]);
    }
    for(i=0;i<dp.size();i++)
        printf("%d ",dp[i]);
    printf("\n");
}
/*
input & Output:
3
2 3 5
0 2 3 5 5 7 8 10        ->output
*/

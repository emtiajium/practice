#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

#define SIZE 100

typedef struct
{
    int cost,weight;
}knapsack;

int dp[SIZE][SIZE];

int _01knapsack(vector<knapsack>P,int MW);

int main()
{
    int n,i,cost,weight,val,MaxWeight;
    vector<knapsack>P;

    while(scanf("%d",&n)==1)
    {
        P.clear();
        knapsack Q;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&weight,&cost);
            Q.cost=cost;
            Q.weight=weight;
            P.push_back(Q);
        }
        scanf("%d",&MaxWeight);
        val=_01knapsack(P,MaxWeight);
        printf("Maximum Cost:%d\n",val);
    }
    return 0;
}

int _01knapsack(vector<knapsack>P,int MW)
{
    int i,j,len;

    len=P.size();
    for(i=0;i<=MW;i++)
        dp[0][i]=0;
    for(i=0;i<=len;i++)
        dp[i][0]=0;

    for(i=0;i<len;i++)
    {
        for(j=1;j<=MW;j++)
        {
            if(P[i].weight>j)
                dp[i+1][j]=dp[i][j];
            else dp[i+1][j]=max(dp[i][j],dp[i][j-P[i].weight]+P[i].cost);
        }
    }
    return dp[len][MW];
}
/*
Input:
4
2 3
3 4
4 5
5 6
5
Output:
Maximum Cost: 7
*/

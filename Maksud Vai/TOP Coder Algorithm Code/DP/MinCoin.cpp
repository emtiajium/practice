#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000

int MinCoin(vector<int>coin,int N);

int main()
{
	int i,n,val;
	vector<int>coin;

	while(scanf("%d",&n)==1)
	{
		coin.clear();
		for(i=0;i<n;i++)
		{
			scanf("%d",&val);
			coin.push_back(val);
		}
		scanf("%d",&val);
		val=MinCoin(coin,val);
		cout<<"Minimum Coin:"<<val<<endl;
	}
	return 0;
}

int MinCoin(vector<int>coin,int N)
{
	vector<int>DP(++N,INF);//Increment Of N Then Initialize By INF
	int i,j;

	DP[0]=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<coin.size();j++)
		{
			if(coin[j]<=i && DP[i-coin[j]]+1<DP[i])
			{
				DP[i]=DP[i-coin[j]]+1;
			}
		}
	}
	return DP[N-1];
}

/*
	Input:			Output:
	3				Minimum Coin:3
	1 3 5				Minimum Coin:2
	11				Minimum Coin:3
	3
	1 3 5
	8
	3
	1 3 5
	7
*/

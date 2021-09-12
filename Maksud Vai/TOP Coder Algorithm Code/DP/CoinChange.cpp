#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int CoinChange(vector<int>coin,int N);

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
		val=CoinChange(coin,val);
		cout<<"The Total Coin Change:"<<val<<endl;
	}

	return 0;
}

int CoinChange(vector<int>coin,int N)
{
	vector<int>DP(++N,0);// First increment then Initialize By 0
	int i,j;

	DP[0]=1;
	for(i=0;i<coin.size();i++)
	{
		for(j=0;j<N;j++)
		{
			if(j-coin[i]>=0)
			{
				DP[j]+=DP[j-coin[i]]; // Be careful in the Integer Range. Because the value is Huge
			}
		}
	}
	return DP[N-1];
}
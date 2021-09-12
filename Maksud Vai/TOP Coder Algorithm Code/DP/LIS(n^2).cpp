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

int LIS(vector<int>data);
int max_element(vector<int>DP);

int main()
{
	int n,i,val;
	vector<int>Data;

	while(scanf("%d",&n)==1 && n)
	{
		Data.clear();
		for(i=0;i<n;i++)
		{
			scanf("%d",&val);
			Data.push_back(val);
		}
		val=LIS(Data);
		printf("LIS:%d\n",val);
	}

	return 0;
}

int LIS(vector<int>Data)
{
	int i,j;
	vector<int>DP(Data.size(),1); //Initialize By 1

	for(i=1;i<Data.size();i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(Data[j]<=Data[i] && DP[j]+1>DP[i])
			{
				DP[i]=DP[j]+1;
			}
		}
	}
	return max_element(DP);
}

int max_element(vector<int>DP)
{
	int i,max;

	for(i=max=0;i<DP.size();i++)
	{
		if(DP[i]>max)
		{
			max=DP[i];
		}
	}
	return max;
}
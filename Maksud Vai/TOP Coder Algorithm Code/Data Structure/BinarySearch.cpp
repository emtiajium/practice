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
#include <queue>

using namespace std;

int BinarySearch(vector<int>data,int item);

int main()
{
	int i,n,temp,item,ind;
	vector<int>data;

	while(scanf("%d",&n)==1)
	{
		data.clear();
		for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			data.push_back(temp); //data should be sorted
		}
		scanf("%d",&item);
		ind=BinarySearch(data,item);
		if(ind==-1)
		{
			printf("Don't Match\n");
		}
		else
		{
			printf("index:%d\n",ind);
		}
	}
	return 0;
}

int BinarySearch(vector<int>data,int item)
{
	int low,high,mid;

	low=0;
	high=data.size();
	while(low<=high)
	{
		mid=(low+high)/2;
		if(data[mid]==item)
		{
			return mid;
		}
		else if(data[mid]<item)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	return -1;
}
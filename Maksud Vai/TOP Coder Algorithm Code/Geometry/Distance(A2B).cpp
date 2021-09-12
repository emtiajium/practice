//Using TOP Coder Tutorials
//A,B are Two points. We find The Distance Betwee A and B.

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

double Distance(vector<int>A,vector<int>B);

int main()
{
	vector<int>A,B;
	int x,y;
	double val;

	scanf("%d %d",&x,&y);
	A.push_back(x);
	A.push_back(y);

	scanf("%d %d",&x,&y);
	B.push_back(x);
	B.push_back(y);

	val=Distance(A,B);

	cout<<"Distance:"<<val<<endl;
	return 0;
}

double Distance(vector<int>A,vector<int>B)
{
	vector<int>dist;

	dist.push_back(A[0]-B[0]);
	dist.push_back(A[1]-B[1]);

	return sqrt(dist[0]*dist[0]+dist[1]*dist[1]);
}
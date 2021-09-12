//Minimum Distance Between C point And AB Line. If line Then Easy But
//When it is segment Then compute shortest distance

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

double LineToPoint(vector<int>A,vector<int>B,vector<int>C,bool IsSegment);
double Distance(vector<int>A,vector<int>B);
int CrossProd(vector<int>A,vector<int>B,vector<int>C);
int DotProd(vector<int>A,vector<int>B,vector<int>C);

int main()
{
	vector<int>A,B,C;
	int x,y;
	double val;

	scanf("%d %d",&x,&y);
	A.push_back(x);
	A.push_back(y);
	
	scanf("%d %d",&x,&y);
	B.push_back(x);
	B.push_back(y);

	scanf("%d %d",&x,&y);
	C.push_back(x);
	C.push_back(y);

	val=LineToPoint(A,B,C,true);

	cout<<"Minimum Distance:"<<val<<endl;
	
	return 0;
}

int DotProd(vector<int>A,vector<int>B,vector<int>C)
{
	vector<int>AB,BC;	

	AB.push_back(B[0]-A[0]);
	AB.push_back(B[1]-A[1]);
	BC.push_back(C[0]-B[0]);
	BC.push_back(C[1]-B[1]);
	
	int DOT=AB[0] * BC[0] + AB[1] * BC[1];
	return DOT;
}

int CrossProd(vector<int>A,vector<int>B,vector<int>C)
{
	vector<int>AB,AC;	

	AB.push_back(B[0]-A[0]);
	AB.push_back(B[1]-A[1]);
	AC.push_back(C[0]-A[0]);
	AC.push_back(C[1]-A[1]);
	
	int cross = AB[0] * AC[1] - AB[1] * AC[0];
    return cross;
}

double Distance(vector<int>A,vector<int>B)
{
	vector<int>dist;

	dist.push_back(A[0]-B[0]);
	dist.push_back(A[1]-B[1]);

	return sqrt(dist[0]*dist[0]+dist[1]*dist[1]);
}

double LineToPoint(vector<int>A,vector<int>B,vector<int>C,bool IsSegment)
{
	double dist=CrossProd(A,B,C)/Distance(A,B);

	if(IsSegment)
	{
		int dot1=DotProd(A,B,C);

		if(dot1>0)
			return Distance(B,C);

		int dot2=DotProd(B,A,C);

		if(dot2>0)
			return Distance(A,C);
	}
	return fabs(dist);
}
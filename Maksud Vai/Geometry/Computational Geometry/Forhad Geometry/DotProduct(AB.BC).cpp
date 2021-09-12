//Using TOP Coder Tutorials
//A,B,C are three points. We find The Dot Product Of AB.BC=?

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

int DotProd(vector<int>A,vector<int>B,vector<int>C);

int main()
{
	vector<int>A,B,C;
	int x,y,val;

	scanf("%d %d",&x,&y);
	A.push_back(x);
	A.push_back(y);

	scanf("%d %d",&x,&y);
	B.push_back(x);
	B.push_back(y);

	scanf("%d %d",&x,&y);
	C.push_back(x);
	C.push_back(y);

	val=DotProd(A,B,C);

	printf("Dot Product:%d\n",val);
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
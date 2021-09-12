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

int DotProd(vector<int>A,vector<int>B,vector<int>C,vector<int>D);

int main()
{
	vector<int>A,B,C,D;
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

	scanf("%d %d",&x,&y);
	D.push_back(x);
	D.push_back(y);

	val=DotProd(A,B,C,D);

	printf("Dot Product:%d\n",val);
	return 0;
}

int DotProd(vector<int>A,vector<int>B,vector<int>C,vector<int>D)
{
	vector<int>AB,CD;	

	AB.push_back(B[0]-A[0]);
	AB.push_back(B[1]-A[1]);
	CD.push_back(D[0]-C[0]);
	CD.push_back(D[1]-C[1]);
	
	int DOT=AB[0] * CD[0] + AB[1] * CD[1];
	return DOT;
}
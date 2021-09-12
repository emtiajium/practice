//Using TOP Coder Tutorials
//A,B,C are three points. We find The Cross Product Of ABxAC=?

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

int CrossProd(vector<int>A,vector<int>B,vector<int>C);

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

	val=CrossProd(A,B,C);

	printf("Cross Product:%d\n",val);
	return 0;
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
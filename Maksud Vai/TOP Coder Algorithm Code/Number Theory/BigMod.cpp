/*
	This is the Big Mod Code. Format: (B^P)%M
*/
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

int BigMod(int B,int P,int M);

int main()
{
	int B,P,M,val;

	while(scanf("%d %d %d",&B,&P,&M)==3)
	{
		val=BigMod(B,P,M);
		printf("%d\n",val);
	}

	return 0;
}

int BigMod(int B,int P,int M)
{
	int R=1;
	while(P>0)
	{
		if(P%2==1)
		{
			R=(R*B)%M;
		}
		P/=2;
		B=(B*B)%M;
	}
	return R;
}
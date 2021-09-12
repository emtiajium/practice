#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define SIZE 1000

int longestMatch(string sequence1, string sequence2);

int main()
{
    string str1,str2;
    int val;

    while(cin>>str1>>str2)
    {
        val=longestMatch(str1,str2);
        cout<<val<<endl;
    }
}

int longestMatch(string sequence1, string sequence2)
{
	int i,j,len1,len2,max;
	vector<int>dp[SIZE];

	len1=sequence1.size();
	len2=sequence2.size();

	for(i=0;i<=len1;i++)
	{
		for(j=0;j<=len2;j++)
		{
			dp[i].push_back(0);
		}
	}

	for(i=max=0;i<len1;i++)
	{
		for(j=0;j<len2;j++)
		{
			if(sequence2[j]==sequence1[i])
			{
				dp[i+1][j+1]=dp[i][j]+1;
				if(dp[i+1][j+1]>max)
					max=dp[i+1][j+1];
			}
		}
	}
	return max;
}

/*
Input:
algorithms
algebra

maksudhossainshibly
fouziasultanatasnova

Output:
3
2
*/

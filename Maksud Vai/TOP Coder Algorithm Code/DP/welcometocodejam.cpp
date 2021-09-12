#include <iostream>
#include <vector>
using namespace std;

char str[]="welcome to code jam";

int google(string str1);

int main()
{
	string str;
	int val,test,Case=1;

	scanf("%d\n",&test);
	while(test--)
	{
		getline(cin,str);
		val=google(str);
		printf("Case #%d: %04d\n",Case++,val);
	}
	return 0;
}

int google(string str1)
{
	vector<int>dp[510];
	int i,j;

	for(i=0;i<=20;i++)
	{
		for(j=0;j<=str1.size();j++)
		{
			dp[i].push_back(0);
		}
	}
	for(i=0;i<=str1.size();i++)
	{
		dp[0][i]=1;
	}
	for(i=0;i<19;i++)
	{
		for(j=0;j<str1.size();j++)
		{
			if(str[i]==str1[j])
			{
				dp[i+1][j+1]=(dp[i+1][j]+dp[i][j+1])%10000;
			}
			else dp[i+1][j+1]=dp[i+1][j];
		}
	}
	return dp[19][str1.size()];
}
/*
3
elcomew elcome to code jam
wweellccoommee to code qps jam
welcome to codejam
Case #1: 0001
Case #2: 0256
Case #3: 0000
*/

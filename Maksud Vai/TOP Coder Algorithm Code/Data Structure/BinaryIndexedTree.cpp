#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <utility>
#include <map>
#include <list>
#include <set>

using namespace std;

vector<int>f,tree;

void build_BIT();
void update(int ind,int val);
int read(int ind);

int main()
{
    int n,i,query,k,l,val,sum,sum1,sum2;

    f.clear();
    tree.clear();
    f.push_back(0);
    tree.push_back(0);

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&val);
        f.push_back(val);
    }

    build_BIT();

    while(scanf("%d",&query)==1)
    {
        if(query==1)
        {
            scanf("%d %d",&i,&val);
            update(i,val);
        }
        if(query==0)
        {
            //return cum. sum between index 1 to k-1
            //return cum. sum between index 1 to l
            //ans difference between
            scanf("%d %d",&k,&l);
            sum1=read(k-1);
            sum2=read(l);
            sum=sum2-sum1;
            printf("%d\n",sum);
        }
    }
    return 0;
}

void build_BIT()
{
    int i,j,count,sum;

    for(i=1;i<f.size();i++)
    {
        count=0;
        j=i;
        while(j%2!=1)
        {
            count++;
            j/=2;
        }
        sum=0;
        for(j=i+1-(1<<count);j<=i;j++)
            sum+=f[j];
        tree.push_back(sum);
    }
}

void update(int ind,int val)
{
    while (ind<tree.size())
    {
		tree[ind]+=val;
		ind += (ind & -ind);
	}
}

int read(int ind)
{
	int sum = 0;

	while (ind > 0)
	{
		sum+=tree[ind];
		ind -= (ind & -ind);
	}
	return sum;
}

/*
Input Output:

16
1 0 2 1 1 3 0 4 2 5 2 2 3 1 0 2
1 1 4
0 1 1
5
0 16 16
2
0 1 16
33
*/

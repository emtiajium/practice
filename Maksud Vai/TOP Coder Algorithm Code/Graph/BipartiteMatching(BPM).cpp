#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>

using namespace std;

#define SIZE 100
#define NILL -1

bool BPM(int u);

vector<int>adj[SIZE];
int Par[SIZE],Color[SIZE];

int main()
{
    int nodes,edges,i,u,v,count;

    while(scanf("%d %d",&nodes,&edges)==2)
    {
    	for(i=0;i<nodes;i++)
    		adj[i].clear();
        for(i=0;i<edges;i++)
        {
        	scanf("%d %d",&u,&v);
        	adj[u].push_back(v);
        }
        count=0;
        memset(Par,NILL,sizeof(Par));
        for(i=0;i<nodes;i++)
        {
        	memset(Color,true,sizeof(Color));
         	if(BPM(i))   
          		count++;
        }
        printf("Maximum Bipartite Matching: %d\n",count);
    }
    return 0;
}

bool BPM(int u)
{
    int i,v;

    for(i=0;i<adj[u].size();i++)
    {
    	v=adj[u][i];
        if(Color[v])
        {
            Color[v] = false;
            if(Par[v]==NILL || BPM(Par[v]))
            {
                Par[v] = u;
                return true;
            }
        }
    }
    return false;
}
/*
Input:
6 4
0 5
1 5
2 4
0 3
Output:
3
Input:
6 3
0 5
1 5
2 4
Output:
2
*/

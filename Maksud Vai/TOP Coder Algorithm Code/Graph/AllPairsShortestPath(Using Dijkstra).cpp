//Total Complexit n^2(logn)

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

#define SIZE 100
#define INF 100000

struct pq
{
	int cost,node;
	bool operator<(const pq &b)const
	{
		return cost>b.cost; // Min Priority Queue
	}
};

vector<pq>adj[SIZE];

vector<int> Dijkstra(int source,int nodes);

int main()
{
	int nodes,edges,i,u,v,cost,source,destination;
	pq V;
	vector<int>dp[SIZE];

	while(scanf("%d %d",&nodes,&edges)==2)
	{
		for(i=0;i<nodes;i++)
		{
			adj[i].clear(); //clear adj vector
			dp[i].clear();
		}
		for(i=0;i<edges;i++)
		{
			scanf("%d %d %d",&u,&v,&cost);
			V.cost=cost;
			V.node=v;
			adj[u].push_back(V);
			V.node=u;				//For Bidirectional Edges
			adj[v].push_back(V);
		}
		for(i=0;i<nodes;i++)
		{
			dp[i]=Dijkstra(i,nodes);
		}
		for(i=0;i<nodes;i++)
		{
            for(int j=0;j<nodes;j++)
            {
                printf("%7d ",dp[i][j]);
            }
            cout<<endl;
        }
		scanf("%d %d",&source,&destination);
		cout<<"Cost:"<<dp[source][destination]<<endl;  // Not Possible When Value==INF
	}

	return 0;
}

vector<int> Dijkstra(int source,int nodes)
{
	priority_queue<pq>Q;
	vector<int>dist;
	pq U,V;
	int i,u,v,cost;
	
	for(i=0;i<nodes;i++)
	{
		dist.push_back(INF);
	}
	dist[source]=0;
	V.node=source;
	V.cost=0;
	Q.push(V);
	while(!Q.empty())
	{
		U=Q.top();
		u=U.node;
		Q.pop();
		for(i=0;i<adj[u].size();i++)
		{
			v=adj[u][i].node;
			cost=adj[u][i].cost;
			if(dist[u]+cost<dist[v])
			{
				dist[v]=dist[u]+cost;
				V.node=v;
				V.cost=dist[v];
				Q.push(V);
			}
		}
	}
	return dist;
}

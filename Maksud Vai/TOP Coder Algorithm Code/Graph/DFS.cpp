#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

#define SIZE 100000
#define INF 1000000
#define NILL -1
#define white 1
#define gray 2
#define black 3

vector<int> DFS(vector<int>adj[],int source,int nodes);

int main()
{
    int i,u,v,nodes,edges,source;
    vector<int>adj[SIZE];

    while(scanf("%d %d",&nodes,&edges)==2)
    {
        vector<int>dis(nodes);

        for(i=0;i<nodes;i++)
            adj[i].clear();
        for(i=0;i<nodes;i++)
        {
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
        }
        scanf("%d",&source);
        dis=DFS(adj,source,nodes);

        for(i=0;i<nodes;i++)
        {
            if(dis[i]!=INF)
                printf("Dis node %d From %d : %d\n",i,source,dis[i]);
            else printf("Dis node %d From %d : INF\n",i,source);
        }
    }
    return 0;
}

vector<int> DFS(vector<int>adj[],int source,int nodes)
{
    vector<int>dis(nodes,INF),par(nodes,NILL),color(nodes,white);
    int i,u,v;
    stack<int>S;

    dis[source]=0;
    par[source]=NILL;
    color[source]=gray;
    S.push(source);

    while(!S.empty())
    {
        u=S.top();
        S.pop();

        for(i=0;i<adj[u].size();i++)
        {
            v=adj[u][i];
            if(color[v]==white)
            {
                dis[v]=dis[u]+1;
                par[v]=u;
                S.push(v);
            }
        }
        color[u]=black;
    }
    return dis;
}

/*
    Input:
    4 4
    0 1
    0 2
    1 3
    2 1
    0
    Output:
    Dis node 0 From 0 : 0
    Dis node 1 From 0 : 2
    Dis node 2 From 0 : 1
    Dis node 3 From 0 : 3
    Input:
    4 4
    0 1
    0 2
    2 1
    1 3
    2
    Output:
    Dis node 0 From 2 : INF
    Dis node 1 From 2 : 1
    Dis node 2 From 2 : 0
    Dis node 3 From 2 : 2

*/

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

#define SIZE 10000
#define INF 1000000
#define NILL -1
#define white 0			//white: Undiscovered
#define black 1			//black: Finished

vector<int>adj[SIZE],Dis(SIZE),Par(SIZE),Color(SIZE);

void BFS(int source,int nodes);

int main()
{
    int i,u,v,nodes,edges,source;

    while(scanf("%d %d",&nodes,&edges)==2)
    {
        for(i=0;i<nodes;i++)
            adj[i].clear();
        for(i=0;i<nodes;i++)
        {
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
        }
        scanf("%d",&source);
        BFS(source,nodes);

        for(i=0;i<nodes;i++)
        {
            if(Dis[i]!=INF)
                printf("Dis node %d From %d : %d\n",i,source,Dis[i]);
            else printf("Dis node %d From %d : INF\n",i,source);
        }
    }
    return 0;
}

void BFS(int source,int nodes)
{
    queue<int>Q;
    int i,u,v;

    for(i=0;i<nodes;i++)
    {
        Dis[i]=INF;
        Par[i]=NILL;
        Color[i]=white;
    }
    Dis[source]=0;
    Par[source]=NILL;
    Q.push(source);
    Color[source]=black;

    while(!Q.empty())
    {
       u=Q.front();
       Q.pop();
       for(i=0;i<adj[u].size();i++)
       {
           v=adj[u][i];
           if(Color[v]==white)
           {
               Color[v]=black;
               Dis[v]=Dis[u]+1;
               Par[v]=u;
               Q.push(v);
           }
       }
    }
}

/*
Input:
4 4
0 1
0 2
2 1
1 3
0
Output:
Dis node 0 From 0 : 0
Dis node 1 From 0 : 1
Dis node 2 From 0 : 1
Dis node 3 From 0 : 2
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

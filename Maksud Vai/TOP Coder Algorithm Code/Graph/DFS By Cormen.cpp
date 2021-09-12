#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

#define SIZE 100000
#define NILL -1
#define white 0
#define gray 1
#define black 2


vector<int>Dis(SIZE),Par(SIZE),Color(SIZE),Fin(SIZE),adj[SIZE];
int Time;

int DFS(int nodes);
void DFS_Visit(int u);

int main()
{
    int nodes,edges,i,u,v;

    while(scanf("%d %d",&nodes,&edges)==2)
    {
        for(i=0;i<nodes;i++)
            adj[i].clear();
        for(i=0;i<edges;i++)
        {
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
        }
        DFS(nodes);
        for(i=0;i<nodes;i++)
            printf("%d ",Par[i]);
        printf("\n");
    }

    return 0;
}

int DFS(int nodes)
{
    int i;

    for(i=0;i<nodes;i++)
    {
        Color[i]=white;
        Par[i]=NILL;
    }
    Time=0;
    for(i=0;i<nodes;i++)
        if(Color[i]==white)
            DFS_Visit(i);
}

void DFS_Visit(int u)
{
    int v;
    Color[u]=gray;      //White Vertex u Has just been Discovered
    Dis[u]=++Time;        //Discoverd u Vertex
    for(int i=0;i<adj[u].size();i++)
    {
        v=adj[u][i];
        if(Color[v]==white)
        {
            Par[v]=u;
            DFS_Visit(v);
        }
    }
    Color[u]=black;     //Blacken u,it is finished
    Fin[u]=++Time;
}

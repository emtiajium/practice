#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

#define SIZE 10000
#define NILL -1
#define white 1
#define gray 2
#define black 3

vector<int>adj[SIZE],Dis(SIZE),Par(SIZE),Array(SIZE),Color(SIZE),Fin(SIZE),Indeg(SIZE),Rank(SIZE);
int Time,K;

int TopologicalSort(int nodes);
int DFS(int nodes);
void DFS_Visit(int u);

int main()
{
    int i,j,nodes,edges,u,v,val;

    while(scanf("%d %d",&nodes,&edges)==2)
    {
        for(i=0;i<nodes;i++)
        {
            adj[i].clear();
            Indeg[i]=0;
            Rank[i]=1;
        }
        for(i=0;i<edges;i++)
        {
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
            Indeg[v]++;		//Indegree count
        }
        val=TopologicalSort(nodes);
        if(val)
        {
            for(i=0;i<K;i++)
                printf("%d ",Array[i]);
            printf("\n");
        }
        else printf("Impossible\n");

    }
    return 0;
}

int TopologicalSort(int nodes)
{
    int i,j;

    DFS(nodes);
    reverse(&Array[0],&Array[K]);
    for(i=0;i<K;i++)
    {
        if(Indeg[Array[i]]) //Impossible Case Check
            return 0;
        for(j=0;j<adj[Array[i]].size();j++)
        {
            Indeg[adj[Array[i]][j]]--;
            if(Rank[adj[Array[i]][j]]<=Rank[Array[i]])
                Rank[adj[Array[i]][j]]=Rank[Array[i]]+1;
        }
    }
    return 1;
}

int DFS(int nodes)
{
    int i;

    for(i=0;i<nodes;i++)
    {
        Color[i]=white;
        Par[i]=NILL;
    }
    Time=K=0;
    for(i=0;i<nodes;i++)
        if(Color[i]==white)
            DFS_Visit(i);
}

void DFS_Visit(int u)
{
    Color[u]=gray;      //White Vertex u Has just been Discovered
    Dis[u]=++Time;        //Discoverd u Vertex
    for(int i=0;i<adj[u].size();i++)
        if(Color[adj[u][i]]==white)
        {
            Par[adj[u][i]]=u;
            DFS_Visit(adj[u][i]);
        }
    Color[u]=black;     //Blacken u,it is finished
    Fin[u]=++Time;
    Array[K++]=u;		//Store the node topological sorted order but in reversely 
}

/*
Input:
4 4
0 1
0 2
1 2
2 3
Output:
0 1 2 3
Input:
9 10
0 1
2 1
3 1
4 1
2 3
3 4
5 6
6 7
4 7
5 4
Output:
8 5 6 2 3 4 7 0 1
Input:
2 2
0 1
1 0
Output:
Impossible

*/
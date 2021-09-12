#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <sstream>
#include <cmath>

using namespace std;

#define SIZE 100000
#define INF 1000000
#define NILL -1
#define white 1
#define gray 2
#define black 3

typedef struct
{
    int Time,u;
}Node;

vector<int>adj[SIZE],adjT[SIZE],Dis(SIZE),Par(SIZE),Fin(SIZE),Color(SIZE),ans[SIZE];
int Time,K;

void StronglyConnectedComponents(int nodes);
void TransposeAdjList(int nodes);
int TDFS(int nodes);
int DFS(int nodes);
void DFS_Visit(int u);
void TDFS_Visit(int u);
int comp(Node P,Node Q);

int main()
{
    int nodes,edges,u,v,i,j,Count;

    while(scanf("%d %d",&nodes,&edges)==2)
    {
        for(i=0;i<nodes;i++)
        {
            adj[i].clear();
            adjT[i].clear();
            ans[i].clear();
        }
        for(i=0;i<edges;i++)
        {
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
        }
        StronglyConnectedComponents(nodes);
        printf("Strongly Connected Components Groups:\n");
        Count=1;
        for(i=0;i<K;i++)
        {
            printf("Group No:%d\n",Count++);
            for(j=0;j<ans[i].size();j++)
                printf("%d ",ans[i][j]);
            printf("\n");
        }
    }
    return 0;
}

void StronglyConnectedComponents(int nodes)
{
    DFS(nodes);
    TransposeAdjList(nodes);
    TDFS(nodes);
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
}

void TransposeAdjList(int nodes)		//Transpose Adjacency List
{
    int i,j;

    for(i=0;i<nodes;i++)
        for(j=0;j<adj[i].size();j++)
            adjT[adj[i][j]].push_back(i);
}

int comp(Node P,Node Q)
{
    return P.Time>Q.Time;
}

int TDFS(int nodes)     // DFS for Transpose Adj List
{
    int i;

    Node P;
    vector<Node>Array(nodes);		//Sort For Finishing Times in Descending Order Because In algorithm it tells Decreases Time
    for(i=0;i<nodes;i++)
    {
        P.Time=Fin[i];
        P.u=i;
        Array[i]=P;
    }
    sort(&Array[0],&Array[i],comp);
    for(i=0;i<nodes;i++)
    {
        Color[i]=white;
        Par[i]=NILL;
    }
    Time=0;
    for(i=K=0;i<nodes;i++)
        if(Color[Array[i].u]==white)
        {
            TDFS_Visit(Array[i].u);
            K++;        //Group No Increase
        }
}
void TDFS_Visit(int u)
{
    Color[u]=gray;      //White Vertex u Has just been Discovered
    Dis[u]=++Time;        //Discoverd u Vertex
    for(int i=0;i<adjT[u].size();i++)
        if(Color[adjT[u][i]]==white)
        {
            Par[adjT[u][i]]=u;
            TDFS_Visit(adjT[u][i]);		//Be CareFull Function Call
        }
    Color[u]=black;     //Blacken u,it is finished
    ans[K].push_back(u);	//Store Member of a group
    Fin[u]=++Time;
}
/*
Input:
8 14
0 1
1 2
1 5
1 4
2 6
2 3
3 2
3 7
4 5
5 6
7 6
7 3
6 5
4 0

Output:

Strongly Connected Components Groups:
Group No:1
1 4 0
Group No:2
7 3 2
Group No:3
5 6

Input:
8 14
0 1
1 2
1 5
1 4
2 6
2 3
3 2
3 7
4 0
4 5
5 6
6 5
6 7
7 7
Output:
Strongly Connected Components Groups:
Group No:1
1 4 0
Group No:2
3 2
Group No:3
5 6
Group No:4
7
*/

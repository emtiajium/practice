#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <sstream>
#include <cmath>

using namespace std;

#define INF 1000000
#define NILL -1

typedef struct
{
    int u,v,cost;
}Node;

int BellManFord(vector<Node>Edge,int nodes,int source,int end);

int main()
{
    int nodes,edges,u,v,cost,i,source,end,val;
    vector<Node>Edge;

    while(scanf("%d %d",&nodes,&edges)==2)
    {
        Edge.clear();       //Clear Edge Vector
        Node P;
        for(i=0;i<edges;i++)
        {
            scanf("%d %d %d",&u,&v,&cost);
            P.u=u;
            P.v=v;
            P.cost=cost;
            Edge.push_back(P);
            P.v=u;      //For Bidirectional Edges
            P.u=v;
            Edge.push_back(P);
        }
        scanf("%d %d",&source,&end);
        val=BellManFord(Edge,nodes,source,end);
        if(val==-1)
            printf("Unreachable\n");
        else printf("Shortest Cost:%d\n",val);
    }

    return 0;
}

int BellManFord(vector<Node>Edge,int nodes,int source,int end)
{
    vector<int>Dis(nodes,INF),Par(nodes,NILL);
    int i,j;

    Dis[source]=0;
    for(i=0;i<nodes-1;i++)
    {
        for(j=0;j<Edge.size();j++)
        {
            if(Dis[Edge[j].v]>Dis[Edge[j].u]+Edge[j].cost)
            {
                Dis[Edge[j].v]=Dis[Edge[j].u]+Edge[j].cost;
                Par[Edge[j].v]=Edge[j].u;
            }
        }
    }
    for(i=0;i<Edge.size();i++)      //Negative Edge Cycle Detection
        if(Dis[Edge[i].v]>Dis[Edge[i].u]+Edge[i].cost)
            return -1;          //Return -1 Because Unreachable Infinity Solution

    if(Dis[end]==INF)
        return -1;         //If There Is no Negative Cycle Then Dis Vector Array
    return Dis[end];      //act as Dijkstra. all shortest  Distance From Source

}
/*
Input:
6 9
0 1 4
0 2 2
1 2 1
1 3 5
2 3 8
2 4 10
3 5 6
3 4 2
4 5 3
0 5		//source & destination
Output:
13
Input:
6 6
0 1 5
0 3 2
1 2 -2
3 4 3
4 5 1
2 5 2
0 5
Output:
Unreachable
*/

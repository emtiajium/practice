#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

#define SIZE 10000

typedef struct
{
    int u,v,cost;
}Node;

vector<int>Par(SIZE),Rank(SIZE);

int Kruskal(vector<Node>Edge,int nodes);
int comp(Node P,Node Q);
void MakeSet(int nodes);
int FindSet(int x);
void Union(int x,int y);
void Link(int x,int y);

int main()
{
    int i,u,v,nodes,edges,cost,val;
    vector<Node>Edge;

    while(scanf("%d %d",&nodes,&edges)==2)
    {
        Node P;
        Edge.clear();
        for(i=0;i<edges;i++)
        {
            scanf("%d %d %d",&u,&v,&cost);
            P.u=u;
            P.v=v;
            P.cost=cost;
            Edge.push_back(P);
        }
        val=Kruskal(Edge,nodes);
        printf("%d\n",val);
    }
    return 0;
}

int Kruskal(vector<Node>Edge,int nodes)
{
    int i,sum;

    sort(Edge.begin(),Edge.end(),comp);

    MakeSet(nodes);

    for(i=sum=0;i<Edge.size();i++)
    {
        if(FindSet(Edge[i].u)!=FindSet(Edge[i].v))
        {
            Union(Edge[i].u,Edge[i].v);
            sum+=Edge[i].cost;
        }
    }
    return sum;
}

void MakeSet(int nodes)
{
    for(int i=0;i<nodes;i++)
    {
        Par[i]=i;
        Rank[i]=i;
    }
}

int FindSet(int x)
{
    if(x!=Par[x])
        Par[x]=FindSet(Par[x]);
    return Par[x];
}

void Union(int x,int y)
{
    Link(FindSet(x),FindSet(y));
}

void Link(int x,int y)
{
    if(Rank[x]>Rank[y])
        Par[y]=x;
    else
    {
        Par[x]=y;
        if(Rank[x]==Rank[y])
            Rank[y]=Rank[y]+1;
    }
}

int comp(Node P,Node Q)
{
    if(P.cost > Q.cost)
        return false;
    return true;
}

/*
    Input:
    5 7
    0 1 5
    0 2 4
    1 2 2
    1 4 3
    2 4 1
    2 3 4
    3 4 3
    Output:
    10
*/

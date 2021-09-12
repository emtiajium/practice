#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<vector>
#include<string.h>
#include<stdio.h>
using namespace std;

#define SZ(a)   ((int)(a).size())
#define PB   push_back

const int NV = 100;

int dis[NV];
bool col[NV];
vector<int>adj[NV],cst[NV];

struct pq
{
    int w,n;

    bool operator <(const pq &b)const
    {
        return w>b.w;
    }
};

void SSSP_DIJKSTRA(int S)
{
    int i,vx,cost;

    pq u,v;
    priority_queue<pq>Q;

    memset(dis,17,sizeof dis);
    memset(col,true,sizeof col);

    u.n=S;
    u.w=dis[S] = 0;
    Q.push(u);

    while(!Q.empty())
    {
        u = Q.top();    Q.pop();

        if(!col[u.n])   continue;
        col[u.n]=false;

        for(i=0;i<SZ(adj[u.n]);i++)
        {
            vx=adj[u.n][i];
            cost=cst[u.n][i];
            if(dis[u.n] + cost <dis[vx])
            {
                v.n=vx;
                v.w=dis[vx]=dis[u.n]+cost;
                Q.push(v);
            }
        }

    }
    return ;
}

int main()
{
    //freopen("in.in","r",stdin);

    int i,j,u,v,w,S,E,V;

    /// V=number of vertex.
    /// E=number of edges.
    /// S=source.

    while(cin>>V>>E>>S)
    {
        for(i=0;i<V;i++)
        {
            adj[i].clear();
            cst[i].clear();
        }
        /// Directed Edge
        for(i=0;i<E;i++)
        {
            cin>>u>>v>>w;
            adj[u].PB(v);
            cst[u].PB(w);
        }

        SSSP_DIJKSTRA(S);

        for(i=0;i<V;i++)
            printf("Distance from source to vertex no:%d is %d\n",i,dis[i]);
    }
    return 0;
}

/*
Input:
******

5 8 0

0 1 5
0 4 100
1 2 10
1 3 100
2 3 80
2 4 7
4 3 30
3 1 3



--------
Output:
*******

Distance from source to vertex no:0 is 0
Distance from source to vertex no:1 is 5
Distance from source to vertex no:2 is 15
Distance from source to vertex no:3 is 52
Distance from source to vertex no:4 is 22

*/

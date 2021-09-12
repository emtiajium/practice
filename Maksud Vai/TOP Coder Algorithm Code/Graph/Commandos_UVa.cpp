/*
A group of commandos were assigned a critical task. They are to destroy
an enemy head quarter. The enemy head quarter consists of several buildings
 and the buildings are connected by roads. The commandos must visit each
 building and place a bomb at the base of each building. They start their
 mission at the base of a particular building and from there they disseminate
 to reach each building. The commandos must use the available roads to travel
 between buildings. Any of them can visit one building after another, but
 they must all gather at a common place when their task in done.  In this
 problem, you will be given the description of different enemy headquarters.
  Your job is to determine the minimum time needed to complete the mission.
  Each commando takes exactly one unit of time to move between buildings. You
   may assume that the time required to place a bomb is negligible. Each
   commando can carry unlimited number of bombs and there is an unlimited
   supply of commando troops for the mission.

Input
The first line of input contains a number T<50, where T denotes the number of
 test cases. Each case describes one head quarter scenario. The first line of
 each case starts with a positive integer N≤100, where N denotes the number of
  buildings in the head quarter. The next line contains a positive integer R,
  where R is the number of roads connecting two buildings. Each of the next R
  lines contain two distinct numbers,  0≤u,v<N, this means there is a road
  connecting building u to building v. The buildings are numbered from 0 to
  N-1. The last line of each case contains two integers  0≤s,d<N. Where s denotes
  the building from where the mission starts and d denotes the building where they
  must meet.
You may assume that two buildings will be directly connected by at most one road.
 The input will be such that, it will be possible to go from any building to
 another by using one or more roads.

Output
For each case of input, there will be one line of output. It will contain
the case number followed by the minimum time required to complete the mission.
Look at the sample output for exact formatting.

Sample Input                             Output for Sample Input
2
4
3
0 1
2 1
1 3
0 3
2
1
0 1
1 0
Case 1: 4
Case 2: 1
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

#define SIZE 1000

vector<int>adj[SIZE];
int Dis[SIZE],Color[SIZE],TDis[SIZE];

int commandos(int nodes,int source,int end);
void BFS(int source,int nodes);

int main()
{
    int i,test,nodes,edges,u,v,source,end,val,Case=1;

    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&nodes,&edges);
        for(i=0;i<nodes;i++)
            adj[i].clear();
        for(i=0;i<edges;i++)
        {
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);//bidirectional
        }
        scanf("%d %d",&source,&end);
        val=commandos(nodes,source,end);
        printf("Case %d: %d\n",Case++,val);
    }

    return 0;
}

int commandos(int nodes,int source,int end)
{
    int i,maxv;

    memset(Dis,0,sizeof(Dis));
    BFS(source,nodes);
    memset(TDis,0,sizeof(Dis));
    TDis[end]=Dis[end];
    Dis[end]=0;
    BFS(end,nodes);

    for(i=maxv=0;i<nodes;i++)
        maxv=max(maxv,TDis[i]);
    return maxv;
}

void BFS(int source,int nodes)
{
    queue<int>Q;
    int i,u,v;

    memset(Color,0,sizeof(Color));
    Q.push(source);
    Color[source]=1;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(i=0;i<adj[u].size();i++)
        {
            v=adj[u][i];
            if(Color[v]==0)
            {
                Color[v]=1;
                Q.push(v);
                TDis[v]=Dis[v]+Dis[u]+1;
                Dis[v]=Dis[u]+1;
            }
        }
    }
}


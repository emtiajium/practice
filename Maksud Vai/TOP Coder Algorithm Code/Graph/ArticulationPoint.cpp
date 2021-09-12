#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

#define SIZE 1000
#define NILL -1
#define white 0
#define gray 1
#define black 2

vector<int>adj[SIZE],dfsTree[SIZE],Store,Point;
int Time,Color[SIZE],Dis[SIZE],Par[SIZE],Low[SIZE],GColor[SIZE];

void ArticulationPoint(int source);
void DFS_Visit(int u);
void FindGraphNode(int u);

int main()
{
    int nodes,edges,i,j,u,v;

    while(scanf("%d %d",&nodes,&edges)==2)
    {
        for(i=0;i<=nodes;i++)
        {
            adj[i].clear();
        }
       	Point.clear();
        for(i=0;i<edges;i++)
        {
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(GColor,white,sizeof(GColor));
        for(i=0;i<nodes;i++)
        {
        	if(GColor[i]==white)
        	{
        		Store.clear();
         		FindGraphNode(i);
         		if(adj[i].size())
         		     ArticulationPoint(i);         		
   		        //else Point.push_back(i);  //Carefull only node not any child
         	}
        }
        printf("Total Articulation:%d\n",Point.size());
        for(i=0;i<Point.size();i++)
        	printf("%d ",Point[i]);
       	printf("\n");
    }
    return 0;
}

void ArticulationPoint(int source)
{
    int i,j,u,v;

    for(i=0;i<Store.size();i++)			//Clear & Set variables
    {
    	v=Store[i];
    	Color[v]=Dis[v]=white;
    	Par[v]=NILL;
    	dfsTree[v].clear();
    }
    Time=0;
    DFS_Visit(source);
    if(dfsTree[source].size()>=2)
    	Point.push_back(source);
    for(j=0;j<Store.size();j++)            //Check articulation Point
    {
    	u=Store[j];    
        if(u==source)
            continue;
        for(i=0;i<dfsTree[u].size();i++)
        {
            v=dfsTree[u][i];
            if(Low[v]>=Dis[u])
            {
                Point.push_back(u);
                break;
            }
        }
    }
}

void DFS_Visit(int u)
{
	int i,v;
	
    Color[u]=gray;      //White Vertex u Has just been Discovered
    Dis[u]=Low[u]=++Time;      //Discoverd u Vertex
    for(i=0;i<adj[u].size();i++)
    {
    	v=adj[u][i];
        if(Color[v]==white)
        {
            Par[v]=u;
            dfsTree[u].push_back(v);
            DFS_Visit(v);
            Low[u]=min(Low[u],Low[v]);
        }
        else if(v!=Par[u])
            Low[u]=min(Low[u],Dis[v]);
    }
    Color[u]=black;     //Blacken u,it is finished
}

void FindGraphNode(int u)		//If this is not only graph it's forest
{
	int i,v;
	
	GColor[u]=black;
	Store.push_back(u);
	for(i=0;i<adj[u].size();i++)
	{
 		v=adj[u][i];
 		if(GColor[v]==white)
 			FindGraphNode(v);
 	}
}

/*
Input:
4 3
0 1
1 2
2 3
Output:
Total Articulation:2
1 2
Input:
23 32
0 1
1 6
0 2
2 6
0 6
1 2
6 5
3 4
4 5
3 5
5 7
5 8
8 7
8 9
5 10
10 11
11 13
10 12
12 13
13 14
14 17
17 15
17 16
16 15
15 18
17 18
18 19
18 20
20 22
22 21
21 20
14 18
Output:
Total Arti
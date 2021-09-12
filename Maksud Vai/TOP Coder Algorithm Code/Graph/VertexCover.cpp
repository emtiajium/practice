#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>

using namespace std;

#define SIZE 100010
#define white 0
#define black 1

vector<int>adj[SIZE],Store;
int Color[SIZE];

int VertexCover(int nodes);
void DFS_Visit(int u);

int main()
{
	int test,nodes,edges,u,v,i,val;
	
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
   		}
   		val=VertexCover(nodes);
   		printf("Minimum Node For Cover This Network : %d\n",val);
 	}

	return 0;
}

int VertexCover(int nodes)
{
	int i,count;
	
	memset(Color,white,sizeof(Color));
	
	Store.clear();
	for(i=0;i<nodes;i++)
	{
 		if(Color[i]==white)
 		{
   			DFS_Visit(i);
   			Store.push_back(i);
   		}
 	}
 	reverse(Store.begin(),Store.end());
 	memset(Color,white,sizeof(Color));
 	count=0;
 	for(i=0;i<Store.size();i++)
 	{
  		if(Color[Store[i]]==white)
  		{
    		DFS_Visit(Store[i]);	//this is node which network largest
    		count++;
    	}
  	}
  	return count;
}

void DFS_Visit(int u)
{
	int i,v;
	
	Color[u]=black;
	for(i=0;i<adj[u].size();i++)
	{
 		v=adj[u][i];
 		if(Color[v]==white)
 			DFS_Visit(v);
 	}
}

/*
Input:
1
3 2
0 1
1 2
Output:
Minimum Node For Cover This Network : 1
*/

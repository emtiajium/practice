#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 2000000
#define SIZE 105
#define NILL -1

int mat[SIZE][SIZE],Par[SIZE],s,t,N,fm;
bool Color[SIZE];

int FordFulkerson();
bool AugPath();
void Make_Res(int u);

int main()
{
	int nodes,edges,i,j,u,v,cost;
	
	while(scanf("%d %d",&nodes,&edges)==2)
	{
		N=nodes;
		memset(mat,0,sizeof(mat));
		for(i=0;i<edges;i++)
		{
  			scanf("%d %d %d",&u,&v,&cost);
  			mat[u][v]=mat[v][u]=cost;
  		}
  		scanf("%d %d",&s,&t);
		printf("The Total Flow:%d\n",FordFulkerson());
	}

	return 0;
}

int FordFulkerson()
{
	int Maxflow=0;
	
	while(AugPath())
	{
		fm=INF;
		Make_Res(t);
		Maxflow += fm;
	}
	return Maxflow;
}

bool AugPath()
{
	int i,u;
	queue<int>Q;
	
	memset(Color,true,sizeof(Color));
	memset(Par,NILL,sizeof(Par));

	Q.push(s);
	Color[s]=false;

	while(!Q.empty())
	{
		u=Q.front();Q.pop();
		for(i=1;i<=N;i++)
			if(Color[i] && mat[u][i])
			{
				Par[i] = u;
				Color[i] = false;
				Q.push(i);
				if(i==t)
					return true;
			}
	}
	return false;
}

void Make_Res(int u)
{
	if(Par[u]==NILL)	return ;
	
 	fm=min(mat[Par[u]][u],fm);
	
 	Make_Res(Par[u]);
 	
  	mat[Par[u]][u] -= fm;
	mat[u][Par[u]] += fm;
}

/*
Input:
4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
1 4
Output:
The Total Flow:25
*/


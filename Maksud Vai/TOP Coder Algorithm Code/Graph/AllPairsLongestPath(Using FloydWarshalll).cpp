#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

#define SIZE 1000
#define INF 10000000

int mat[SIZE][SIZE];

void FloydWarshall(int nodes);

int main()
{
    int i,j,n,nodes,edges,u,v,cost;

    while(scanf("%d %d",&nodes,&edges)==2)
    {
        memset(mat,0,sizeof(mat));
        for(i=0;i<edges;i++)
        {
            scanf("%d %d %d",&u,&v,&cost);
            mat[u][v]=cost;//For Directed Graph
        }
        FloydWarshall(nodes);
        for(i=0;i<nodes;i++)
        {
            for(j=0;j<nodes;j++)
                printf("%d\t",mat[i][j]);
            printf("\n");
        }
    }
    return 0;
}

void FloydWarshall(int nodes)
{
    int i,j,k;

    for(k=0;k<nodes;k++)
        for(i=0;i<nodes;i++)
            for(j=0;j<nodes;j++)
                if(mat[i][k] && mat[k][j])
                    mat[i][j]=max(mat[i][j],mat[i][k]+mat[k][j]);
}

/*
Input:
6 15
0 1 2
0 2 2
0 3 2
0 4 2
0 5 2
1 2 2
1 3 2
1 4 2
1 5 2
2 3 2
2 4 2
2 5 2
3 4 2
3 5 2
4 5 2
Output:
0       2       4       6       8       10
0       0       2       4       6       8
0       0       0       2       4       6
0       0       0       0       2       4
0       0       0       0       0       2
0       0       0       0       0       0
*/

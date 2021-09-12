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
        for(i=0;i<nodes;i++)
            for(j=0;j<nodes;j++)
                if(i!=j)
                    mat[i][j]=INF;
                else mat[i][j]=0;
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
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
}

/*
Input:
5 9
0 1 3
0 2 8
0 4 -4
1 3 1
1 4 7
2 1 4
3 0 2
3 2 -5
4 3 6
Output:
0   1   -3  2   -4
3   0   -4  1   -1
7   4    0  5    3
2  -1   -5  0   -2
8   5    1  6    0
*/

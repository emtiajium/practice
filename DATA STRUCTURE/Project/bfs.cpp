#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> edge[100], cost[100];
const int infinity = 1000000000;

int bfs(int source, int destination) {

    int d[100];
    for(int i=0; i<100; i++) d[i] = infinity;

    queue<int> q;
    q.push( source );
    d[ source ] = 0;

    while( !q.empty() ) {
        int u = q.front(); q.pop();
        int ucost = d[ u ];

        for(int i=0; i<edge[u].size(); i++) {
            int v = edge[u][i], vcost = cost[ u ][i] + ucost;

            if( d[v] > vcost ) {
                d[v] = vcost;
                q.push( v );
            }
        }
    }

    return d[ destination ];
}

int main()
{
    //freopen("in.txt","r",stdin);
    int N,E,x,y,z,i,source,dest,bf;
    while(scanf("%d%d",&N,&E)==2){
        for(i=1;i<=E;i++){
            scanf("%d%d%d",&x,&y,&z);
            edge[x].push_back(y);
            edge[y].push_back(x);
            cost[x].push_back(z);
            cost[y].push_back(z);
        }
        scanf("%d%d",&source,&dest);
        bf=bfs(source,dest);
        printf("%d\n",bf);
        for(i=0;i<100;i++){
            edge[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}

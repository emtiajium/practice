#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> edge[100], cost[100];
const int infinity = 1000000000;


struct data {
    int city, dist;
    bool operator < ( const data& p ) const {
        return dist > p.dist;
    }
};

int dijkstra(int source, int destination) {

    int d[100];
    for(int i=0; i<100; i++) d[i] = infinity;
    priority_queue<data> q;
    data u, v;
    u.city = source,
    u.dist = 0;
    q.push( u );
    d[ source ] = 0;
    while( !q.empty() ) {
        u = q.top();
        q.pop();
        int ucost = d[ u.city ];
        for(int i=0; i<edge[u.city].size(); i++) {
            v.city = edge[u.city][i], v.dist = cost[u.city][i] + ucost;
            if( d[v.city] > v.dist ) {
                d[v.city] = v.dist;
                q.push( v );
            }
        }
    }

    return d[ destination ];
}

int main()
{
    //freopen("in.txt","r",stdin);
    int N,E,x,y,z,i,source,dest,dis;
    while(scanf("%d%d",&N,&E)==2){
        for(i=0;i<E;i++){
            scanf("%d%d%d",&x,&y,&z);
            edge[x].push_back(y);
            edge[y].push_back(x);
            cost[x].push_back(z);
            cost[y].push_back(z);
        }
        scanf("%d%d",&source,&dest);
        dis=dijkstra(source,dest);
        printf("%d\n",dis);
        for(i=0;i<100;i++){
            edge[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}

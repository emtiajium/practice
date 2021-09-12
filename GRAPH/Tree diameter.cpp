#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
//const double PI=3.14159265358979323846264338327950288419716939937511;
const int SIZE=105;
struct TT{
    int city,distTT;
};
struct comp{
    bool operator()(TT a,TT b){
        return a.distTT>b.distTT;
    }
};
TT u,v;
vector<int>edge[SIZE],cost[SIZE];
priority_queue< TT , vector<TT> , comp > pq;
int dist[SIZE];
int N,E,x,y,z,i,source,diam,size,ucost,high,node,node2;

void Dijkstra(int source){
    for(i=0;i<SIZE;i++) dist[i]=10000007;
    u.city=source,
    u.distTT=0;
    pq.push(u);
    dist[source]=0;
    while(!pq.empty()){
        u=pq.top();
        pq.pop();
        ucost=dist[u.city];
        size=edge[u.city].size();
        for(i=0;i<size;i++){
            v.city=edge[u.city][i];
            v.distTT=cost[u.city][i]+ucost;
            if(v.distTT<dist[v.city]){
                dist[v.city]=v.distTT;
                pq.push(v);
            }
        }
    }
}
int maxdist(){
    for(i=1,high=0;i<=N;i++){
        if(dist[i]>high){
            high=dist[i];
            node=i;
        }
    }
    return node;
}
int main()
{
    freopen("input.txt","r",stdin);//input.in
    //freopen("output.txt","w",stdout);//output.out
    while(scanf("%d%d",&N,&E)==2){
        for(i=0;i<E;i++){
            scanf("%d%d%d",&x,&y,&z);
            edge[x].push_back(y);
            edge[y].push_back(x);
            cost[x].push_back(z);// undirected
            cost[y].push_back(z);
        }
        source=1;
        Dijkstra(source);
        node=maxdist();
        memset(dist,0,sizeof(dist));
        Dijkstra(node);
        node2=maxdist();
        diam=dist[node2];
        printf("%d\n",diam);
        for(i=0;i<SIZE;i++){
            edge[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}

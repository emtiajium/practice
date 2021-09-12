#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int infinity=1000000007,SIZE=105;
struct TT{
    int city,distTT;
};
struct comp{
    bool operator()(TT a,TT b){
        return a.distTT>b.distTT;
    }
};
TT u,v;
vector<int>edge[SIZE],cost[SIZE],vct;
priority_queue<TT,vector<TT>,comp> pq;
int dist[SIZE],parent[SIZE];
int N,E,x,y,z,i,source,dest,dis,size,ucost;

void path(int s,int d){
    vct.push_back(d);
    if(parent[d]==s){
        vct.push_back(s);
        return;
    }
    path(s,parent[d]);
}
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d%d",&N,&E)==2){
        for(i=0;i<E;i++){
            scanf("%d%d%d",&x,&y,&z);
            edge[x].push_back(y);
            edge[y].push_back(x);// undirected
            cost[x].push_back(z);
            cost[y].push_back(z);
        }
        scanf("%d%d",&source,&dest);
        for(i=0;i<SIZE;i++) dist[i]=infinity;
        u.city=source;
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
                    parent[v.city]=u.city;
                    pq.push(v);
                }
            }
        }
        dis=dist[dest];
        path(source,dest);
        reverse(vct.begin(),vct.end());
        size=vct.size();
        for(i=0;i<size;i++){
            printf("%d ",vct[i]);
        }
        printf("\nDistance %d\n",dis);
        vct.clear();
        for(i=0;i<=N;i++){
            printf("%d --> %d\n",i,dist[i]);
        }
        for(i=0;i<SIZE;i++){
            edge[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}

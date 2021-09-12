#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct TT{
    int u,v,cost;
};
TT graph[10005];
int parent[105];
int t,cases,N,E,i,a,b,c,coun,low;
bool comp(TT a,TT b){
    return a.cost>b.cost;
}
int find(int a){
    if(parent[a]!=a) parent[a]=find(parent[a]);
    return parent[a];
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&N,&E);
        for(i=0;i<E;i++)
            scanf("%d%d%d",&graph[i].u,&graph[i].v,&graph[i].cost);
        sort(graph,graph+E,comp);
        for(i=0;i<=N;i++)
            parent[i]=i;
        for(i=c=coun=0,low=graph[0].cost;i<E&&coun!=N-1;i++){
            a=find(graph[i].u);
            b=find(graph[i].v);
            if(a!=b){
                c+=graph[i].cost;
                parent[b]=a;
                coun++;
                low=min(low,graph[i].cost);
            }
        }
        printf("Case #%d: %d\n",++cases,low);
    }
    return 0;
}

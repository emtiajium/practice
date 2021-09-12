#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAX=10000,minn=10000000;
struct TT{
    int u,v,cost;
};
TT graph[MAX];
int parent[MAX],arr[MAX];
int t,N,E,i,k,a,b,c,coun,c2,best;
bool comp(TT a,TT b){
    return a.cost<b.cost;
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
        for(i=1;i<=N;i++)
            parent[i]=i;
        for(i=0;i<E;i++)
            scanf("%d%d%d",&graph[i].u,&graph[i].v,&graph[i].cost);
        sort(graph,graph+E,comp);
        c=coun=0;
        for(i=0;i<E;i++){
            a=find(graph[i].u);
            b=find(graph[i].v);
            if(a!=b){
                c+=graph[i].cost;
                parent[b]=a;// parent[a]=b;
                arr[coun++]=i;
            }
        }
        best=minn;
        for(k=0;k<coun;k++){
            for(i=1;i<=N;i++)
                parent[i]=i;
            c2=coun=0;
            for(i=0;i<E;i++){
                if(i==arr[k]) continue;
                a=find(graph[i].u);
                b=find(graph[i].v);
                if(a!=b){
                    c2+=graph[i].cost;
                    parent[b]=a;// parent[a]=b;
                    coun++;
                }
            }
            if(coun!=N-1) continue;
            if(c2<best) best=c2;
        }
        if(E==1) printf("%d %d\n",c,c);
        else printf("%d %d\n",c,best);
    }
    return 0;
}

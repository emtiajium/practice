#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAX=200005;
struct TT{
    int u,v,cost;
};
TT graph[MAX];
int parent[MAX];
int N,E,i,a,b,c,sum;
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
    while(scanf("%d%d",&N,&E)&&N&&E){
        for(i=sum=0;i<E;i++){
            scanf("%d%d%d",&graph[i].u,&graph[i].v,&graph[i].cost);
            sum+=graph[i].cost;
        }
        for(i=0;i<N;i++)
            parent[i]=i;
        sort(graph,graph+E,comp);
        for(i=c=0;i<E;i++){
            a=find(graph[i].u);
            b=find(graph[i].v);
            if(a!=b){
                c+=graph[i].cost;
                parent[b]=a;// parent[a]=b;
            }
        }
        sum=sum-c;
        printf("%d\n",sum);
    }
    return 0;
}

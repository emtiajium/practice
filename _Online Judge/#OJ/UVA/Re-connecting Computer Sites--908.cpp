#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAX=1000005;
struct TT{
    int u,v,cost;
};
TT graph[MAX];
long long parent[MAX];
bool flag;
long long N,M,K,i,a,b,c,coun,sum;
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
    while(scanf("%lld",&N)==1){
        if(flag) puts("");
        flag=true;
        c=N-1;
        for(i=sum=0;i<c;i++){
            scanf("%lld%lld%lld",&graph[i].u,&graph[i].v,&graph[i].cost);
            sum+=graph[i].cost;
        }
        printf("%lld\n",sum);
        scanf("%lld",&K);
        coun=0;
        while(K--){
            scanf("%lld%lld%lld",&graph[coun].u,&graph[coun].v,&graph[coun].cost);
            coun++;
        }
        scanf("%lld",&M);
        while(M--){
            scanf("%lld%lld%lld",&graph[coun].u,&graph[coun].v,&graph[coun].cost);
            coun++;
        }
        for(i=1;i<=N;i++)
            parent[i]=i;
        sort(graph,graph+N,comp);
        c=0;
        for(i=0;i<N;i++){
            a=find(graph[i].u);
            b=find(graph[i].v);
            if(a!=b){
                c+=graph[i].cost;
                parent[b]=a;// parent[a]=b;
            }
        }
        printf("%lld\n",c);
    }
    return 0;
}

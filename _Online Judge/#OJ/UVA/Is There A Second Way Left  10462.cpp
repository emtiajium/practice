#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAX=10000,INF=10000000;
struct TT{
    int u,v,cost;
};
TT graph[MAX];
int parent[MAX],arr[MAX];
int t,cases,N,E,i,k,a,b,c,coun,c2,best,ans,ans2;
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
        ans=(coun!=N-1)?0:1;
        best=INF;
        ans2=0;
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
            else ans2++;
            if(c2<best){
                best=c2;
            }
        }
        printf("Case #%d : ",++cases);
        if(ans==0 && ans2==0) puts("No way");
        else if(ans==1 && ans2==0) puts("No second way");
        else printf("%d\n",best);
    }
    return 0;
}

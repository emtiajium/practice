#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
const int infinity=1<<30,SIZE=20005;;
struct TT{
    int city, dist;
};
struct comp{
    bool operator()(TT a,TT b){
        return a.dist>b.dist;
    }
};
TT u,v;
vector<int> edge[SIZE], cost[SIZE];
priority_queue< TT , vector<TT> , comp > pq;
int d[SIZE];
int t,cases,N,M,S,T,x,y,z,i,dis,size,ucost;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&N,&M,&S,&T);
        for(i=0;i<M;i++){
            scanf("%d%d%d",&x,&y,&z);
            edge[x].push_back(y);
            edge[y].push_back(x);
            cost[x].push_back(z);
            cost[y].push_back(z);
        }
        for(i=0;i<SIZE;i++){
            d[i]=infinity;
        }
        u.city=S,
        u.dist=0;
        pq.push(u);
        d[S]=0;
        while(!pq.empty()){
            u=pq.top();
            pq.pop();
            ucost=d[u.city];
            size=edge[u.city].size();
            for(i=0;i<size;i++){
                v.city=edge[u.city][i];
                v.dist=cost[u.city][i]+ucost;
                if(d[v.city]>v.dist){
                    d[v.city]=v.dist;
                    pq.push(v);
                }
            }
        }
        dis=d[T];
        printf("Case #%d: ",++cases);
        if(dis==infinity) puts("unreachable");
        else printf("%d\n",dis);
        for(i=0;i<SIZE;i++){
            edge[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}

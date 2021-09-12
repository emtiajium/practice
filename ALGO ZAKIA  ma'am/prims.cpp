#include<stdio.h>
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
const int MAX=105;
struct TT{
    int node,cost;
};
struct comp{
    bool operator()(TT a, TT b){
        return a.cost > b.cost;
    }
};
priority_queue < TT , vector<TT> , comp > pq;
vector<TT>arr[MAX];
bool visited[MAX];
TT U,V;
int N,E,i,j,a,b,p,cost,sum,source,size,coun;
int main ()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d%d",&N,&E)==2){
        for(i=0;i<E;i++){
            scanf("%d%d%d",&a,&b,&cost);
            U={b,cost};
            arr[a].push_back(U);
            U.node=a;
            arr[b].push_back(U);
        }
        source=arr[1][0].node;
        sum=0;
        V={source,0};
        pq.push(V);
        while(!pq.empty()){
            U=pq.top();
            if(visited[U.node]==false) sum+=U.cost;
            visited[U.node]=true;
            pq.pop();
            size=arr[U.node].size();
            for(i=0;i<size;i++){
                p=arr[U.node][i].node;
                if(visited[p]==false){
                    V.node=p;
                    V.cost=arr[U.node][i].cost;
                    pq.push(V);
                }
            }
        }
        for(i=coun=0;i<=N;i++){
            if(visited[i]) coun++;
        }
        if(coun!=N) puts("MST impossible");
        else printf("%d\n",sum);
        memset(visited,false,sizeof(visited));
        for(i=0;i<MAX;i++)
            arr[i].clear();
    }
    return 0;
}

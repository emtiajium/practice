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
struct TT{
    int u,v,cost;
};
TT graph[2005];
int dist[1005];
int t,N,E,i,k,U,V,ucost;
bool flag;
int main()
{
    //freopen("input.txt","r",stdin);//input.in
    //freopen("output.txt","w",stdout);//output.out
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&N,&E);
        for(i=0;i<E;i++){
            scanf("%d%d%d",&graph[i].u,&graph[i].v,&graph[i].cost);
        }
        for(i=0;i<=N;i++) dist[i]=10000009;
        dist[0]=0;
        for(k=1;k<N;k++){
            for(i=0;i<E;i++){
                U=graph[i].u;
                V=graph[i].v;
                ucost=dist[U]+graph[i].cost;
                dist[V]=min(ucost,dist[V]);
            }
        }
        for(i=0,flag=false;i<E;i++){
            U=graph[i].u;
            V=graph[i].v;
            ucost=dist[U]+graph[i].cost;
            if(dist[V]>ucost){
                flag=true;
                break;
            }
        }
        if(flag) puts("possible");
        else puts("not possible");
    }
    return 0;
}

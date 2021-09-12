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
    int u,v,cost;
};
TT graph[SIZE];
int dist[SIZE];
int N,E,source,end,i,k,U,V,ucost;
bool flag;
int main()
{
    freopen("input.txt","r",stdin);//input.in
    //freopen("output.txt","w",stdout);//output.out
    while(scanf("%d%d",&N,&E)==2){
        for(i=0;i<E;i++){
            scanf("%d%d%d",&graph[i].u,&graph[i].v,&graph[i].cost);
        }
        for(i=0;i<=N;i++) dist[i]=1000009;
        //scanf("%d%d",&source,&end);
        source=1;
        dist[source]=0;
        parent[source]=-1;
        for(k=1;k<N;k++){
            printf("%d iteration\n",k);
            for(i=0;i<E;i++){
                U=graph[i].u;
                V=graph[i].v;
                ucost=dist[U]+graph[i].cost;
                if(ucost<dist[V]){
                    dist[V]=ucost;
                    parent[V]=U;
                }
            }
            for(i=1;i<=N;i++) printf("%d --> %d\n",i,dist[i]);
            puts("");
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
        if(flag) puts("Graph contains a negative-weight cycle");
        else{
            for(i=1;i<=N;i++) printf("%d --> %d\n",i,dist[i]);
            //printf("%d\n",dist[end]);
        }
        puts("");
    }
    return 0;
}
/*
source = 0

3 3
0 1 1000
1 2 15
2 1 -42

8 11
0 1 10
0 7 8
1 5 2
2 1 1
2 3 1
3 4 3
4 5 -1
5 2 -2
6 5 -1
6 1 -4
7 6 1
*/

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
using namespace std;
const int MAX=100;
struct TT{
    int u,v,cost;
};
TT graph[MAX];
int parent[MAX];
bool flag[MAX];
int N,E,i,a,b,c,coun;
bool comp(TT a,TT b){
    return a.cost<b.cost;
}
int find(int a){
    if(parent[a]!=a) parent[a]=find(parent[a]);
    return parent[a];
}
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d%d",&N,&E)==2){
        for(i=0;i<E;i++)
            scanf("%d%d%d",&graph[i].u,&graph[i].v,&graph[i].cost);
        sort(graph,graph+E,comp);
        //for(i=0;i<E;i++) printf("%d %d %d\n",graph[i].u,graph[i].v,graph[i].cost);
        for(i=0;i<=N;i++)
            parent[i]=i;
        for(i=c=coun=0;i<E&&coun!=N-1;i++){
            a=find(graph[i].u);
            b=find(graph[i].v);
            if(a!=b){
                c+=graph[i].cost;
                parent[b]=a;// parent[a]=b;
                flag[i]=true;
                coun++;
            }
        }
        if(coun!=N-1) puts("Not possible");
        else{
            for(i=0;i<E;i++){
                if(flag[i]==true) printf("%d --> %d %d\n",graph[i].u,graph[i].v,graph[i].cost);
            }
            printf("MinCost %d\n",c);
		}
		memset(flag,false,sizeof(flag));
    }
    return 0;
}
/*
min && 2nd min are same
9 14
1 2 4
1 8 8
2 8 11
3 2 8
8 9 7
8 7 1
7 9 6
9 3 2
3 4 7
3 6 4
7 6 2
4 6 14
4 5 9
5 6 10
*/

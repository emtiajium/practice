#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
struct TT{
    int u,v,cost;
};
TT graph[25005];
int parent[1005];
vector<int>v;
bool flag[25005];
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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d%d",&N,&E)&&N&&E){
        for(i=0;i<E;i++)
            scanf("%d%d%d",&graph[i].u,&graph[i].v,&graph[i].cost);
        sort(graph,graph+E,comp);
        for(i=0;i<=N;i++)
            parent[i]=i;
        for(i=c=coun=0;i<E;i++){
            a=find(graph[i].u);
            b=find(graph[i].v);
            if(a!=b){
                c+=graph[i].cost;
                parent[b]=a;// parent[a]=b;
                flag[i]=true;
                coun++;
            }
        }
        for(i=0;i<E;i++){
            if(flag[i]==false) v.push_back(graph[i].cost);
        }
        sort(v.begin(),v.end());
        a=v.size();
        if(a) printf("%d",v[0]); // পুশ না হলেও আউটপুট দেখায়।
        for(i=1;i<a;i++){
            printf(" %d",v[i]);
        }
        if(a==0) puts("forest");
        else puts("");
        v.clear();
        memset(flag,false,sizeof(flag));
    }
    return 0;
}
/*

shakil AUST

cycle na hoile oita forest.
ekhon question hoilo taile cycle ta kokhon ami kortechi na.
MST er problem e, say eta to kruskal diya kora jay.
amra always 2ita alada alada node nei,
emon check kori tader parent ek naki ba tara age theke link up naki,
na hole oi node ta nei. ar linkup thakle nei na.
ekhane ei linkup er kaj tai kaje lagaite hobe.
judi sob edge er junnoi ekhane kruskal e u,v 2ita node hole, parent[u]!=parent[v] condition true thake,
taile kintu finally konoi cyclei paowa gelo na, eta forest. 2nd tast case e eta valo vabe bujha jay.
4 5
0 1 1
1 2 2
2 3 3
3 1 4
0 2 0
kruskal er ..........
*/

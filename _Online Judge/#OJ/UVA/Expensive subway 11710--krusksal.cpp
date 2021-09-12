#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
using namespace std;
struct TT{
    int u,v,cost;
};
struct comp{
    bool operator()( TT a, TT b){
        return a.cost > b.cost;
    }
};
priority_queue < TT , vector<TT> , comp > pq;
TT arr[79805];
int parent[405];
map< string, int > city;
TT t,U,V;
string s,s2;
int N,E,i,a,b,cost,sum,coun;
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
    while(scanf("%d%d",&N,&E)){
        if(N==0 && E==0) break;
        for(i=1;i<=N;i++){
            cin>>s;
            city[s]=i;
        }
        for(i=0;i<E;i++){
            cin>>s>>s2>>cost;
			a=city[s];
			b=city[s2];
            arr[i]={a,b,cost};
        }
        cin>>s;
        sort(arr,arr+E,comp);
        for(i=0;i<=N;i++)
            parent[i]=i;
        for(i=sum=coun=0;i<E&&coun!=N-1;i++){
            a=find(arr[i].u);
            b=find(arr[i].v);
            if(a!=b){
                sum+=arr[i].cost;
                parent[b]=a;// parent[a]=b;
                coun++;
            }
        }
        if(coun!=N-1) puts("Impossible");
        else printf("%d\n",sum);
    }
    return 0;
}

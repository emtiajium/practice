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
    int city,distTT;
};
struct comp{
    bool operator()(TT a,TT b){
        return a.distTT<b.distTT;
    }
};
int parent[15],dist[15];
vector<int>edge[15],cost[15],v;
TT U,V;
priority_queue< TT, vector<TT>, comp>pq;
int cases,N,n,i,b,c,source,end,ucost,size;
void path(int s,int d){
    v.push_back(d);
    if(parent[d]==s){
        v.push_back(s);
        return;
    }
    path(s,parent[d]);
}
int main()
{
    //freopen("input.txt","r",stdin);//input.in
    //freopen("output.txt","w",stdout);//output.out
    while(scanf("%d",&N)&&N){
        for(i=1;i<=N;i++){
            scanf("%d",&n);
            while(n--){
                scanf("%d%d",&b,&c);
                edge[i].push_back(b);
                cost[i].push_back(c);
            }
            dist[i]=10000009;
        }
        scanf("%d%d",&source,&end);
        U={source,0};
        //U.city=source; U.distTT=0;
        pq.push(U);
        dist[source]=0;
        parent[source]=-1;
        while(!pq.empty()){
            U=pq.top();
            pq.pop();
            ucost=dist[U.city];
            size=edge[U.city].size();
            for(i=0;i<size;i++){
                V.city=edge[U.city][i];
                V.distTT=cost[U.city][i]+ucost;
                if(V.distTT<dist[V.city]){
                    dist[V.city]=V.distTT;
                    parent[V.city]=U.city;
                    pq.push(V);
                }
            }
        }
        printf("Case %d: Path =",++cases);
        path(source,end);
        reverse(v.begin(),v.end());
        size=v.size();
        for(i=0;i<size;i++){
            printf(" %d",v[i]);
        }
        printf("; %d second delay\n",dist[end]);
        v.clear();
        memset(parent,-1,sizeof(parent));
        memset(dist,0,sizeof(dist));
        for(i=0,N+=2;i<N;i++){
            edge[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}

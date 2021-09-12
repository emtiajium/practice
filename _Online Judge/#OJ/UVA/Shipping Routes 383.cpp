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
//const double PI=3.14159265358979323846264338327950288419716939937511;
vector<int>graph[1005];
queue<int>Q;
map<string,int>city;
string str,str2;
int dist[35];
bool visited[35],flag;
int cases,t,N,E,q,val,cost,a,b,source,end,u,v,i,size;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    puts("SHIPPING ROUTES OUTPUT\n");
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&N,&E,&q);
        for(i=0;i<N;i++){
            cin>>str;
            city[str]=i;
        }
        for(i=0;i<E;i++){
            cin>>str>>str2;
            a=city[str];
            b=city[str2];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        printf("DATA SET  %d\n\n",++cases);
        while(q--){
            if(flag==true) puts("");
            flag=true;
            cin>>val>>str>>str2;
            source=city[str];
            end=city[str2];
            visited[source]=true;
            dist[source]=0;
            Q.push(source);
            while(!Q.empty()){
                u=Q.front();
                size=graph[u].size();
                for(i=0;i<size;i++){
                    v=graph[u][i];
                    if(visited[v]==false){
                        dist[v]=dist[u]+1;
                        visited[v]=true;
                        Q.push(v);
                    }
                }
                Q.pop();
            }
            cost=dist[end]*val*100;
            if(cost==0) puts("NO SHIPMENT POSSIBLE");
            else printf("$%d\n",cost);
            flag=false;
            memset(visited,false,sizeof(visited));
            memset(dist,0,sizeof(dist));
        }
        puts("");
        for(i=0;i<N;i++) graph[i].clear();
    }
    printf("END OF OUTPUT\n");
    return 0;
}

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
const int MAX=1005;
vector<int>graph[MAX];
queue<int>Q;
map< int, int >city;
int dist[35];
bool visited[35];
int cases,E,x,y,a,b,source,u,v,i,size,assign,TTL,coun;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&E),E){
        assign=0;
        for(i=0;i<E;i++){
            scanf("%d%d",&x,&y);
            if(city.find(x)==city.end()) city[x]=assign++;
            if(city.find(y)==city.end()) city[y]=assign++;
            a=city[x];
            b=city[y];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        while(scanf("%d%d",&a,&TTL)==2){
            if(a==0 && TTL==0) break;
            source=city[a];
            visited[source]=true;
            dist[source]=0;
            Q.push(source);
            while(!Q.empty()){
                u=Q.front();
                size=graph[u].size();
                for(i=0;i<size;i++){
                    v=graph[u][i];
                    if(visited[v]==false){
                        visited[v]=true;
                        dist[v]=dist[u]+1;
                        Q.push(v);
                    }
                }
                Q.pop(); // ৪৫ নাম্বার লাইনের পর-পরই দেয়া যায়।
            }
            size=city.size();
            for(i=coun=0;i<size;i++){
                if(i==source) continue;//source
                else if(dist[i]==0) coun++;//unreachable
                else if(dist[i]>TTL) coun++;//greater TTL
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++cases,coun,a,TTL);
            memset(visited,false,sizeof(visited));
            memset(dist,0,sizeof(dist));
        }
        size=city.size();
        city.clear();
        for(i=0;i<size;i++){
            graph[i].clear();
        }
    }
    return 0;
}
/*
there is no isoleted vertex in judge input.
1
10 11
12 1 0 0
0
*/

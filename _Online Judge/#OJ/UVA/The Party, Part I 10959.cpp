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
int dist[MAX];
bool visited[MAX],flag;
int t,N,E,a,b,source,u,v,i,size;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        if(flag) puts("");
        flag=true;
        scanf("%d%d",&N,&E);
        for(i=0;i<E;i++){
            scanf("%d%d",&a,&b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        source=0;
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
        for(i=1;i<N;i++){
            printf("%d\n",dist[i]);
        }
        memset(visited,false,sizeof(visited));
        memset(dist,0,sizeof(dist));
        for(i=0;i<MAX;i++) graph[i].clear();
    }
    return 0;
}

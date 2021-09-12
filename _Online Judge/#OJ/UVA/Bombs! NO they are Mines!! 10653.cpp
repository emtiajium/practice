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
int xx[]={-1,0,0,1};
int yy[]={0,-1,1,0};
bool graph[1005][1005],visited[1005][1005];
int dist[1005][1005];
queue<int>Q,q;
int ROW,COL,bomb,row,col,num,u,v,su,sv,eu,ev,k,c,d;
bool is_safe(int c,int d){
    if(c<0||c>=ROW||d<0||d>=COL) return false;
    return true;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d%d",&ROW,&COL)){
        if(ROW==0 && COL==0) break;
        scanf("%d",&bomb);
        while(bomb--){
            scanf("%d%d",&row,&num);
            for(k=0;k<num;k++){
                scanf("%d",&col);
                graph[row][col]=true;
            }
        }
        scanf("%d%d%d%d",&su,&sv,&eu,&ev);
        visited[su][sv]=true;
        dist[su][sv]=0;
        Q.push(su);
        q.push(sv);
        while(!Q.empty()){
            u=Q.front();
            v=q.front();
            for(k=0;k<4;k++){
                c=u+xx[k];
                d=v+yy[k];
                if(graph[c][d]==false && is_safe(c,d) && visited[c][d]==false){
                    Q.push(c);
                    q.push(d);
                    visited[c][d]=true;
                    dist[c][d]=dist[u][v]+1;
                }
                u=Q.front();
                v=q.front();
            }
            Q.pop();
            q.pop();
        }
        printf("%d\n",dist[eu][ev]);
        memset(visited,false,sizeof(visited));
        memset(graph,false,sizeof(graph));
        memset(dist,0,sizeof(dist));
    }
    return 0;
}

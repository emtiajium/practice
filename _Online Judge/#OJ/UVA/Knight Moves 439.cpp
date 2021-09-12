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
bool is_safe(int c,int d){
    if(c<0||c>=8||d<0||d>=8) return false;
    return true;
}
int xx[]={-2,-1,1,2,-2,-1,1,2};
int yy[]={1,2,2,1,-1,-2,-2,-1};
bool visited[10][10];
int dist[10][10];
char str[5],str2[5];
queue<int>Q,q;
int su,sv,eu,ev,u,v,c,d,k;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%s %s",str,str2)==2){
        su=str[1]-49;
        sv=str[0]-97;
        eu=str2[1]-49;
        ev=str2[0]-97;
        visited[su][sv]=true;
        dist[su][sv]=0;
        Q.push(su);
        q.push(sv);
        while(!Q.empty()){
            u=Q.front();
            v=q.front();
            for(k=0;k<8;k++){
                c=u+xx[k];
                d=v+yy[k];
                if(is_safe(c,d) && visited[c][d]==false){
                    Q.push(c);
                    q.push(d);
                    dist[c][d]=dist[u][v]+1;
                    visited[c][d]=true;
                }
                u=Q.front();
                v=q.front();
            }
            Q.pop();
            q.pop();
        }
        printf("To get from %s to %s takes %d knight moves.\n",str,str2,dist[eu][ev]);
        memset(visited,false,sizeof(visited));
        memset(dist,0,sizeof(dist));
    }
    return 0;
}

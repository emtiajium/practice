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
vector<int>graph[500005];
bool visited[30005];
queue<int>Q;
int t,N,E,a,b,u,v,source,i,j,size,coun,high;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&N,&E);
        for(i=0;i<E;i++){
            scanf("%d%d",&a,&b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        high=0;
        for(i=1;i<=N;i++){
            source=i;
            visited[source]=true;
            Q.push(source);
            coun=1;
            while(!Q.empty()){
                u=Q.front();
                size=graph[u].size();
                for(j=0;j<size;j++){
                    v=graph[u][j];
                    if(visited[v]==false){
                        visited[v]=true;
                        Q.push(v);
                        coun++;
                    }
                }
                Q.pop();
            }
            high=max(high,coun);
            memset(visited,false,sizeof(visited));
        }
        printf("%d\n",high);
        for(i=0;i<=N;i++) graph[i].clear();
    }
    return 0;
}

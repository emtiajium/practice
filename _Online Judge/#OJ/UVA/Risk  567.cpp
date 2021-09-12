#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int SIZE=25;
vector<int>edge[SIZE];
queue<int>Q;
int dist[SIZE];
bool visited[SIZE],flag;
int cases,t,q,n,x,i,u,v,source,dest,size;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    i=1;
    while(scanf("%d",&n)==1){
        while(n--){
            scanf("%d",&x);
            edge[i].push_back(x);
            edge[x].push_back(i);
        }
        i++;
        t=18;
        while(t--){
            scanf("%d",&n);
            while(n--){
                scanf("%d",&x);
                edge[i].push_back(x);
                edge[x].push_back(i);
            }
            i++;
        }
        scanf("%d",&q);
        printf("Test Set #%d\n",++cases);
        while(q--){
            scanf("%d%d",&source,&dest);
            visited[source]=true;
            dist[source]=0;
            Q.push(source);
            while(!Q.empty()){
                u=Q.front();
                size=edge[u].size();
                for(i=0;i<size;i++){
                    v=edge[u][i];
                    if(visited[v]==false){
                        dist[v]=dist[u]+1;
                        visited[v]=true;
                        Q.push(v);
                    }
                }
                Q.pop();
            }
            printf("%2d to %2d: %d\n",source,dest,dist[dest]);
            memset(dist,0,sizeof(dist));
            memset(visited,false,sizeof(visited));
        }
        puts("");
        for(i=0;i<SIZE;i++) edge[i].clear();
        i=1;
    }
    return 0;
}
/*
first input
node edge
20 28
edge
1 3
2 3
2 4
3 4
3 5
3 6
4 6
5 7
6 12
6 13
7 8
8 9
8 10
9 11
10 11
11 12
11 17
12 14
13 14
13 15
14 15
14 16
15 16
16 19
17 18
17 19
18 20
19 20
source destination
1 20
2 9
19 5
18 19
16 20
*/

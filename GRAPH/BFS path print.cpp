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
const int MAX=105;
vector<int>graph[MAX];
queue<int>Q;
int dist[MAX],parent[MAX];
bool visited[MAX];
int N,E,a,b,source,end,u,v,i,size;

void path(int n,int s){
    printf("%d <-- ",n);
    if(parent[n]==s){
        printf("%d\n",s);
        return;
    }
    path(parent[n],s);
}

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d%d",&N,&E)==2){
        for(i=0;i<E;i++){
            scanf("%d%d",&a,&b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        while(scanf("%d%d",&source,&end)==2){
            visited[source]=true;
            dist[source]=0;
            parent[source]=-1;
            Q.push(source);
            while(!Q.empty()){
                u=Q.front();
                size=graph[u].size();
                for(i=0;i<size;i++){
                    v=graph[u][i];
                    if(visited[v]==false){
                        dist[v]=dist[u]+1;
                        visited[v]=true;
                        parent[v]=u;
                        Q.push(v);
                    }
                }
                Q.pop();
            }
            printf("Source %d to end %d\n",source,end);
            if(source!=end && dist[end]==0) puts("Unreachable");
            else if(source==end){
                printf("%d <-- %d\n",source,end);
                printf("Path length %d\n\n",dist[end]);
            }
            /* এখানে সোর্স  নোড আর unreachable নোড উভয়েরই ডিস্টেন্স শুণ্য থাকবে; একটা কাজ করা যায়; ডিসটেন্স
                অ্যারে ইনফিনিটি দিয়ে ফিল আপ করা যায়, তাতে     সোর্স  নোডের জিরো ডিস্টেন্স  আর unreachable নোডের ইনফিনিটি থাকবে। */
            else if(source!=end && dist[end]!=0){
                path(end,source);
                printf("Path length %d\n\n",dist[end]);
            }
            memset(visited,false,sizeof(visited));
            memset(dist,0,sizeof(dist));
            memset(parent,-1,sizeof(parent));
        }
        for(i=0;i<MAX;i++) graph[i].clear();
    }
    return 0;
}
/*
12 12
1 2
1 4
2 3
3 7
4 5
5 7
5 8
8 9
7 9
9 10
8 10
11 12

2 2
2 10
2 12
11 12
*/

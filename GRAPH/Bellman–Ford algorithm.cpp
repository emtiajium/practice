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
const int SIZE=105;
struct TT{
    int u,v,cost;
};
TT graph[SIZE];
int dist[SIZE];
int N,E,source,end,i,k,U,V,ucost;
bool flag;
int main()
{
    freopen("input.txt","r",stdin);//input.in
    //freopen("output.txt","w",stdout);//output.out
    while(scanf("%d%d",&N,&E)==2){
        for(i=0;i<E;i++){
            scanf("%d%d%d",&graph[i].u,&graph[i].v,&graph[i].cost);//Directed
        }
        for(i=0;i<=N;i++) dist[i]=1000009;
        //scanf("%d",&source);
        source=0;
        dist[source]=0;
        for(k=1;k<N;k++){//কারণ ২টা নোডের মধ্যে shortest path এ n-1 টার বেশি এজ থাকেনা।
            printf("%d iteration\n",k);
            for(i=0;i<E;i++){
                U=graph[i].u;
                V=graph[i].v;
                ucost=dist[U]+graph[i].cost;
                if(ucost<dist[V]){
                    dist[V]=ucost;
                }
            }
            for(i=0;i<=N;i++) printf("%d --> %d\n",i,dist[i]); puts("");
        }
        for(i=0,flag=false;i<E;i++){
            U=graph[i].u;
            V=graph[i].v;
            ucost=dist[U]+graph[i].cost;
            if(dist[V]>ucost){
                flag=true;
                break;
            }
        }
        if(flag) puts("Graph contains a negative-weight cycle");
        else{
            for(i=0;i<=N;i++) printf("%d --> %d\n",i,dist[i]);
            //printf("%d\n",dist[end]);
        }
        puts("");
    }
    return 0;
}
/*
// পরপর দুই স্টেপে আপডেইট হয়নি মানে হচ্ছে শর্টেস্ট পাথ বের হয়ে গেছে; আর আপডেইট হবেনা।
source = 0

3 3
0 1 1000
1 2 15
2 1 -42

8 11
0 1 10
0 7 8
1 5 2
2 1 1
2 3 1
3 4 3
4 5 -1
5 2 -2
6 5 -1
6 1 -4
7 6 1

4 5
0 1 1
0 2 -1
0 3 -2
1 3 4
2 3 3
*/
/*
In particular, in a directed
acyclic graph (one with no cycles), we can use Bellman­Ford to find the  longest path  
from s to any
vertices v, by simply changing all the positive weights to negative, and vice versa.
*/

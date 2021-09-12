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
vector<int>graph[MAX],vct;
queue<int>Q;
map< string, int >city;
string arr[MAX],str,str2;
int parent[MAX],dist[MAX];
bool visited[MAX],flag;
int t,N,E,q,a,b,source,end,u,v,i,size,assign;
void path(int n,int s){
    vct.push_back(n);
    if(parent[n]==s){
        vct.push_back(s);
        return;
    }
    path(parent[n],s);
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        if(flag==true) puts("");
        flag=true;
        scanf("%d%d",&E,&q);
        assign=0;
        for(i=0;i<E;i++){
            cin>>str>>str2;
            if(city.find(str)==city.end()) city[str]=assign++;
            if(city.find(str2)==city.end()) city[str2]=assign++;
            a=city[str];
            b=city[str2];
            arr[a]=str;
            arr[b]=str2;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        while(q--){
            cin>>str>>str2;
            source=city[str];
            end=city[str2];
            visited[source]=true;
            parent[source]=-1;
            Q.push(source);
            while(!Q.empty()){
                u=Q.front();
                size=graph[u].size();
                for(i=0;i<size;i++){
                    v=graph[u][i];
                    if(visited[v]==false){
                        visited[v]=true;
                        parent[v]=u;
                        Q.push(v);
                    }
                }
                Q.pop();
            }
            path(end,source);
            reverse(vct.begin(),vct.end());
            size=vct.size();
            for(i=0;i<size;i++){
                a=vct[i];
                cout<<arr[a][0];
            }
            puts("");
            memset(visited,false,sizeof(visited));
            memset(parent,-1,sizeof(parent));
            vct.clear();
        }
        size=city.size();
        city.clear();
        for(i=0;i<size;i++){
            graph[i].clear();
        }
    }
    return 0;
}

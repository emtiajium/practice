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
int N,E,a,b,source,end,u,v,i,size,assign;
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
    while(scanf("%d",&E)==1){
        if(flag==true) puts("");
        flag=true;
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
        cin>>str>>str2;
        if(city.find(str)==city.end()) city[str]=assign++;
        if(city.find(str2)==city.end()) city[str2]=assign++;
        source=city[str];
        end=city[str2];
        visited[source]=true;
        parent[source]=-1;
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
                    parent[v]=u;
                    Q.push(v);
                }
            }
            Q.pop();
        }
        if(source!=end && dist[end]==0) puts("No route");
        else if(source==end){
            if(dist[end]==0) puts("");
            else cout<<arr[source]<<" "<<arr[end]<<endl;
        }
        else{
            path(end,source);
            reverse(vct.begin(),vct.end());
            size=vct.size()-1;
            for(i=0;i<size;i++){
                a=vct[i];
                b=vct[i+1];
                cout<<arr[a]<<" "<<arr[b]<<endl;
            }
        }
        size=city.size();
        memset(visited,false,sizeof(visited));
        memset(parent,-1,sizeof(parent));
        memset(dist,0,sizeof(dist));
        vct.clear();
        city.clear();
        for(i=0;i<size;i++){
            graph[i].clear();
        }
    }
    return 0;
}

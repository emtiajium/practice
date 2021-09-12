#include<stdio.h>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX=105;
const double EPS=1e-9;
struct PP{
    double xx,yy;
};
struct TT{
    int u,v;
    double cost;
};
PP coord[MAX];
TT temp;
vector<TT>graph;
int parent[MAX];
int cases,N,E,i,j,a,b,coun;
double c;
bool flag;
bool comp(TT a,TT b){
    return a.cost<b.cost;
}
int find(int a){
    if(parent[a]!=a) parent[a]=find(parent[a]);
    return parent[a];
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        if(flag) puts("");
        flag=true;
        scanf("%d",&N);
        for(i=0;i<N;i++){
            scanf("%lf%lf",&coord[i].xx,&coord[i].yy);
        }
        for(i=0;i<N;i++){
            for(j=i+1;j<N;j++){
                temp.u=i;
                temp.v=j;
                temp.cost=sqrt( (coord[i].xx - coord[j].xx)*(coord[i].xx - coord[j].xx) + (coord[i].yy - coord[j].yy)*(coord[i].yy - coord[j].yy) );
                graph.push_back(temp);
            }
        }
        sort(graph.begin(),graph.end(),comp);
        E=graph.size();
        //for(i=0;i<E;i++) printf("%d %d %lf\n",graph[i].u,graph[i].v,graph[i].cost);
        for(i=0;i<=N;i++) // <=MAX got me TLE && OLE
            parent[i]=i;
        c=0.0;
        for(i=coun=0;i<E&&coun!=N-1;i++){
            a=find(graph[i].u);
            b=find(graph[i].v);
            if(a!=b){
                c+=graph[i].cost;
                parent[b]=a;// parent[a]=b;
                coun++;
            }
        }
        c+=EPS;
        printf("%.2lf\n",c);
		graph.clear();
    }
    return 0;
}

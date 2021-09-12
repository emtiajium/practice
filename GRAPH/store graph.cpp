#include<cstdio>
#include<vector>
using namespace std;
const int MAX=100; //maximum node
int main()
{
    freopen("input.txt","r",stdin);
    int N,E,i,j,x,y,size;
    vector<int>edges[MAX];
    vector<int>cost[MAX]; //parallel vector to store costs;
    scanf("%d%d",&N,&E);
    for(i=0;i<E;i++){
        scanf("%d%d",&x,&y);
        edges[x].push_back(y);
        edges[y].push_back(x);
        cost[x].push_back(1);
        cost[y].push_back(1);
    }
    for(i=0;i<=N;i++){
        size=edges[i].size();
        if(size==0) continue;
        printf("%d >> ",i);
        for(j=0;j<size;j++){
            printf("%d ",edges[i][j]);
        }
        puts("");
    }
    return 0;
}

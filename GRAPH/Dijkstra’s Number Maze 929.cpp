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
const int infinity=10000009;
struct TT{
    int x,y,distTT;
};
struct comp{
    bool operator()(TT a,TT b){
        return a.distTT>b.distTT;
    }
};
TT U,V;
priority_queue< TT, vector<TT>, comp > PQ;
int xx[]={0,1,0,-1};
int yy[]={-1,0,1,0};
int cost[1003][1003],dist[1003][1003];
int t,row,col,u,c,d,i,j,k,ucost;
bool is_safe(int c,int d){
    if(c<0||c>=row||d<0||d>=col) return false;
    return true;
}
int main()
{
    //freopen("input.txt","r",stdin);//input.in
    //freopen("output.txt","w",stdout);//output.out
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&row,&col);
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                scanf("%d",&cost[i][j]);
                dist[i][j]=infinity;
            }
        }
        dist[0][0]=cost[0][0];
        U={0,0,0};
        PQ.push(U);
        while(!PQ.empty()){
            U=PQ.top();
            PQ.pop();
            ucost=dist[U.x][U.y];
            for(k=0;k<4;k++){
                c=U.x+xx[k];
                d=U.y+yy[k];
                V={c,d,cost[c][d]+ucost};
                if(is_safe(c,d) && V.distTT<dist[c][d]){
                    PQ.push(V);
                    dist[c][d]=V.distTT;
                }
            }
        }
        printf("%d\n",dist[row-1][col-1]);
    }
    return 0;
}

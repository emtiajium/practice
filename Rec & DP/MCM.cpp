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
const int INF = 1048576;
int cost[105][105],S[105][105],arr[105];
int N;
int MCM(int i,int j){
    int k,mcost;
    if(i==j) return 0;
    if(cost[i][j]!=INF) return cost[i][j];
    if(i<j){
        for(k=i;k<j;k++){
            mcost=cost[i][j];
            cost[i][j]=min(cost[i][j],MCM(i,k)+MCM(k+1,j)+arr[i-1]*arr[k]*arr[j]);
            if(cost[i][j]<mcost) S[i][j]=k;
        }
        return cost[i][j];
    }
}
void output(int i,int j){
    if(i==j){
        printf("A%d",i);
        return;
    }
    else if(i<j){
        printf("(");
        output(i,S[i][j]);
        printf(" x ");
        output(S[i][j]+1,j);
        printf(")");
        return;
    }
}
int main()
{
    //freopen("input.txt","r",stdin);//input.in
    //freopen("output.txt","w",stdout);//output.out
    int i,j;
    while(scanf("%d",&N)==1){
        N++;
        for(i=0;i<105;i++){
            for(j=0;j<105;j++)
                cost[i][j]=INF;
        }
        for(i=0;i<N;i++){
            scanf("%d",&arr[i]);
        }
        MCM(1,N-1);
        for(i=1;i<N;i++){
            for(j=i+1;j<N;j++)
                printf("%d ",cost[i][j]);
            puts("");
        }
        for(i=1;i<N;i++){
            for(j=i+1;j<N;j++)
                printf("%d ",S[i][j]);
            puts("");
        }
        printf("Min Cost %d\n\n",cost[1][N-1]);
        output(1,N-1);
        puts("\n");
    }
    return 0;
}
/*
4
30 1 40 10 25
6
30 35 15 5 10 20 25
*/

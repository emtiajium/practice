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
const int INF = 2000000000;
int cost[12][12],S[12][12],arr[12];
int cases,N,aa,bb;

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
    while(scanf("%d",&N)&&N){
        for(i=0;i<N;i++){
            scanf("%d%d",&aa,&bb);
            arr[i]=aa;
        }
        arr[i]=bb;
        for(i=0;i<12;i++){
            for(j=0;j<12;j++)
                cost[i][j]=INF;
        }
        MCM(1,N);
        printf("Case %d: ",++cases);
        output(1,N);
        puts("");
    }
    return 0;
}

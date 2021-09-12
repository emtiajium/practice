#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
//const double PI=3.14159265358979323846264338327950288419716939937511;
int n,b,h,w,i,j,k;
bool flag;
int price[25],bed[25][20],cost[25];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d%d%d%d",&n,&b,&h,&w)==4){
        for(i=0;i<h;i++){
            scanf("%d",&price[i]);
            for(j=0;j<w;j++)
                scanf("%d",&bed[i][j]);
        }
        k=0;
        for(i=0;i<h;i++){
            flag=0;
            for(j=0;j<w;j++){
                if(bed[i][j]>=n){
                    cost[k]=n*price[i];
                    flag=1;
                }
            }
            if(flag) k++;
        }
        sort(cost,cost+k);
        if(k==0||cost[0]>b) puts("stay home");
        else printf("%d\n",cost[0]);
        memset(cost,0,sizeof(cost));
    }
    return 0;
}

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
struct TT{
    int num,mod,evod;
};
TT arr[10005];
int M,N,i;

bool comp(TT a, TT b){
    if(a.mod==b.mod){
        if(a.evod==1 && b.evod==1) return a.num>b.num;
        else if(a.evod==0 && b.evod==0) return a.num<b.num;
        return a.evod>b.evod;
    }
    return a.mod<b.mod;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d%d",&N,&M)&&N&&M){
        for(i=0;i<N;i++){
            scanf("%d",&arr[i].num);
            arr[i].mod=arr[i].num%M;
            arr[i].evod=arr[i].num&1;
        }
        sort(arr,arr+N,comp);
        printf("%d %d\n",N,M);
        for(i=0;i<N;i++){
            printf("%d\n",arr[i]);
        }
    }
    puts("0 0");
    return 0;
}

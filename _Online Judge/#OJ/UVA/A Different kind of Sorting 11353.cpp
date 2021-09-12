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
bool flag[1430];
int prime[230]={2};
int i,j,k,r,cnd,t,cases;
struct TT{
    int val,pf;
};
TT arr[2000005];
bool comp(TT a,TT b){
    if(a.pf==b.pf) return a.val<b.val;
    return a.pf<b.pf;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=3;i<38;i+=2){
        r=i+i;
        if(flag[i]==false){
            for(j=i*i;j<1425;j+=r)
                flag[j]=true;
        }
    }
    for(i=3,j=1;i<1425;i+=2)
        if(flag[i]==false) prime[j++]=i;
    arr[1].val=1;
    arr[1].pf=1;
    for(k=2;k<2000002;k++){
        t=k;
        cnd=sqrt(t)+1;
        arr[k].val=k;
        arr[k].pf=0;
        for(i=0;prime[i]<cnd&&t!=1;i++){
            while(t%prime[i]==0){
                t/=prime[i];
                arr[k].pf++;
            }
        }
        if(t>1) arr[k].pf++;
    }
    sort(arr+1,arr+2000001,comp);
    while(scanf("%d",&k)&&k){
        printf("Case %d: %d\n",++cases,arr[k].val);
    }
    return 0;
}

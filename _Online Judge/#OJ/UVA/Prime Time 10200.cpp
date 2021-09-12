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
bool flag[10008];
int prime[1235]={2},arr[10005]={0,1};
int i,j,r,k,n,tn,cnd,a,b,num;
double pct;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=3;i<101;i+=2){
        r=i+i;
        if(flag[i]==false){
            for(j=i*i;j<10008;j+=r)
                flag[j]=true;
        }
    }
    for(i=3,j=1;i<10008;i+=2)
        if(flag[i]==false) prime[j++]=i;
    for(k=1;k<10002;k++){
        n=tn=k*k+k+41;
        cnd=sqrt(n)+1;
        for(i=0;prime[i]<cnd&&tn!=1;i++){
            while(tn%prime[i]==0)
                tn/=prime[i];
        }
        if(tn==n) arr[k+1]=arr[k]+1;
        else arr[k+1]=arr[k];
    }
    while(scanf("%d%d",&a,&b)==2){
        num=b-a+1;
        r=arr[b+1]-arr[a];
        pct=((double)r*100.0)/(double)num;
        printf("%.2lf\n",pct+1e-9);
    }
    return 0;
}

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
bool flag[228]={true,true};
int prime[50]={2},res[50002]={0,1};
int n,i,j,k,r,cnd,t;
double phi;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=3;i<16;i+=2){
        if(flag[i]==false){
            for(j=i*i,r=i<<1;j<228;j+=r)
                flag[j]=true;
        }
    }
    for(i=3,j=1;i<228;i+=2){
        if(flag[i]==false) prime[j++]=i;
    }
    for(k=2;k<50001;k++){
        t=k;
        phi=(double)t;
        cnd=sqrt(t)+1;
        for(i=0;prime[i]<cnd&&t!=1;i++){
            flag[0]=false;
            while(t%prime[i]==0){
                t/=prime[i];
                flag[0]=true;
            }
            if(flag[0]) phi*=(1.0-1.0/(double)prime[i]);
        }
        if(t>1) phi*=(1.0-1.0/(double)t);
        res[k]=res[k-1]+2*(int)phi;
    }
    while(scanf("%d",&n)&&n){
        printf("%d\n",res[n]);
    }
    return 0;
}

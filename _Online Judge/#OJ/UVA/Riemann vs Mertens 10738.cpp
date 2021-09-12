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
const int SIZE=1000003;
int i,j,cnd,r,n,coun,t,tot_pf;
bool flag[1010]={1,1},xlag,zlag;
int prime[171]={2};
struct TT{
    int muN,MN;
};
TT arr[SIZE];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=3;i<32;i+=2){
        r=i+i;
        if(flag[i]==false){
            for(j=i*i;j<1010;j+=r)
                flag[j]=true;
        }
    }
    for(i=3,j=1;i<1010;i+=2)
        if(flag[i]==false) prime[j++]=i;
    arr[1].muN=arr[1].MN=1;
    for(i=2;i<SIZE;i++){
        t=i;
        cnd=sqrt(t)+1;
        tot_pf=0;
        zlag=false;
        for(j=0;prime[j]<cnd&&t!=1;j++){
            xlag=false;
            coun=0;
            while(t%prime[j]==0){
                t/=prime[j];
                xlag=true;
                coun++;
            }
            if(xlag==true) tot_pf++;
            if(coun>1){
                zlag=true;
                break;
            }
        }
        if(zlag==false&&t>1) tot_pf++;
        if(zlag==true) arr[i].muN=0;
        else{
            if(tot_pf%2==0) arr[i].muN=1;
            else arr[i].muN=-1;
        }
        arr[i].MN=arr[i-1].MN+arr[i].muN;
    }
    while(scanf("%d",&n)&&n){
        printf("%8d%8d%8d\n",n,arr[n].muN,arr[n].MN);
    }
    return 0;
}

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
const int SIZE=46352;
bool flag[SIZE]={true,true};
int prime[4795]={2};
int i,j,n,tn,r,coun,cnd,divs,res;
double phi;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=3;i<216;i+=2){
        if(flag[i]==false){
            r=i<<1;
            for(j=i*i;j<SIZE;j+=r)
                flag[j]=true;
        }
    }
    for(i=3,j=1;i<SIZE;i+=2){
        if(flag[i]==false) prime[j++]=i;
    }
    while(scanf("%d",&n)==1){
        tn=n;
        divs=1;phi=n;
        cnd=sqrt(n)+1;
        for(i=0;prime[i]<cnd&&n!=1;i++){
            coun=0;
            while(tn%prime[i]==0){
                tn/=prime[i];
                coun++;
            }
            if(coun){
                divs*=coun+1;
                phi*=1-1/(double)prime[i];
            }
        }
        if(tn>1){
            divs*=2;
            phi*=1-1/(double)tn;
        }
        res=n-(int)phi-divs+1;
        printf("%d\n",res);
    }
    return 0;
}

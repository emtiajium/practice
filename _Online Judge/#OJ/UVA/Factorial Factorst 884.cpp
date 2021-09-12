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
int fact[1000005];
int k,i,t_m,cnd,coun;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(k=2;k<1000004;k++){
        coun=0;
        t_m=k;
        while(t_m%2==0){
            t_m/=2;
            coun++;
        }
        cnd=sqrt(t_m);
        i=3;
        while (i<=cnd){
            if(t_m%i==0){
                t_m=t_m/i;
                coun++;
            }
            else i=i+2;
        }
        if(t_m>1) coun++;
        fact[k]=fact[k-1]+coun;
    }
    while(scanf("%d",&k)==1){
        printf("%d\n",fact[k]);
    }
    return 0;
}

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

const int SIZE=105;
bool flag[SIZE]={1,1};
int prime[30]={2},arr[30];
int i,j,k,r,n,coun,zzz;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=3;i<11;i+=2){
        r=i+i;
        if(flag[i]==false){
            for(j=i*i;j<SIZE;j+=r)
                flag[j]=true;
        }
    }
    for(i=3,j=1;i<SIZE;i+=2){
        if(flag[i]==false) prime[j++]=i;
	}
	while(scanf("%d",&n)&&n){
	    printf("%3d! =",n);
        for(i=j=0;prime[i]<=n;i++){
            zzz=prime[i];
            coun=0;
            while(n>=zzz){
                coun+=n/zzz;
                zzz*=prime[i];
            }
            arr[j++]=coun;
        }
        for(i=0;i<j;i++){
            printf("%3d",arr[i]);
            if(i==14&&i<j-1) printf("\n      ");
        }
        memset(arr,0,sizeof(arr));
        puts("");
	}
    return 0;
}

#include<stdio.h>
#include<math.h>
using namespace std;
const int SIZE=1011;
int i,j,k,r;
bool flag[SIZE]={1,1},xlag;
int prime[172]={2};
int main()
{
    //freopen("input.txt","r",stdin);
    for(i=3;i<32;i+=2){
        r=i+i;
        if(!flag[i]){
            for(j=i*i;j<SIZE;j+=r)//j+=2*i;
                flag[j]=1;
        }
    }
    for(i=3,j=1;i<SIZE;i+=2){
        if(!flag[i]) prime[j++]=i;
    }
    while(scanf("%d",&k)&&k){
        printf("%d : ",k);
        j=sqrt(k)+1;
        r=0;
        for(i=0;k!=1&&prime[i]<j;i++){
            xlag=false;
            while(k%prime[i]==0){
                k/=prime[i];
                xlag=true;
            }
            if(xlag) r++;
        }
        if(k>1) r++;
        printf("%d\n",r);
    }
    return 0;
}

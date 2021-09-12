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
bool flag[38];
int prime[15]={2};
struct TT{
    int val,countt;
};
TT arr[1005];
char ch[25];
int i,j,k,r,tc,cases,len,n,t,cnd,size,coun;
long long divs;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=3;i<6;i+=2){
        if(flag[i]==false){
            r=i+i;
            for(j=i*i;j<38;j+=r)
                flag[j]=true;
        }
    }
    for(i=3,j=1;i<38;i+=2){
        if(flag[i]==false) prime[j++]=i;
    }
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%s",&n,ch);
        len=strlen(ch);
		size=0;
        for(k=n;k>1;k-=len){
            t=k;
            cnd=sqrt(t)+1;
            for(i=0;prime[i]<cnd&&t!=1;i++){
                flag[0]=false;
                coun=0;
                while(t%prime[i]==0){
                    t/=prime[i];
                    coun++;
                    flag[0]=true;
                }
                if(flag[0]){
                    flag[1]=false;
                    for(j=0;j<size;j++){
                        if(arr[j].val==prime[i]){
                            flag[1]=true;
                            arr[j].countt+=coun;
                            break;
                        }
                    }
                    if(flag[1]==false){
                        arr[size].val=prime[i];
                        arr[size].countt=coun;
                        size++;
                    }
                }
            }
            if(t>1){
                flag[1]=false;
                for(j=0;j<size;j++){
                    if(arr[j].val==t){
                        flag[1]=true;
                        arr[j].countt++;
                        break;
                    }
                }
                if(flag[1]==false){
                    arr[size].val=t;
                    arr[size].countt++;
                    size++;
                }
            }
        }
        /*for(i=0;i<size;i++){
            printf("%d %d\n",arr[i].val,arr[i].countt);
        }*/
        printf("Case %d: ",++cases);
        for(i=0,divs=1,flag[0]=false;i<size;i++){
            divs*=arr[i].countt+1;
            if(divs>1000000000000000000){
                puts("Infinity");
                flag[0]=true;
                break;
            }
        }
        if(flag[0]==false)printf("%lld\n",divs);
        memset(arr,0,sizeof(arr));
    }
    return 0;
}

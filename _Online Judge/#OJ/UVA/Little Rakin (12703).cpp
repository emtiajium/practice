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

//const double PI=2*acos(0.0);
const int SIZE=1005;
int fib[45]={0,1},arr[SIZE],arr2[SIZE],finl[SIZE];
int t,cases,n,a,b,i,cnd,high,high2;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    for(i=2;i<43;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&a,&b);
        cnd=sqrt(a);
        for(i=2;i<=cnd;i++){
            while(a%i==0){
                a=a/i;
                arr[i]++;
            }
        }
        if(a>1) arr[a]++;
        high=max(i,a);
        cnd=sqrt(b);
        for(i=2;i<=cnd;i++){
            while(b%i==0){
                b=b/i;
                arr2[i]++;
            }
        }
        if(b>1) arr2[b]++;
        high2=max(i,b);
        high=max(high,high2);
        for(i=2;i<=high;i++){
            arr[i]=arr[i]*fib[n-1];
            arr2[i]=arr2[i]*fib[n];
            finl[i]=arr[i]+arr2[i];
        }
        for(i=2;i<=high;i++){
            if(finl[i]==0) continue;
            printf("%d %d\n",i,finl[i]);
        }
        puts("");
        memset(arr,0,sizeof(arr));
        memset(arr2,0,sizeof(arr2));
        memset(finl,0,sizeof(finl));
    }
    return 0;
}

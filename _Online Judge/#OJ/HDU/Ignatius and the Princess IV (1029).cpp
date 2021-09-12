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
struct TT{
    int val,coun;
};
TT arr[1000005];
int n,t,i,p,high;

bool comp(TT a,TT b){
    return a.coun>b.coun;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    while(scanf("%d",&n)==1){
        p=(n+1)>>1;
        high=0;
        for(i=0;i<n;i++){
            scanf("%d",&t);
            arr[t].val=t;
            arr[t].coun++;
            high=max(high,t);
        }
        high=high+2;
        sort(arr,arr+high,comp);
        for(i=0;i<high;i++){
            if(arr[i].coun>=p){
                printf("%d\n",arr[i].val);
                break;
            }
        }
        memset(arr,0,sizeof(arr));
    }
    return 0;
}

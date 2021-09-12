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
struct TT{
    int val,div;
};
TT arr[1005]={2147483647};
int i,j,cases;
bool comp(TT a,TT b){
    if(a.div==b.div) return a.val>b.val;
    return a.div<b.div;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    arr[1].val=arr[1].div=1;
    for(i=2;i<1001;i++){
        for(j=i;j<1001;j+=i){
            arr[j].div++;
        }
        arr[i].div++;
        arr[i].val=i;
    }
    sort(arr,arr+1001,comp);
    scanf("%d",&i);
    while(i--){
        scanf("%d",&j);
        printf("Case %d: %d\n",++cases,arr[j].val);
    }
    return 0;
}

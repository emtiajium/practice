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
const int INF=1<<20,SIZE=1005;
int arr[SIZE],I[SIZE],L[SIZE],LIS_arr[SIZE];
int n,i,LIS_len;

int LIS();
void output_LIS(int);

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        LIS_len=LIS();
        printf("len %d\n",LIS_len);
        //for(i=0;i<n;i++) printf("[%d] -> %d\n",arr[i],L[i]);
        output_LIS(LIS_len);
    }
    return 0;
}

int LIS(){
    int len=0,low,high,i,mid;
    I[0]=-INF;
    for(i=1;i<=n;i++) I[i]=INF;
    for(i=0;i<n;i++){
        low=0;
        high=len;
        while(low<=high){
            mid=(low+high)>>1;
            if(I[mid]<arr[i]) low=mid+1;
            else high=mid-1;
        }
        I[low]=arr[i];
        L[i]=low;
        if(len<low) len=low;
    }
    return len;
}

void output_LIS(int len){
    int i=0,j,top;

    for(j=1;j<n;j++){
        if(L[j]>L[i]) i=j;
    }
    top=L[i]-1;
    LIS_arr[top]=arr[i];
    top--;
    for(j=i-1;j>=0;j--){
        if(arr[j]<arr[i] && L[j]==L[i]-1){
            i=j;
            LIS_arr[top]=arr[i];
            top--;
        }
    }
    for(i=0;i<len;i++)
        printf("%d\n",LIS_arr[i]);
    puts("");
}

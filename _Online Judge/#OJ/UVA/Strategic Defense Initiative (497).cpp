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
const int inff=1<<30,SIZE=100005;
int arr[SIZE],I[SIZE],L[SIZE],LIS_arr[SIZE];
int t,test,n,i,LIS_len;
char str[25];

int LIS();
void output_LIS(int);

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--){
        if(test) puts("");
        n=0;
        while(gets(str)){
            if(str[0]==NULL) break;
            arr[n++]=atoi(str);
        }
        //for(i=0;i<n;i++) printf("input %d\n",arr[i]);
        LIS_len=LIS();
        printf("Max hits: %d\n",LIS_len);
        output_LIS(LIS_len);
        test++;
    }
    return 0;
}

int LIS(){
    int len=0,low,high,i,mid;
    I[0]=-inff;
    for(i=1;i<=n;i++) I[i]=inff;
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
        if(L[j]>=L[i]) i=j;
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
}

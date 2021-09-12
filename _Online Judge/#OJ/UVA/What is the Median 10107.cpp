//What is the Median? 10107
#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[10010];
int i=0,med;
int main()
{
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&arr[i])==1){
        i++;
        sort(arr,arr+i);
        if(i%2==0) med=(arr[i/2]+arr[i/2-1])/2;
        else med=arr[i/2];
        printf("%d\n",med);
    }
    return 0;
}

#include<stdio.h>
int arr[55];
struct TT{
    int minn,maxx;
};
TT val;
int n,i;
TT find(int arr[],int n,int i){
    TT local;
    local={arr[i],arr[i]};
    if(i==n-1) return local;
    local=find(arr,n,i+1);
    local.minn=((arr[i] > local.minn)? local.minn : arr[i]);
    local.maxx=((arr[i] > local.maxx)? arr[i] : local.maxx);
    return local;
}
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        val=find(arr,n,0);
        printf("%d %d\n",val.maxx,val.minn);
    }
    return 0;
}

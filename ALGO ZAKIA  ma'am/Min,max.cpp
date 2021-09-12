// Given a Tree, is it possible to find the greatest and least among leaves in linear time?

#include<stdio.h>

#define max(a,b) (a > b? a : b);
#define min(a,b) (a > b? b : a);

int arr[55];
struct TT{
    int minn,maxx;
};
TT val;
int n,i;

TT find(int array[],int low,int high){
    TT local,local2;
	int mid;
    if(low==high){
        local.maxx=array[low];
        local.minn=array[low];
        return local;
    }
    mid=(low+high)/2;
    local=find(array,low,mid);
    local2=find(array,mid+1,high);
    local.maxx=max(local.maxx,local2.maxx);
    local.minn=min(local.minn,local2.minn);
    return local;
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        val=find(arr,0,n-1);
        printf("%d %d\n",val.maxx,val.minn);
    }
    return 0;
}

#include<stdio.h>
int t,n,count,i,avg,sum;
double percentage;
int arr[1010];
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0,sum=0;i<n;i++){
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }
        avg=sum/n;
        for(i=0,count=0;i<n;i++){
            if(arr[i]>avg) count++;
        }
        percentage=((double)count*100.0)/(double)n;
        printf("%0.3lf%%\n",percentage);
    }
    return 0;
}

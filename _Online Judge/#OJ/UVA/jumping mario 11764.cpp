#include<stdio.h>
int arr[52];
int main()
{
    int t,n,i,j,k,upper,lower;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        upper=0;
        lower=0;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
        }
        for(j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1]) lower++;
			else if(arr[j]<arr[j+1]) upper++;
        }
            printf("Case %d: %d %d\n",i,upper,lower);
    }
    return 0;
}

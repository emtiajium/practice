#include<stdio.h>
int arr[25]={0};
int n,k,p,t,c,i,j;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%d %d %d",&n,&k,&p);
        for(i=1;i<=n;i++)
            arr[i]=i;

        for(i=1,j=k;i<=p;i++){
            j++;
            if(arr[j]==0 || arr[j]>n) j=1;
        }
        printf("Case %d: %d\n",c,arr[j]);
    }
    return 0;
}
/*
for(i=1;i<=t;i++){
    scanf("%d %d %d",&n,&k,&p);
    printf("Case %d: %d\n",i,((k-1)+p)%n+1);
}
*/

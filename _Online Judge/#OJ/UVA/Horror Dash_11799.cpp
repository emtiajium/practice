#include<stdio.h>
int arr[110];
int t,c,size,i,max;
int main()
{
    scanf("%d",&t);
    for(c=1;c<=t;c++){
        scanf("%d",&size);

        for(i=0;i<size;i++)
            scanf("%d",&arr[i]);

        for(i=0,max=arr[0];i<size;i++){
            if(arr[i]>max) max=arr[i];
        }
        printf("Case %d: %d\n",c,max);
    }
    return 0;
}

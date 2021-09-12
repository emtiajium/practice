#include<stdio.h>
int a[9];
int main()
{
    int n,i,j,p;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&p);
        for(j=0;j<p;j++)
            scanf("%d",&a[j]);
        printf("Case %d: %d\n",i,a[p/2]);
    }
    return 0;
}

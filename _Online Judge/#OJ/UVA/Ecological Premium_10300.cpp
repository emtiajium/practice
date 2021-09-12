#include<stdio.h>
int a[19][3];
int main()
{
    int t,f,i,j;
    long long sum;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        sum=0;
		scanf("%d",&f);
        for(j=0;j<f;j++)
        {
            scanf("%d %d %d",&a[j][0],&a[j][1],&a[j][2]);
            sum+=(long long)a[j][0]*(long long)a[j][2];
        }
        printf("%lld\n",sum);

    }
    return 0;
}

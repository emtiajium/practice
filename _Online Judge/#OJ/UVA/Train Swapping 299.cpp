#include<stdio.h>
int a[55];
int main()
{
	int t,n,i,j,k,N,sum,x;
	scanf("%d",&t);
	for(x=1;x<=t;x++)
	{
	    sum=0;
	    scanf("%d",&N);
	    for(i=0;i<N;i++)
	    {
	        scanf("%d",&a[i]);
	    }
	    for(i=0;i<N-1;i++)
	    {
	        for(j=0;j<N-1-i;j++)
	        {
	            if(a[j]>=a[j+1])
	            {
	                k=a[j];
	                a[j]=a[j+1];
	                a[j+1]=k;
	                sum++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",sum);
	}
    return 0;
}

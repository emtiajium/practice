#include<stdio.h>
int a[1002];
int main()
{
	register int i,j,k,N,count;
	while(scanf("%d",&N)==1)
	{
	    count=0;
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
	                if(!(a[j]>=a[j+1]))count++;
                }
            }
        }
        printf("Minimum exchange operations : %d\n",count);
    }
    return 0;
}

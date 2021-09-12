int a[1200000];
int b[1200000];

int LIS(int n)
{
    int i,j,l,r,m=0,mid;
    b[0]=-(-1u/2);
    for(i=1;i<=n;i++)
        b[i]=-1u/2;

    for(i=0;i<n;i++)
    {
        l=0;r=i+1;
        while(l<r)
        {
            mid=(l+r)/2;
            if(b[mid]<a[i]) l=mid+1;else r=mid;
        }
        b[r]<?=a[i];
        m>?=r;
    }
    return m;
}






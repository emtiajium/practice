#include<stdio.h>

typedef int LL;
LL a[1200000];
LL b[1200000];
LL p[1200000];

void go(int t)
{
    if(!t)  return ;
    go(p[t]);
    printf("%d\n",a[t]);
}

int main()
{
    //freopen("in.in","r",stdin);

    int i,j,l,r,m,n=1,mid,t;


    while(scanf("%d",&a[n])==1) n++;

    m=0;
    b[0]=0;
    a[0]=-(-1u/2);
    a[n]=-1u/2;
    for(i=1;i<n;i++)    b[i]=n;
    for(i=1;i<n;i++)
    {
        l=0;r=i;
        while(l<r)
        {
            mid=(l+r)/2;
            if(a[b[mid]]<a[i])    l=mid+1; else r=mid;
        }
        //printf("%d %d\n",r,a[i]);
        p[i]=b[r-1];
        if(a[b[r]]>a[i])    b[r]=i;
        if(r>=m)
        {
            m=r;
            t=i;
        }
    }

    printf("%d\n-\n",m);
    go(t);

    return 0;
}



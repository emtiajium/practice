#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<math.h>

using namespace std;

#define sz 10009

bool f[sz];
int p[sz],np[sz];

void sieve()
{
    int i,j,k,c=0;
    memset(f,true,sizeof f);
    memset(np,0,sizeof np);

    p[c++]=2;
    np[2]++;
    for(i=3;i<sz;i+=2)
        if(f[i])
        {
            p[c++]=i;
            np[i]++;
            if(sz/i>=i) for(j=i*i; j<sz ;j+=i+i)  f[j]=false;
        }

    for(i=2;i<sz;i++)
        if(!np[i])
        {
            for(j=0;p[j]<i;j++)
                if(i%p[j]==0)
                {
                    np[i]=1+np[i/p[j]];
                    break;
                }

        }
}

int a[100];

int main()
{
    sieve();

    int i,j,k,l,n,m,tst,tks,ks=1,mx,cnt;
    //freopen("in.in","r",stdin);

    scanf("%d",&tks);

    while(tks--)
    {
        memset(a,0,sizeof a);

        scanf("%d%d",&n,&m);

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                scanf("%d",&k);
                a[i]+=np[k];
            }

        k=a[0];
        for(i=1;i<n;i++)    k^=a[i];

        if(!k)  printf("Case #%d: NO\n",ks++);
        else printf("Case #%d: YES\n",ks++);
    }

    return 0;
}

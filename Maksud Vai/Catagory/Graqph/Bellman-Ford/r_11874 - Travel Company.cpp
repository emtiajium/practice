#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>

using namespace std;

#define ME 10000
#define MV 110

int A[ME],B[ME],D[ME],dis[MV];

bool BellmanFord(int N,int R)
{
    memset(dis,100,sizeof dis);
    dis[0]=0;
    int i,j;
    bool re;
    for(j=0;j<N;j++)
    {
        re=false;
        for(i=0;i<R;i++)
            if(dis[A[i]] + D[i]<dis[B[i]])
                dis[B[i]] = dis[A[i]]+D[i],re=true;
    }
    return re;
}

int main()
{
    int N,R,i,T,ks=1,P,I,E;

    //freopen("G.in","r",stdin);

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d%d%d",&N,&R,&P);

        for(i=0;i<R;i++)
        {
            scanf("%d%d%d%d",&A[i],&B[i],&I,&E);
            D[i] = P*E-I;
        }
        if(BellmanFord(N,R))    printf("Case %d: YES\n",ks++);
        else printf("Case %d: NO\n",ks++);

    }
    return 0;
}

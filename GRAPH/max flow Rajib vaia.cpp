//From Rajib vai
//*********************************820*********************************************
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<iostream>
#include<list>
#include<sstream>
#include<cmath>

#define N 109
#define MIN(A,B) (A>B?B:A)

using namespace std;
int f[N][N],bf[N][N];

int flow(int s,int d,int n)
{
    int u,v,i,j,k,par[N];
    for(i=0;i<n;i++)
    {
        par[i] = -1;
    }
    queue<int> Q;
    Q.push(s);
    while( !Q.empty() )
    {
         u = Q.front();Q.pop();
        for(v=0;v<n;v++)
        {
            if( s!=v && par[v]==-1 && f[u][v]-bf[u][v]>0 )
            {
                Q.push(v);
                par[v] = u;
            }
        }
    }
    if(par[d]==-1) return 0;
    int mf = INT_MAX;
    u = par[d];
    v = d;
    while( u!=-1 )
    {
        mf = MIN(mf,(f[u][v]-bf[u][v]));
        v = u;
        u = par[v];
    }
    if( mf==0 ) return 0;
    u = par[d];
    v = d;
    while( u!=-1 )
    {
        bf[u][v]+=mf;
        bf[v][u]=-bf[u][v];
        v = u;
        u = par[v];

    }
    return mf;
}

int main()
{
    int i,j,k,l,m,n,s,d,u,cost,v,cas=1;
    while( cin>>n )
    {
        if( !n ) break;
        cin>>s>>d>>m;
        s--;d--;
        while( m-- )
        {
            cin>>u>>v>>cost;
            u--;v--;
            f[u][v]+=cost;
            f[v][u]+=cost;
        }
        int sum = 0;
        while( int x = flow(s,d,n) )
        {
            sum+=x;
        }
        cout<<"Network "<<cas++<<endl;
        cout<<"The bandwidth is "<<sum<<"."<<endl<<endl;
        memset(f,0,sizeof(f));
        memset(bf,0,sizeof(bf));
    }

    return 0;
}

*******************************10330***************************************
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<iostream>
#include<list>
#include<sstream>
#include<cmath>

#define N 300
#define MIN(A,B) (A>B?B:A)

using namespace std;

int f[N][N],bf[N][N],vc[N];

int flow(int s,int d,int n)
{
    int i,k,j,par[N],u,v;
    for(i=0;i<=n;i++)
        par[i] = -1;
    queue<int> Q;
    Q.push(s);
    while( !Q.empty() )
    {
        u = Q.front();Q.pop();
        for(v=0;v<=n;v++)
        {
            if(s!=v && par[v]==-1 && f[u][v]-bf[u][v]>0)
            {
                Q.push(v);
                par[v] = u;
            }
        }
    }
    if(par[d]==-1) return 0;
    u = par[d];
    v = d;
    int mf = INT_MAX;
    while( u!=-1 )
    {
        mf = MIN(mf,f[u][v]-bf[u][v] );
        v = u;
        u = par[v];
    }
    if( mf==0  ) return 0;

    u = par[d];
    v = d;
    while( u!=-1 )
    {
        bf[u][v]+=mf;
        bf[v][u]=-bf[u][v];
        v = u;
        u = par[v];
    }
    return mf;
}

int main()
{
    int i,k,l,m,n,d,b,c,u,v;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&vc[i]);
            f[2*i-1][2*i] = vc[i];
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&c);
            f[2*u][2*v-1] = c;
        }
        scanf("%d %d",&b,&d);
        for(i=1;i<=b;i++)
        {
            scanf("%d",&c);
            f[0][2*c-1] = vc[c];
        }
        for(i=1;i<=d;i++)
        {
            scanf("%d",&c);
            f[2*c][2*n+1] = 10000000000;
        }

        int sum = 0;
        while( int x = flow(0,2*n+1,2*n+1) )
        {
            sum+=x;
        }
        printf("%d\n",sum);
        memset(f,0,sizeof(f));
        memset(bf,0,sizeof(bf));
    }
    return 0;
}

#include<iostream>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

#define sz 1000000
typedef long long LL;

int rnk[sz],par[sz];

struct E{
    int u,v;
    LL c;
    void scan(){
        scanf("%d%d%lld",&u,&v,&c);
        //cin>>u>>v>>c;
    }
    bool operator<(const E &b)const{return c>b.c;}
};

E e[sz];

void ini(int n)
{
    memset(rnk,0,sizeof rnk);
    for(int i=0;i<n;i++)    par[i]=i;
}



int FS(int u){
    if(u!=par[u])   par[u] = FS(par[u]);
    return par[u];
}

void L(int u,int v)
{
    if(rnk[u]>rnk[v])   par[v] = u;
    else {
        par[u]=v;
        if(rnk[u]==rnk[v])  rnk[v]++;
        }
}

LL MST(int n,int m)
{
    if(n==1) return 0;
    int i,x,y,cnt,mx;
    cnt=mx=0;
    priority_queue<E>q;
    E edg;

    for(i=0;i<m;i++)    q.push(e[i]);
    while(!q.empty())
    {
        edg=q.top();q.pop();
        x = FS(edg.u);
        y = FS(edg.v);
        if(x!=y)
        {
            L(x,y);
            mx = edg.c;
            if(++cnt==n-1)    return mx;
        }
    }

    return -1;
}

int main()
{
    int i,n,m;
    LL ans;

    while(scanf("%d%d",&n,&m)==2 &&(n||m))
    {
        ini(n);
        for(i=0;i<m;i++)    e[i].scan();
        ans = MST(n,m);
        if(ans==-1)   printf("IMPOSSIBLE\n");
        //else cout<<ans<<endl;
        else printf("%lld\n",ans);

    }

    return 0;
}


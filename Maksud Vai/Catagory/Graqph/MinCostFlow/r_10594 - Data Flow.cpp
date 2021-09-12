#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define MV 102

typedef long long LL;

LL  cst[MV][MV],
    cap[MV][MV],
    par[MV],dis[MV],
    source,sink,flow;

vector<int>adj[MV];

struct pq{
    LL d,n;
    void ini(LL a,LL b){n=a;d=b;}
    bool operator<(const pq &b)const{return d>b.d;}
};


bool PFS(int s,int sk)
{
    priority_queue<pq>Q;
    pq u,v;
    int i;

    memset(dis,50,sizeof dis);
    dis[1]=0;
    u.ini(1,0);
    Q.push(u);

    while(!Q.empty())
    {
        u=Q.top();Q.pop();
        for(i=0;i<(int)adj[u.n].size();i++)
            if(cap[u.n][adj[u.n][i]] && dis[u.n]+cst[u.n][adj[u.n][i]]<dis[adj[u.n][i]])
            {
                dis[adj[u.n][i]] = dis[u.n]+cst[u.n][adj[u.n][i]];
                v.ini(adj[u.n][i],dis[adj[u.n][i]]);
                Q.push(v);
                par[adj[u.n][i]]=u.n;
            }
    }

    if(dis[sk]<dis[0])  return true;
    return false;
}

void MakeResidal(int u)
{
    cst[par[u]][u]=cst[u][par[u]]=-cst[par[u]][u];
    cap[u][par[u]]++;
    cap[par[u]][u]--;
    if(u!=1)    MakeResidal(par[u]);
}

LL MinCostFlow(int s,int sk,LL f,LL lc)
{
    source=s;
    sink = sk;
    LL tt=0,cur;
    if(!f)  return 0;
    while(f && PFS(s,sk))
    {
        cur=f;
        if(f>lc)  cur=lc;
        f-=cur;
        tt+=cur*dis[sk];
        if(!f)  return tt;
        MakeResidal(sk);
    }
    return -1;
}

int main()
{
    int n,m,i,u,v;
    LL w,f,lc;
    //freopen("Data Flow.in","r",stdin);

    while(scanf("%d%d",&n,&m)==2)
    {
        for(i=1;i<=n;i++)
            adj[i].clear();
        memset(cap,0,sizeof cap);
        memset(cst,0,sizeof cst);

        while(m--)
        {
            //scanf("%d%d%lld",&u,&v,&w);   //%d -> %lld for w
            cin>>u>>v>>w;
            cst[u][v]=cst[v][u]=w;
            cap[u][v]=cap[v][u]=1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //scanf("%lld%lld",&f,&lc);   //%d -> %lld
        cin>>f>>lc;

        w = MinCostFlow(1,n,f,lc);
        if(w==-1)   printf("Impossible.\n");
        //else printf("%lld\n",w);  //%d -> %lld for w
        else cout<<w<<endl;
    }
    return 0;
}


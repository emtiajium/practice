/// Vertexs are numberd from 1 to n.

const int S = 100001;
int par[S][18],st[S],ft[S];
int lg,Time;
vector<int>g[S];

int mxv,miv;

void dfs(int u)
{
    int i,v,w;

    st[u]=Time++;

    for(i=1;i<=lg;i++)
        par[u][i]=par[ par[u][i-1] ][i-1];

    for(i=0;i<SZ(g[u]);i++)
    {
        v = g[u][i];
        if(v!=par[u][0])
        {
            par[v][0]=u;
            dfs(v);
        }
    }
    ft[u]=Time++;
}

bool IsAncestor(int a,int u){return st[a]<=st[u] && ft[u]<=ft[a];}

int LCA(int u,int v)
{
    int i;
    if(IsAncestor(u,v))   return u;
    if(IsAncestor(v,u))   return v;

    for(i=lg;i>-1;i--)
        if(!IsAncestor(par[u][i],v))    u=par[u][i];
    return par[u][0];
}

int main()
{
    int i,j,k,l,tks,ks=1,n,m,u,v,w,q,lca;

    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);

        for(i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            //u++;v++;
            g[u].PB(v);
            g[v].PB(u);
        }

        Time=0;
        lg = 1 + (log(n)/log(2.0));
        memset(par,-1,sizeof par);


        par[1][0]=1;
        dfs(1);

        printf("Case %d:\n",ks++);
        scanf("%d",&q);

        while(q--)
        {
            scanf("%d%d",&u,&v);
            //u++;v++;
            lca=LCA(u,v);
            cout<<"LCA : "<<lca<<endl;
        }

        if(tks) for(i=0;i<=n;i++)   g[i].clear();
    }

    return 0;
}




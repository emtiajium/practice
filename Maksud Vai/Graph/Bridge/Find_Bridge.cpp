/**
#  cnt is used for numbering or labeling the
            vertices of dfs tree in preorder.
#  VN[u] = lebel (or number) of vertices u.
#  f is used for flaging the edges.
*/



#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;



const int NV = 1001;

vector<int>adj[NV],en[NV],bridge;
int L[NV],H[NV],ND[NV],VN[NV],cnt;
int ED[NV*NV][2];
bool f[NV*NV];

void DFS(int u)
{
    L[u]=H[u]=VN[u] = cnt++;
    ND[u]=1;


    for(int v,i=0;i<(int)adj[u].size();i++)
    {
        if(!f[en[u][i]]) continue;

        f[en[u][i]] = false;
        v = adj[u][i];
        if(L[v]==-1)
        {
            DFS(v);

            ND[u]+=ND[v];
            L[u] = min(L[u],L[v]);
            H[u] = max(H[u],H[v]);

            /// Decide the Bridge
            if(L[v]>=VN[v] && H[v]<VN[v]+ND[v])
                bridge.push_back(en[u][i]);
        }

        L[u] = min(L[u],VN[v]);
        H[u] = max(H[u],VN[v]);
    }
}


void Find_Bridges()
{
    memset(f,true,sizeof f);
    memset(L,-1,sizeof L);

    bridge.clear();

    cnt=0;

    DFS(1);

    printf("Bridges are given below :\n");
    for(int i=0;(int)bridge.size();i++)
        printf("%d %d\n",ED[bridge[i]][0],ED[bridge[i]][1]);
}


int main()
{
    //freopen("in.in","r",stdin);

    int i,u,v,n,m,ks=1;

    while(scanf("%d%d",&n,&m)==2 &&(n||m))
    {
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
            en[i].clear();
        }

        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);

            ED[i][0]=u;
            ED[i][1]=v;

            adj[u].push_back(v);
            adj[v].push_back(u);
            en[u].push_back(i);
            en[v].push_back(i);
        }

        printf("%d\n\n",ks++);
        Find_Bridges();
        printf("#\n");
    }
    return 0;
}




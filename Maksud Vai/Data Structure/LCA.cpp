#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define N_N 100010
int N;
vector<int>adj[N_N];
int P[N_N][20],L[N_N],T[N_N];

void DFS(int u,int d)
{
    L[u]=d;
    for(int i=0;i<(int)adj[u].size();i++)
    {
        T[adj[u][i]]=u;
        DFS(adj[u][i],d+1);
    }
}



void Make(int n)
{
    N=n;
    int i,j;

    memset(P,-1,sizeof P);
    memset(T,-1,sizeof T);

    DFS(0,0);

    for(i=0;i<N;i++)    P[i][0]=T[i];

    for(j=1;1<<j <N;j++)
        for(i=0;i<N;i++)
            if(P[i][j-1]!=-1)
                P[i][j]=P[P[i][j-1]][j-1];
}

int Query(int p,int q)
{
    if(L[p]<L[q])   swap(p,q);
    int i,j;

    for(j=1; 1<<j <=L[p] ;j++);j--;

    for(i=j;i>=0;i--)  if(L[p]-(1<<i)>=L[q])   p=P[p][i];

    for(i=j;i>-1;i--)
        if(P[p][i] != -1 && P[p][i] != P[q][i])
            p=P[p][i],q=P[q][i];

    return T[p];
}

int main()
{
    //freopen("in.in","r",stdin);

    int i,n,u,v;



    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)    adj[i].clear();

        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&u,&v);
            adj[v].push_back(u);
        }

        Make(n);

        //cout<<"ok"<<endl;
        while(scanf("%d%d",&u,&v)==2&&(u||v))
        {
            cout<<u<<"  "<<v<<endl;
            cout<<Query(u,v)<<endl;
        }
    }


    return 0;
}

#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<utility>
#include<functional>
#include <deque>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <ctime>


#include<cmath>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

using namespace std;



///*******Start********


#define oo          (1<<30)
#define SZ(a)       ((int)a.size())
#define LL           long long


///*******Ready***********

struct pq{LL n,w;

    pq(LL nn=0,LL ww=0 ){n=nn;w=ww;}
    ///Longest Path
    bool operator<(const pq &b)const{return w<b.w;}
};


/// dd is the number or maximum Vertices.
const int dd=205;

LL cap[dd][dd],cst[dd][dd];
LL dis[dd],par[dd],flow;
vector<int>g[dd];


void AddEdge(int u,int v,int w,int c)
{
    /**
        w = Weight
        c = Capacity
    */
    cap[u][v]=c;
    cap[v][u]=0;
    cst[u][v]=w;
    cst[v][u]=-w;
    g[u].push_back(v);
    g[v].push_back(u);
}

bool FindPath(int source,int sink)
{
    priority_queue<pq>q;
    pq u;
    LL  i,no;

    ///Initialize dis and par.
    for(i=0;i<dd;i++)   dis[i]=-oo,par[i]=-1;

    dis[source]=0;
    q.push(pq(source,0));

    while(!q.empty())
    {
        u = q.top();q.pop();

        for(i=0;i<SZ(g[u.n]);i++)
        {
            no=g[u.n][i];
            if(cap[u.n][no]>0 && dis[no]<u.w+cst[u.n][no])
            {
                dis[no]=u.w+cst[u.n][no];
                par[no]=u.n;
                q.push(pq(no,dis[no]));
            }
        }
    }

    return dis[sink]>0; ///Path Check
}

void MR(int source,int u)
{

    flow=min(flow,cap[par[u]][u]);
    if(par[u]!=source)   MR(source,par[u]);
    cap[par[u]][u]-=flow;
    cap[u][par[u]]+=flow;
}


LL MinCostMaxFlow(int source,int sink)
{
    LL re=0;

    ///Because We need only four route.
    while(FindPath(source,sink))
    {
        flow=oo;        ///Check oo
        MR(source,sink);
        re+=flow*dis[sink];
    }
    return re;
}


///*******END************


int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.in","w",stdout);
    //ios_base::sync_with_stdio(false);

    int tks,ks=1,i,j,t;
    int mi, ni, pi, si, mt,m,S,T;
    LL re;

    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d%d",&m,&t);
        S=0;
        T=2*m+1;

        for(i=0;i<=T;i++)   g[i].clear();

        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d%d%d",&mi,&ni,&pi,&si,&mt);

            AddEdge(S,i,-mi,ni);
            AddEdge(m+i,T,pi,si);
            for(j=0;j<=mt && i+j<=m;j++)
                AddEdge(i,m+i+j,-t*(j),oo);

        }

        re=MinCostMaxFlow(S,T);

        printf("Case %d: %lld\n",ks++,re);
    }
    return 0;
}

/**
Outpur:
*******
Case 1: 20

*/

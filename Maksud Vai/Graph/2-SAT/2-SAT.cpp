///2-SAT

///http://www.codeforces.com/problemset/problem/27/D
/**
    Solution:
    a^b  = (!a || !b) && (a || b)

    if cluse is (a||b) then edges are :
        !a -> b
        !b -> a

    But for this Priblem,For one cluse (a XOR b) Edges are:
        a -> !b
        b -> !a
        !a -> b
        !b -> a


*/


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
#include <assert.h>


#include<cmath>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

#define SZ(a)       ((int)a.size())
#define pb          push_back
#define Clear(a,b)    memset(a,b,sizeof(a))







struct edg{
    int u,v;
    edg(int u=0,int v=0)
    {
        this->u=u;
        this->v=v;
    }
};

const int S=102;
edg ine[S];
vector<int>g[2*S],rg[2*S];
vector<int>order;
int col[2*S],componentNo=1,variableN;
int val[2*S];

void process(int u,int v,int m)
{
    g[u].pb(m+v);
    g[v].pb(m+u);
    rg[m+v].pb(u);
    rg[m+u].pb(v);

    g[m+u].pb(v);
    g[m+v].pb(u);
    rg[u].pb(m+v);
    rg[v].pb(m+u);
}


void buildGraph(int n)
{
    int i,j,a,b;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&ine[i].u,&ine[i].v);
        if(ine[i].u>ine[i].v)   swap(ine[i].u,ine[i].v);
    }

    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
        {
            a=b=0;
            a = (ine[i].u<ine[j].u && ine[j].u<ine[i].v && ine[j].v>ine[i].v);
            b = (ine[i].u<ine[j].v && ine[j].v<ine[i].v && ine[i].u>ine[j].u);
            if(a>b || b>a)
            {
                process(i,j,n);
            }
        }
}

void dfs(int u)
{
    col[u] = 1;
    for(int i=0;i<SZ(g[u]);i++)
        if(col[g[u][i] ]==0)
        {
            dfs(g[u][i]);
        }
    order.pb(u);
}

void sdfs(int u)
{
    col[u] = componentNo;
    for(int i=0;i<SZ(rg[u]);i++)
        if(col[rg[u][i] ]==0)
            sdfs(rg[u][i]);
}

void makeSCC()
{
    int i;
    Clear(col,0);
    for(i=1;i<=2*variableN;i++)
        if(col[i]==0)  dfs(i);

    componentNo=1;
    Clear(col,0);

    for(i = SZ(order)-1;i>-1;i--)
        if(col[ order[i] ]==0)
        {
            sdfs(order[i]);
            componentNo++;
        }
}

bool isSolution()
{
    for(int i=1;i<=variableN;i++)
        if(col[i]==col[variableN+i])    return false;
    return true;
}



void giveVal(int u,int v)
{
    if(val[u]<2)    return ;
    val[u] = v;
    for(int i=0;i<SZ(g[u]);i++)
        if(val[g[u][i] ]==2)
            giveVal(g[u][i],(col[u]==col[ g[u][i] ])?v:(v+1)%2);

    int com;
    if(u>variableN) com=u-variableN;
    else com = u+variableN;
    giveVal(com,(v+1)%2);
}

bool TWO_SAT(int n)
{
    int i;
    variableN = n;

    buildGraph(n);

    makeSCC();

    if(!isSolution())   return false;

    for(i=1;i<=2*variableN;i++) val[i] = 2;

    for(i=1;i<=2*variableN;i++)
        if(val[i]==2)   giveVal(i,0);

    return true;
}


int main()
{
//    freopen("in.in","r",stdin);
//    freopen("out.in","w",stdout);


    int i,j,k,tks,ks=1,n,m,a,b,u,v;

    while(scanf("%d%d",&n,&m)==2)
    {
        if(!TWO_SAT(m))   puts("Impossible");
        else
        {
            for(i=1;i<=m;i++)
                if(val[i ])   printf("%c",'o');
                else printf("%c",'i');
                cout<<endl;
        }
    }
    return 0;
}



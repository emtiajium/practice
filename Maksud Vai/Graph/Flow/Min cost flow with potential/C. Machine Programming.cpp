/**
    Flow with potential.

    VK Cup 2012 Round 3
    C. Machine Programming
    Link: http://www.codeforces.com/contest/164/problem/C
*/

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <set>
#include <cmath>
#include <cstring>

#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <assert.h>

using namespace std;

//Type Definition
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi>vvi;
typedef vector<string> vs;
typedef map<string,int> msi;
typedef map<int,int>mii;

#define ERR 1e-9
#define PI 3.141592653589793

#define REP(i,n) for (i=0;i<n;i++)
#define FOR(i,p,k) for (i=p; i<k;i++)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)

#define Sort(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())
#define MP(a,b) make_pair(a,b)
#define Clear(x,with) memset(x,with,sizeof(x))
#define SZ(x) (int)x.size()
#define pb push_back
#define popcount(i) __builtin_popcountll(i)
#define gcd(a,b)    __gcd(a,b)
#define lcm(a,b) ((a)*((b)/gcd(a,b)))
#define two(X) (1<<(X))
#define twoL(X) (((ll)(1))<<(X))
#define setBit(mask,i) (mask|two(i))
#define contain(S,X) (((S)&two(X))!=0)
#define fs first
#define sc second
#define CS c_str()
#define EQ(a,b) (fabs(a-b)<ERR)
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin());
#define Find(x,y) ((int)x.find(y))
#define all(a)  a.begin(),a.end()
#define rall(a)  a.rbegin(),a.rend()

//For debugging
#define debug_array(a,n) for(ll i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(ll i=0;i<row;i++) {for(ll j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define deb(a)  cout<<#a<<" #-> "<<a<<endl
#define debug(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"\t"; return *this; }}dbg;

//Important Functions
template<class T> void setmax(T &a, T b) { if(a < b) a = b; }
template<class T> void setmin(T &a, T b) { if(b < a) a = b; }
template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
template<class T> inline T Mod(T n,T m) {return (n%m+m)%m;} //For Positive Negative No.
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
ll toInt(string s){ll r=0;istringstream sin(s);sin>>r;return r;}
bool isVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
bool isUpper(char c){return c>='A' && c<='Z';}
bool isLower(char c){return c>='a' && c<='z';}
ll Pow(ll B,ll P){	ll R=1;	while(P>0)	{if(P%2==1)	R=(R*B);P/=2;B=(B*B);}return R;}
ll BigMod(ll B,ll P,ll M){	ll R=1;	while(P>0)	{if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}	return R;}
void binprint(ll mask,ll n){ll i;string s="";do{s+=(mask%2+'0');mask/=2;}while(mask);Reverse(s);s=string(max(n-SZ(s),0LL),'0')+s;for(i=SZ(s)-n;i<SZ(s);i++) printf("%c",s[i]);printf("\n");}
void ASCII_Chart(){ll i,j;int k;printf("ASCII Chart:(30-129)\n");FOR(i,30,50){REP(j,5){k=i+j*20;printf("%3d---> '%c'   ",k,k);}printf("\n");}}


#define SIZE 2010

struct Edg
{
    ll u,v,rev,cap,w,f;

    Edg(ll u=0,ll v=0,ll cap=0,ll w=0,ll rev=0)
    {
        this->u = u;
        this->v = v;
        this->cap = cap;
        this->w = w;
        this->rev = rev;
        f=0;
    }
};


const ll inf = 1000LL*9999999999LL;
int edgNo;
vector<Edg>edgs;
vector<int>g[SIZE];
int source,sink,N;
ll potential[SIZE],dis[SIZE],par[SIZE];
int mat[SIZE][SIZE];
Edg ea,eb;
int st[1001],ft[1001],c[1001];
int final[1001];



struct pq
{
    ll nod,cst;
    pq(ll nod=0,ll cst=0)
    {
        this->nod = nod;
        this->cst = cst;
    }
    bool operator<(const pq &b)const
    {
        return cst>b.cst;
    }
};

priority_queue<pq>Q;


void addEdge(int u,int v,int cap,int w)
{
    ea = Edg(u,v,cap,w,edgNo+1);
    eb = Edg(v,u,0,-w,edgNo);

    edgs.pb(ea);
    edgs.pb(eb);

    g[u].pb(edgNo);
    g[v].pb(edgNo+1);
    edgNo+=2;
}


bool isPath(int s,int t)
{
    ll up=1,e=1,i,j,u,v,cap,cst,val;
    pq U;


    for(i=1;i<=N;i++)   dis[i] = inf;
    dis[0]=0;

    Q.push(pq(s,0));


    while(!Q.empty())
    {
        U = Q.top();Q.pop();
        u = U.nod;

        cst = U.cst;
        if(cst>dis[u]) continue;

        for(i=0;i<SZ(g[u]);i++)
        {
            e = g[u][i];
            v = edgs[e].v;
            cst = edgs[e].w;
            cap = edgs[e].cap;
            val = potential[u]-potential[v]+cst+dis[u];
            if(cap>0 && dis[v]>val)
            {
                dis[v] = val;
                Q.push(pq(v,val));
                par[v] = e;
            }
        }
    }

    for(i=0;i<=N;i++)   potential[i]+=dis[i];

    return dis[t]<inf;
}


void update(int u)
{
    if(!u)  return ;
    Edg &a = edgs[ par[u] ];
    Edg &b = edgs[a.rev];
    a.f++;
    b.f--;

    a.cap-=1;
    b.cap+=1;
    mat[a.u][a.v] = 1;
    update(a.u);
}


void ff(int m)
{
    ll up=1,e=1,i,j,u,v,t,cst,ks=1,val;



    while(up)
    {
        up = 0;

        for(i=0;i<=N;i++)
        {
            for(j=0;j<SZ(g[i]);j++)
            {
                e = g[i][j];
                u = edgs[e].u;
                v = edgs[e].v;
                cst = edgs[e].w;
                t = edgs[e].cap;
                val = potential[u]+cst;
                if(t>0 && potential[v] > val)
                {
                    potential[v] = val;up=1;
                }
            }
        }

    }


    while(m-- && isPath(0,N))
    {
        update(N);
    }
}

map<int,int>mp;

int main()
{
//    freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);

    int i,j,test,Case=1,k,n,m,u,v;


    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&st[i],&ft[i],&c[i]);
        ft[i]+=st[i];
        mp[st[i] ]=0;
        mp[ft[i] ]=0;
    }

    N = 0;
    edgNo = 0;

    FOREACH(I,mp)   I->sc = N++;
    N--;
    source=0;
    sink  = N;

    for(i=0;i<n;i++)
    {
        final[i] = edgNo;
        u = mp[ st[i] ];
        v = mp[ ft[i] ];
        addEdge(u,v,1,-c[i]);
    }

    for(map<int,int>::iterator ita,itb = mp.begin(); itb!=mp.end() ;)
    {
        ita=itb;
        itb++;
        if(itb==mp.end())   break;
        addEdge(ita->sc,itb->sc,m,0);
    }



    ff(m);

    m = 0;
    for(i=0;i<n;i++)
    {
        if(m++) printf(" ");
        j = final[i];
        if(edgs[j].f>0)   printf("1");
        else printf("0");
    }
    printf("\n");



    return 0;
}

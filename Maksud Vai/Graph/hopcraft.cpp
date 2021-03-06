//#pragma comment(linker, "/STACK:60000000")

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
#define popcount(i) __builtin_popcount(i)
#define gcd(a,b)    __gcd(a,b)
#define lcm(a,b) ((a)*((b)/gcd(a,b)))
#define two(X) (1<<(X))
#define twoL(X) (((ll)(1))<<(X))
#define setBit(mask,i) (mask|two(i))
#define contain(S,X) (((S)&two(X))!=0)
#define X first
#define Y second
#define CS c_str()
#define EQ(a,b) (fabs(a-b)<ERR)
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin());
#define Find(x,y) ((int)x.find(y))

//For debugging
#define debug_array(a,n) for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define debug(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"\t"; return *this; }}dbg;

//Important Functions
template<class T> void setmax(T &a, T b) { if(a < b) a = b; }
template<class T> void setmin(T &a, T b) { if(b < a) a = b; }
template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
template<class T> inline T Mod(T n,T m) {return (n%m+m)%m;} //For Positive Negative No.
template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
bool isVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
bool isUpper(char c){return c>='A' && c<='Z';}
bool isLower(char c){return c>='a' && c<='z';}
ll Pow(ll B,ll P){	ll R=1;	while(P>0)	{if(P%2==1)	R=(R*B);P/=2;B=(B*B);}return R;}
int BigMod(ll B,ll P,ll M){	ll R=1;	while(P>0)	{if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}	return (int)R;}
void binprint(ll mask,ll n){ll i;string s="";do{s+=(mask%2+'0');mask/=2;}while(mask);Reverse(s);s=string(max(n-SZ(s),0LL),'0')+s;for(i=SZ(s)-n;i<SZ(s);i++) printf("%c",s[i]);printf("\n");}
void ASCII_Chart(){int i,j,k;printf("ASCII Chart:(30-129)\n");FOR(i,30,50){REP(j,5){k=i+j*20;printf("%3d---> '%c'   ",k,k);}printf("\n");}}


//int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2}; //Hexagonal Direction

//#include<conio.h> //for using getch();

//struct edge{ int cost,node; edge(int _cost=0,int _node=0){cost=_cost;node=_node;}bool operator<(const edge &b)const {return cost>b.cost;}}; // Min Priority Queue
//bool comp(edge a,edge b){ return a.cost < b.cost;} //Asc Sort by cost

#define INF (1<<28)
#define SIZE 40100
#define LIMIT 500000

bool flag[LIMIT+10];
int prime[(LIMIT/10)+100],total_prime;
map<int,int>MAP;

void seive()
{
    int i,j,r,c = 0;

    for(i=3;i<=LIMIT;i+=2) flag[i] = true;
    flag[2] = true;
    prime[c++] = 2;

    for(i=3;i<=LIMIT;i+=2)
        if(flag[i])
        {
            prime[c++] = i;
            if(i<=LIMIT/i)
            {
                r = i*2;
                for(j=i*i;j<=LIMIT;j+=r)
                    flag[j] = false;
            }
        }
    total_prime = c;
    return;
}

vector<int>adj[SIZE];
int L[SIZE],R[SIZE],N,d[SIZE],val[SIZE];
int color[SIZE];

bool BFS()
{
    queue<int>Q;
    int i,u,v;

    for(i=1;i<=N;i++)
        if(!L[i] && color[i] == 1){
             d[i] = 0, Q.push(i);
        }else if(color[i]==1) d[i] = INF;
    d[0] = INF;

    while(!Q.empty())
    {
        u = Q.front();Q.pop();

        if(!u) continue;
        for(i=0;i<adj[u].size();i++)
        {
            v = adj[u][i];

            if( d[R[v]] == INF)
            {
                d[ R[v] ] = d[u]+1;
                Q.push(R[v]);
            }
        }
    }
    return d[0]!=INF;
}

bool dfs(int u)
{
    if(!u) return true;
    int i,v;

    for(i=0;i<adj[u].size();i++)
    {
        v = adj[u][i];
        if( d[R[v]] == d[u]+1 && dfs(R[v]))
        {
            L[u] = v; R[v] = u;
            return true;
        }
    }
    d[u] = INF;
    return false;
}

int HopcroftKarp()
{
    int i,ret = 0;

    for(i=1;i<=N;i++) L[i] = 0,R[i] = 0;

    while(BFS())
    {
        for(i=1;i<=N;i++)
            if(!L[i] && color[i]==1 && dfs(i)) ret++;
    }
    return ret;
}

void build_graph(int u,int col)
{
    color[u] = col;
    for(int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];
        if(!color[v]) build_graph(v,3-col);
        assert(color[v] != col);
    }
    return;
}

int main()
{
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
    int i,j,test,Case=1;
    seive();

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d",&N);
        for(i=1;i<=N;i++)
            scanf("%d",&val[i]);

        sort(&val[1],&val[N+1]);
        MAP.clear();
        for(i=1;i<=N;i++)
        {
            MAP[val[i]] = i;
            adj[i].clear();
        }

        for(i=1;i<=N;i++)
        {
            int x = val[i];

            for(j=0;j<total_prime && prime[j]*x<=val[N];j++)
            {
                int ind = MAP[prime[j]*x];
                if(ind>0 && i!=ind)
                {
                    adj[i].pb(ind);
                    adj[ind].pb(i);
                }
            }
        }
        Clear(color,0);

//        if(val[i]==1 && N>1) color[1] = 3;
        for(i=1;i<=N;i++)
            if(!color[i]) build_graph(i,1);

//        for(i=1;i<=N;i++)
//            debug(i,color[i]);

//        debug("came here:");
        int ans = HopcroftKarp();
        cout<<ans<<endl;
        printf("Case %d: %d\n",Case++,N-ans);
    }

    return 0;
}


/*******
4
5
2 4 8 16 32
*********/

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
#define fs first
#define sc second
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
ll Pow(ll B,ll P){  ll R=1; while(P>0)  {if(P%2==1) R=(R*B);P/=2;B=(B*B);}return R;}
int BigMod(ll B,ll P,ll M){ ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (int)R;}
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
#define SIZE 1100

struct pq
{
    int node,cost;
    pq(int n,int c)
    {
        node = n;cost = c;
    }
    bool operator<(const pq &b)
        const{return cost>b.cost;}
};

struct data
{
    int st,dur,pro,ind;

    data(int a=0,int b=0,int c=0,int d=0)
    {
        st = a;dur = b;
        pro = c;ind = d;
    }
};
data task[1010];

bool comp(data p,data q)
{
    return p.st<q.st;
}

struct edge
{
    int u,v,cst,cap,rev,f;
    edge(int _u=0,int _v=0,int _cst=0,int _cap=0,int _rev=0,int _f=0)
    {
        u = _u; v = _v; cst = _cst; cap = _cap; rev = _rev; f = _f;
    }
};

vector<edge>adj[2010];
int Dist[2010];
pii par[2010];
int potential[2010];

pii addedge(int u,int v,int cst,int cap)
{
    pii ret = MP(u,SZ(adj[u]));

    adj[u].pb(edge(u,v,cst,cap,SZ(adj[v]),0));
    adj[v].pb(edge(v,u,-cst,0,SZ(adj[u])-1,0));

    return ret;
}

bool Dijkstra(int source,int sink)
{
    priority_queue<pq>Q;

    for(int i=0;i<=sink+1;i++) Dist[i] = INF;
    Dist[source] = 0;
    Q.push(pq(source,0));

    while(!Q.empty())
    {
        int u = Q.top().node;
        int c = Q.top().cost;
        Q.pop();
        if(c>Dist[u]) continue;

        for(int i=0;i<SZ(adj[u]);i++)
        {
            edge tmp = adj[u][i];
            int v = tmp.v;
            int td = Dist[u]+tmp.cst+potential[u]-potential[v];

            if(tmp.cap<=0) continue;
            if(td>=Dist[v]) continue;

            Dist[v] = td;
            par[v] = MP(u,i);
            Q.push(pq(v,Dist[v]));
        }
    }

    return Dist[sink]<INF;
}

void update_graph(int v,int source)
{
    if(par[v].fs!=source) update_graph(par[v].fs,source);

    edge &tmp = adj[par[v].fs][par[v].sc];
    edge &rev = adj[tmp.v][tmp.rev];

    tmp.cap--;
    rev.cap++;
    tmp.f++;
    rev.f--;
}

int MinCostMaxFlow(int source,int sink,int K)
{
    int ans = 0;

    while(K && Dijkstra(source,sink))
    {
        update_graph(sink,source);
        for(int i=0;i<=sink;i++) potential[i]+=Dist[i];
        K--;
    }


    ans = 0;
//    for(int i=0;i<=sink+1;i++)
//    {
//        for(int j=0;j<SZ(adj[i]);j++)
//        {
//            edge tmp = adj[i][j];
//            if(tmp.f>0){
//                ans+=tmp.f*tmp.cst;
//            }
//        }
//    }

    return ans;
}

int sol[1010];
map<int,int>MAP;
pii store[1010];

int main()
{
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);

    int i,j,test,Case=1;
    int N,K,st,dur,pro,source,sink,u,v;

    while(scanf("%d %d",&N,&K)==2)
    {
        vector<int>ele;

        for(i=1;i<=N;i++)
        {
            scanf("%d %d %d",&st,&dur,&pro);
            task[i] = data(st,dur,pro,i);
            ele.pb(st); ele.pb(st+dur);
        }

        sort(ele.begin(),ele.end());
        Unique(ele);

        MAP.clear();
        for(i=0;i<SZ(ele);i++) MAP[ele[i]] = i;

        source = 0; sink = SZ(ele)-1;
        for(i=0;i<=sink;i++) adj[i].clear();

        for(i=0;i<sink;i++)
        {
            addedge(i,i+1,0,K);
        }
        for(i=1;i<=N;i++)
        {
            u = MAP[task[i].st];
            v = MAP[task[i].st+task[i].dur];
            store[i] = addedge(u,v,-task[i].pro,1);
        }

        Clear(potential,0);

        bool up;
        do {
            up = false;
            for(i=0;i<=sink;i++)
            {
                u = i;
                for(j=0;j<SZ(adj[i]);j++)
                {
                    edge tmp = adj[i][j];
                    v = tmp.v;

                    if(tmp.cap==0) continue;
                    int c = potential[u] + tmp.cst;
                    if(c<potential[v])
                    {
                        potential[v] = c;
                        up = true;
                    }
                }
            }
        } while (up);

        int ans = MinCostMaxFlow(source,sink,K);


        for(i=1;i<=N;i++)
        {
            u = store[i].fs;
            v = store[i].sc;
            sol[i] = adj[u][v].f;
        }
        for(i=1;i<=N;i++)
            printf("%d ",sol[i]);
        printf("\n");
    }

    return 0;
}

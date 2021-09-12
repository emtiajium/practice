/**
    http://poj.org/problem?id=3608
*/
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

#define ERR 1e-7
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
template<class T> T abs(T x) {return x > 0 ? x : -x;}
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


//int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2}; //Hexagonal Direction

//#include<conio.h> //for using getch();

//struct edge{ int cost,node; edge(int _cost=0,int _node=0){cost=_cost;node=_node;}bool operator<(const edge &b)const {return cost>b.cost;}}; // Min Priority Queue
//bool comp(edge a,edge b){ return a.cost < b.cost;} //Asc Sort by cost

#define SIZE 10010


struct P
{
    double x,y;
    P(double x=0,double y=0)
    {
        this->x = x;
        this->y = y;
    }
    void scan(){
        scanf("%lf%lf",&x,&y);
    }
    void print(int i=0){
        printf("  %2d -> %10.3lf  %10.3lf\n",i,x,y);
    }
};

P MV(P a,P b){return P(b.x-a.x,b.y-a.y);}
P Add(P a,P b){return P(a.x+b.x,a.y+b.y);}
double Dot(P a,P b){return a.x*b.x+a.y*b.y;}
double Cro(P a,P b){return a.x*b.y-a.y*b.x;}
double Abs(P a){return sqrt(Dot(a,a));}
P Rotate(P a,double ang){return P( a.x*cos(ang)-a.y*sin(ang), a.x*sin(ang)+a.y*cos(ang));}
double findAng(P a,P b){    return acos(Dot(a,b)/Abs(a)/Abs(b));}
double Dis(P a,P b){return Abs(MV(a,b));}
P p[SIZE],q[SIZE],pvt;



double pointToSeg(P a,P b,P c)
{
    if(Dot(MV(b,c),MV(b,a))<0)  return Dis(b,a);
    if(Dot(MV(c,b),MV(c,a))<0)  return Dis(c,a);
    return abs(Cro(MV(b,c),MV(b,a))/Abs(MV(b,c)));
}

double segToSeg(P a,P b,P c,P d)
{
    double _m = pointToSeg(a,c,d);
    _m = min(_m,pointToSeg(b,c,d));
    _m = min(_m,pointToSeg(c,a,b));
    _m = min(_m,pointToSeg(d,a,b));
    return _m;
}


bool com(P a,P b)
{
    double c = Cro(MV(pvt,a),MV(pvt,b));
    if(EQ(c,0)) return Dis(pvt,a)<Dis(pvt,b);
    return c>0;
}

int makeConvexHull(P ar[],int n)
{
    int i,j;

    pvt = ar[0];
    FOR(i,1,n)  if(pvt.y>ar[i].y)   pvt = ar[i];
        else if(EQ(pvt.y,ar[i].y) && pvt.x>ar[i].x)   pvt = ar[i];

    sort(ar,ar+n,com);

    j=1;
    FOR(i,2,n)
    {
        while(j>0 && Cro(MV(ar[j-1],ar[j]),MV(ar[j-1],ar[i]))<ERR)  j--;
        ar[++j] = ar[i];
    }

    ar[++j] = ar[0];
    return j;
}


double minDisBetweenTwoConvexHull(int pn,int qn)
{
    int indP,indQ,i,j;
    indP = 0;
    indQ = 0;

    FOR(i,1,pn)
        if(p[indP].y>p[i].y) indP = i;
        else if(EQ(p[indP].y,p[i].y) &&  p[indP].x<p[i].x) indP = i;

    FOR(i,1,qn)
        if(q[indQ].y<q[i].y) indQ = i;
        else if(EQ(q[indQ].y,q[i].y) && q[indQ].x>q[i].x) indQ = i;


    double minDis = Dis(p[indP],q[indQ]);
    int np,nq;
    double anP,anQ,minAng;
    P pV = P(-100,0),qV = P(100,0);
    j=0;

    while(j<=pn+10)
    {
        np = indP<1 ? pn-1:indP-1;
        nq = indQ<1 ? qn-1:indQ-1;

        anP = findAng(pV,MV(p[indP],p[np]));
        anQ = findAng(qV,MV(q[indQ],q[nq]));

        if(EQ(anP,anQ))
        {
            minAng = anP;
            minDis = min(minDis,segToSeg(p[indP],p[np],q[indQ],q[nq]));
            indP = np;
            indQ = nq;
            j++;
        }
        else if(anP<anQ)
        {
            minAng = anP;
            minDis = min(minDis,pointToSeg(q[indQ],p[indP],p[np]));
            indP = np;
            j++;
        }
        else
        {
            minAng = anQ;
            minDis = min(minDis,pointToSeg(p[indP],q[indQ],q[nq]));
            indQ = nq;
        }

        pV = Rotate(pV,-minAng);
        qV = Rotate(qV,-minAng);
    }

    return minDis;
}


int main()
{
    int i,j,test,Case=1,pn,qn;

    while(scanf("%d%d",&pn,&qn)==2 && pn)
    {
        REP(i,pn)   p[i].scan();
        REP(i,qn)   q[i].scan();

        pn = makeConvexHull(p,pn);
        qn = makeConvexHull(q,qn);

        printf("%.10lf\n",minDisBetweenTwoConvexHull(pn,qn));
    }

    return 0;
}

/*
Problem Name : QTREE2
Problem Number : SPOJ 913
Link : https://www.spoj.pl/problems/QTREE2/
Problem Type : Search, LCA
Difficulty : 7 / 10
Interest : 9 / 10
Complexity : O(NlogN), O(logN)
Date : December 10, 2010
*/

#include <stdio.h>
#include <vector>
#include <time.h>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define MAXN 10000
#define MAXLOGN 14
//#define i64 __int64
#define i64 long long

vector< pair<int,int> > adj[MAXN+1];

int n;
i64 d[MAXN+1];
char flag[MAXN+1];
int root;
int L[MAXN+1];
int father[MAXN+1];
int A[MAXN+1][MAXLOGN+1];
i64 INF = 10000000;

void dfs(int cur) {
 flag[cur] = true;
 int i;
 rep(i,adj[cur].size()) {
  if(!flag[adj[cur][i].first]) {
   d[adj[cur][i].first] = d[cur] + adj[cur][i].second;
   father[adj[cur][i].first] = cur;
   L[adj[cur][i].first] = L[cur] + 1;
   dfs(adj[cur][i].first);
  }
 }
}

vector<string> parse(const string& s,const string& delim=" ") {
 vector<string>res;
 string t;
 for(int i=0;i!=s.size();i++) {
  if(delim.find(s[i]) != string::npos) {
   if(!t.empty()) {
    res.push_back(t);
    t="";
   }
  }
  else t+=s[i];
 }
 if(!t.empty()) res.push_back(t);
 return res;
}

void pre_process() {
 int i,j;
 for(i=1;i<=n;i++) for(j=0;(1<<j)<=n;j++) A[i][j] = -1;
 for(i=1;i<=n;i++) A[i][0] = father[i];
 for(j=1;(1<<j)<=n;j++) for(i=1;i<=n;i++) if(A[i][j-1] != -1) A[i][j] = A[A[i][j-1]][j-1];
}

int getLCA(int p, int q) {
 int i,log;
 if(L[p] < L[q]) swap(p,q);
 for(log=1;(1<<log)<=L[p];log++);
 log--;
 for(i=log;i>=0;i--) if(L[p] - (1<<i) >= L[q]) p = A[p][i];
 if(p == q) return p;
 for(i=log;i>=0;i--) {
  if(A[p][i] != -1 && A[p][i] != A[q][i]) {
   p = A[p][i];
   q = A[q][i];
  }
 }
 return father[p];
}


int getKth(int p, int q, int k, int LCA) {
 int d,log,i;
 if(LCA == p) {
  d = L[q] - L[p] + 1;
  swap(p,q);
  k = d - k + 1;
 }
 else if(LCA == q) ;
 else {
  if(L[p] - L[LCA] + 1 < k) {
   d = L[p] + L[q] - 2 * L[LCA] + 1;
   k = d - k + 1;
   swap(p,q);
  }
 }
 for(log=1;(1<<log)<=L[p];log++);
 log--;
 k--;
 for(i=log;i>=0;i--) if((1<<i) <= k) {
  p = A[p][i];
  k -= (1<<i);
 }
 return p;
}

int main() {
 int T;
 int i,a,b,c,k;
 i64 res;
 char s[100];
 int LCA;
 INF *= INF;
 vector<string> vs;
 scanf(" %d",&T);
 srand(time(NULL));
 while(T--) {
  scanf(" %d",&n);
  for(i=1;i<=n;i++) adj[i].clear(), d[i] = INF, flag[i] = false;
  for(i=1;i<n;i++) {
   scanf(" %d %d %d",&a,&b,&c);
   adj[a].push_back(make_pair(b,c));
   adj[b].push_back(make_pair(a,c));
  }
  root = rand() % n + 1;
  d[root] = 0;
  father[root] = -1;
  L[root] = 0;
  dfs(root);

  pre_process();

  gets(s);
  while(gets(s)) {
   if(s[1] == 'O') break;
   vs = parse(s);
   a = atoi(vs[1].c_str());
   b = atoi(vs[2].c_str());
   LCA = getLCA(a,b);
   assert(LCA >= 1 && LCA <= n);
   if(vs[0] == "DIST") {
    if(LCA == a || LCA == b) res = abs(d[a] - d[b]);
    else res = d[a] + d[b] - 2 * d[LCA];
   }
   else if(vs[0] == "KTH") {
    k = atoi(vs[3].c_str());
    res = getKth(a,b,k,LCA);
   }
   else assert(0);
   printf("%lld\n",res);
  }
  printf("\n");
 }
 return 0;
}

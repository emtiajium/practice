
//#include<bits/stdc++.h>
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

#define deb(a)      cerr<<" -> "<<#a<<"  "<<a<<endl;
#define popcount(a) (__builtin_popcountll(a))
#define SZ(a)       ((int)a.size())
#define fs           first
#define sc           second
#define pb          push_back
#define ll          long long
#define mp          make_pair
#define SS          stringstream
#define VS          vector<string>
#define VI          vector<int>
#define CON(a,b)  ((a).find(b)!=(a).end())
#define mem(a,b)    memset(a,b,sizeof(a))
#define Clear(a,b)    memset(a,b,sizeof(a))
#define memc(a,b)   memcpy(a,b,sizeof(b))
#define accu(a,b,c) accumulate((a),(b),(c))
#define fi(i,a,b)   for(i=a;i<b;i++)
#define fii(a,b)    for(i=a;i<b;i++)
#define fij(a,b)    for(j=a;j<b;j++)
#define fik(a,b)    for(k=a;k<b;k++)
#define fil(a,b)    for(l=a;l<b;l++)
#define ri(i,a)     for(i=0;i<a;i++)
#define rii(a)      for(i=0;i<a;i++)
#define rij(a)      for(j=0;j<a;j++)
#define rik(a)      for(k=0;k<a;k++)
#define ril(a)      for(l=0;l<a;l++)
#define fore(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define EQ(a,b)     (fabs((a)-(b))<ERR)
#define all(a)      (a).begin(),(a).end()
#define rall(a)      (a).rbegin(),(a).rend()
#define p2(a)       (1LL<<a)
#define EX(msk,a)   (msk&p2(a))



//#define debug(args...)          {dbg,args; cerr<<endl;}
//#define debug(args...)          {cout<<" #--> ";dbg,args; cerr<<endl;}
#define debug(a...)          {cerr<<" #--> ";dbg,a; cerr<<endl;}

struct debugger
{
    ///Collected from rudradevbasak
    template<typename T> debugger& operator , (const T v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;


const double pi=acos(-1.0);
const double eps=1e-7;

template<class TT>TT sqr(TT a){return a*a;}
template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
template<class ZZ>ZZ max(ZZ a,ZZ b,ZZ c){return max(a,max(b,c));}
template<class ZZ>ZZ min(ZZ a,ZZ b,ZZ c){return min(a,min(b,c));}
typedef pair<int,int> pii;

bool flag;

struct Nod
{
    Nod *next[10];
    int cnt;
    bool isPre;
};

char str[20];

void addChar(Nod *cur,int p,int l)
{
    int c = str[p]-'0';
    Nod *nxt;

    if(cur->next[c]==NULL)
    {
        cur->next[c] = new Nod();
        cur->next[c]->cnt=0;
        cur->next[c]->isPre = false;
    }

    nxt = cur->next[c];
    nxt->cnt++;



    if(p==l-1)
    {
        nxt->isPre=true;
    }
    else addChar(nxt,p+1,l);
}

void del(Nod *n)
{
    for(int i=0;i<10;i++)
        if(n->next[i]!=NULL)
        {
            if(n->next[i]->cnt>1 && n->next[i]->isPre)  flag=false;
            del(n->next[i]);

            delete n->next[i];
        }
}

int main()
{
//    freopen("in.in","r",stdin);
//    freopen("out.in","w",stdout);


    //ios_base::sync_with_stdio(false);
    //std::cout << std::setprecision(13)<<b<<std::endl;
    //assert(ks<0);

    int i,j,k,tks=1,ks=1,n,l;


    scanf("%d",&tks);

    while(tks--)
    {
        Nod *root = new Nod();
        flag = true;


        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",&str);
            l = strlen(str);
            addChar(root,0,l);
        }

        del(root);

        if(flag)
            printf("Case %d: YES\n",ks++);
            else printf("Case %d: NO\n",ks++);
    }

    return 0;
}



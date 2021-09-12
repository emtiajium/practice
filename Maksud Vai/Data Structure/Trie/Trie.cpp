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

#define SZ(a)       ((int)a.size())
#define PB          push_back

typedef struct{

    int nw,np;
    int re[26];

    void Initialize(){
        np=nw=0;
        memset(re,-1,sizeof re);
    }
}P;

P root;
vector<P>Tree;
string word;

void AddWord(int vertex,int p)  ///p means curent index of the word;
{
    if(p==SZ(word))
    {
        Tree[vertex].nw++;
        return ;
    }

    if(Tree[vertex].re[word[p]-97]==-1) /// If the word does not exist.
    {
        P ad;
        ad.Initialize();
        Tree.PB(ad);
        Tree[vertex].re[word[p]-97] = SZ(Tree)-1;
    }

    Tree[vertex].np++;
    AddWord(Tree[vertex].re[word[p]-97],p+1);
}

int CountWord(int vertex,int p)
{
    if(p==SZ(word)) return Tree[vertex].nw;
    if(Tree[vertex].re[word[p]-97]==-1) return 0;
    return CountWord(Tree[vertex].re[word[p]-97],p+1);
}

int CountPrefix(int vertex,int p)
{
    if(p==SZ(word)) return Tree[vertex].np;
    if(Tree[vertex].re[word[p]-97]==-1) return 0;
    return CountPrefix(Tree[vertex].re[word[p]-97],p+1);
}



int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.out","w",stdout);
    //ios_base::sync_with_stdio(false);

    int i,j,k,tks,ks=1,n,m;

    while(cin>>n && n)  ///Number of word
    {
        Tree.clear();   ///Initializ the tree.

        ///Initializ the root.
        root.Initialize();
        Tree.PB(root);

        while(n--)
        {
            cin>>word;
            AddWord(0,0);
        }

        cin>>m; ///Number of quary
        while(m--)
        {
            cin>>word;
            cout<<"Number of Prefix: "<<CountPrefix(0,0)<<endl;
            cout<<"Number of Word: "<<CountWord(0,0)<<endl;
        }
    }

    return 0;
}



#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>

using namespace std;

#define fi(i,a,b)   for(i=a;i<b;i++)
#define fd(i,a,b)   for(i=a;i>b;i--)
#define fii(a,b)   for(i=a;i<b;i++)
#define fdi(a,b)   for(i=a;i>b;i--)
#define fij(a,b)   for(j=a;j<b;j++)
#define fdj(a,b)   for(j=a;j>b;j--)
#define fik(a,b)   for(k=a;k<b;k++)
#define fdk(a,b)   for(k=a;k>b;k--)
#define fil(a,b)   for(l=a;l<b;l++)
#define fdl(a,b)   for(l=a;l>b;l--)
#define ri(i,a)    for(i=0;i<a;i++)
#define rd(i,a)    for(i=a;i>-1;i--)
#define rii(a)     for(i=0;i<a;i++)
#define rdi(a)     for(i=a;i>-1;i--)
#define rij(a)     for(j=0;j<a;j++)
#define rdj(a)     for(j=a;j>-1;j--)
#define rik(a)     for(k=0;k<a;k++)
#define rdk(a)     for(k=a;k>-a;k--)
#define ril(a)     for(l=0;l<a;l++)
#define rdl(a)     for(l=a;i>-1;l--)

typedef struct {int v,u;long long d;}E;
int nc,ne,par[1001],rnk[1001];
E edg[35800];
int comp(const void *a,const void *b){
    E *x = (E*)a,*y=(E*)b;
    return x->d - y->d;
    }

int FindSet(int x)
{
    if(par[x]!=x)
        par[x] = FindSet(par[x]);
    return par[x];
}

void Union(int x,int y)
{
    if(rnk[x]<rnk[y])
        par[x] = y;
    else {
        par[y] = x;
        if(rnk[x]==rnk[y])
        rnk[x]++;
    }
}


int main(){
    long long i,j,v,w,x,y,t;
    map<string,int>M;
    long long sv,su;

    while(cin>>nc>>ne &&(nc||ne))
    {


        rii(nc)rnk[i]=0,par[i]=i;

        rii(ne){cin>>su>>sv>>w; edg[i].u=su,edg[i].v=sv,edg[i].d=w;
        }

        qsort(edg,ne,sizeof(E),comp);
        w=0;
        t=0;
        rii(ne)
        {
            x = FindSet(edg[i].u) ,y= FindSet(edg[i].v);
            if(x!= y)
            {
                Union(x,y);
            }
            else {
                    if(t++) cout<<" ";
                   cout<<edg[i].d;

            }

        }
        if(!t)  cout<<"forest";


        cout<<endl;

    }
    return 0;
}

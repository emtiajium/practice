#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define p2(a)       (1LL<<a)

int g[16][16],n;
bool mm[1<<16][16];
double cal[1<<16][16];

double go(int msk,int c)
{
    if(mm[msk][c])  return cal[msk][c];
    mm[msk][c] = true;
    if(msk==p2(n)-1)    return cal[msk][c]=0.;

    int i,na=0;

    double s1=5.,s2=0,x;

    for(i=0;i<n;i++)
        if( (msk&p2(i)) == 0 && g[c][i])
        {
            x = go(msk|p2(i),i);
            if(x>=0.)
            {
                s1+=g[c][i];
                s2+=go(msk|p2(i),i);
                na++;
            }
        }

    if(na)  cal[msk][c]=(s1+s2)/na;
    else cal[msk][c]=-1.;
    return cal[msk][c];
}

int main()
{
    int ks=1,tks,u,v,w,m;
    double ans;
    //freopen("in.in","r",stdin);
    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d%d",&n,&m);
        memset(g,0,sizeof g);
        memset(mm,false,sizeof mm);

        while(m--){
            scanf("%d%d%d",&u,&v,&w);
            g[u][v]=g[v][u]=w;
        }
        ans=go(1,0);
        if(ans<0)   ans=0;
        printf("Case %d: %.10lf\n",ks++,ans);
    }

    return 0;
}


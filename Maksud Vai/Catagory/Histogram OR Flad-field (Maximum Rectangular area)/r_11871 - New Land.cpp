#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

typedef pair<int,int>PII;
stack<PII>stk;
PII T;

int mat[2002][2002];    //Take 0(Land) or 1(Water).
int cs[2002][2002];     //Number of consicutive 0 in a column.


int MAX_LAND(int r,int c)
{
    int mx=0,i,j;

    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            if(mat[i][j])   cs[i][j]=0;
            else cs[i][j] = cs[i-1][j]+1;

    for(i=1;i<=r;i++)
    {
        stk.push(PII(0,-1));
        for(j=1;j<=c;j++)
        {
            T = stk.top();
            if(T.second < cs[i][j])   stk.push(PII(j,cs[i][j]));
            else
            {
                while(!stk.empty())
                {
                    T = stk.top();
                    if(T.second==cs[i][j])  break;
                    stk.pop();
                    mx>?= T.second*(j-T.first);
                    if(stk.top().second<cs[i][j])
                    {
                        stk.push(PII(T.first,cs[i][j]));
                        break;
                    }
                }
            }
        }
        while(!stk.empty())
        {
            T = stk.top();
            stk.pop();
            mx>?= T.second*(c-T.first+1);
        }
    }
    return mx;
}

int main()
{
    int i,j,b,tks,ks=1,r,c,st,l,cur,t;
    //freopen("D.in","r",stdin);
    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d%d",&r,&c);
        for(i=1;i<=r;i++)
        {
            scanf("%d%d",&t,&b);
            cur=st=1;
            while(t--)
            {
                scanf("%d",&l);
                cur+=l;
                while(st<cur)   mat[i][st++]=b;
                b^=1;
            }
        }
        printf("Case %d: %d\n",ks++,MAX_LAND(r,c));

    }
    return 0;
}

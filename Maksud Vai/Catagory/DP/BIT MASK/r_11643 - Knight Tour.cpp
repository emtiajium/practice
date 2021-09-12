#include<iostream>
#include<string>
#include<queue>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

typedef struct{int x,y;}co;
int dis[1006][1006],n,mk[50000][17];

void BFS()
{
    queue<int>q;
    int i,r,c,ur,uc,
    dr[] = {2,2,1,1,-1,-1,-2,-2},
    dc[] = {1,-1,2,-2,2,-2,1,-1};
    memset(dis,-1,sizeof(dis));
    dis[2][2] = 0;
    q.push(2);q.push(2);

    while(!q.empty())
    {
        ur = q.front(); q.pop();
        uc = q.front(); q.pop();
        for(i=0;i<8;i++)
        {
            r = ur+ dr[i];  c = uc+ dc[i];
            if(r>-1 && c>-1 && r<1006 && c<1006 && dis[r][c]==-1)
            {
                q.push(r);  q.push(c);
                dis[r][c] = dis[ur][uc]+1;
            }
        }
    }
}

int DIS(co a,co b)
{

    if(
    (a.x==1 && a.y==1 && b.x==2 && b.y==2) ||
    (a.x==2 && a.y==2 && b.x==1 && b.y==1) ||
    (a.x==n-1 && a.y==n-1 && b.x==n && b.y==n) ||
    (a.x==n && a.y==n && b.x==n-1 && b.y==n-1) ||
    (a.x==1 && a.y==n && b.x==2 && b.y==n-1) ||
    (a.x==2 && a.y==n-1 && b.x==1 && b.y==n) ||
    (a.x==n && a.y==1 && b.x==n-1 && b.y==2) ||
    (a.x==n-1 && a.y==2 && b.x==n && b.y==1)
    )
        return 4;
    return dis[abs(a.x-b.x)+2][abs(a.y-b.y)+2];
}

int main()
{
    int i,j,t,k,m,ks=1,c,l;
    co s,a[17];
    BFS();
    //freopen("in.in","r",stdin);
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&k);
        scanf("%d%d",&s.x,&s.y);
        k--;
        if(!k)  {printf("Case %d: 0\n",ks++);continue;}

        for(i=0;i<k;i++)
            scanf("%d%d",&a[i].x,&a[i].y);

        m = 1e9;
        l = 1<<k;

        for(i=1;i<l;i++)
            for(j=0;j<k;j++)
                mk[i][j] = m;

        for(i=0;i<k;i++)
            mk[(1<<i)][i] = DIS(s,a[i]);

        for(i=1;i<l;i++)
            for(j=0;j<k;j++)
                if( (i|(1<<j)) > i)
                {
                    for(c=0;c<k;c++)//if(j!=c)
                        mk[i|(1<<j)][j] <?= mk[i][c]+ DIS(a[c],a[j]);
                }
        l--;
        for(i=0;i<k;i++)
            m <?= mk[l][i]+DIS(a[i],s);
        printf("Case %d: %d\n",ks++,m);
    }
    return 0;
}

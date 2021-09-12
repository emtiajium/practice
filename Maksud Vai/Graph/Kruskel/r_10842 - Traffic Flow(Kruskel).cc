#include	<stdio.h>
#include	<stdlib.h>
#include	<vector>

#define INF 2000000

typedef struct
{
	int u,v,w;
}NOD;

NOD nod[10010];
int rank[10010],par[10010];

int comp(const void *a,const void *b)
{
	NOD *x = (NOD *) a;
	NOD *y = (NOD *) b;
	return x->w - y->w;
}

void MS(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		par[i] = i;
		rank[i] = 0;
	}
}

int FS(int x)
{
	if(x != par[x])
		par[x] = FS(par[x]);

	return par[x];
}

void LK(int x,int y)
{
	if(rank[x]>rank[y])
		par[y] = x;
	else
	{
		par[x] = y;
		if(rank[x] == rank[y])
			rank[y]++;
	}
}
void U(int x,int y)
{
	LK(FS(x),FS(y));
}

int main()
{
	int i,j,n,m,x,max,t=1,T,u,v,w,k;
//	freopen("in.txt","r",stdin);

	scanf("%d",&T);
	T++;
	for(t=1;t<T;t++)
	{
		scanf("%d%d",&n,&m);
		MS(n);
		for(i=0,k=0;k<m;i++,k++)
		{
			scanf("%d%d%d",&u,&v,&w);
			if(u==v)
			{
				i--;
				continue;
			}

			nod[i].u = u;	nod[i].v = v;	nod[i].w = w;
		}
		m = i ;
		qsort(nod,m,sizeof(NOD),comp);


		for(i=m-1,max = INF ;i>-1;i--)
			if(FS(nod[i].u) != FS(nod[i].v))
			{
				if( max > nod[i].w )
					max = nod[i].w;
				U(nod[i].u ,nod[i].v);
			}
		printf("Case #%d: %d\n",t,max);
	}
	return 0;
}

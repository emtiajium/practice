#include <stdio.h>
#include <algorithm>
using namespace std;

struct edge
{
	int u,v,cost;
}ed[100];

int par[100];

bool compare(edge a, edge b)
{
	if(a.cost<b.cost)
		return 1;
	else 
		return 0;
}

int find_par(int a)
{
	while(par[a]!=a)
	{
		a=par[a];
	}
	return a;
}

bool join(int u, int v)
{
	int x,y;
	x=find_par(u);
	y=find_par(v);
	if(x==y)
		return 0;
	else
	{
		par[x]=y;
		//par[y]=z;
		return 1;
	}
}

int main()
{
	int a,b,c,i,nd,edg,total,count;
	scanf("%d %d",&nd,&edg);
	for(i=0;i<edg;i++)
		scanf("%d %d %d",&ed[i].u,&ed[i].v,&ed[i].cost);
	for(i=1;i<=nd;i++)
		par[i]=i;
	sort(ed,ed+edg,compare);
	total=0;
	count=0;
	for(i=0;i<edg;i++)
	{
		a=ed[i].u;
		b=ed[i].v;
		c=ed[i].cost;
		if(join(a,b))
		{
			total+=c;
			count++;
		}
	}
	if(count!=nd-1)
		printf("MST not possible\n");
	else
	printf("%d\n",total);
	return 0;
}

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct{
	int x,y;
}P;

P p[50],stk[50],pevot;
int T,n;

int cross(P a,P b,P c){
	return ((b.x-a.x)*(c.y-a.y)) - ((b.y-a.y)*(c.x-a.x));
}

int comp(const void *a,const void *b)
{
	int c;
	P *n = (P*) a;	
	P *m = (P*) b;	
	
	c = cross(pevot,*m,*n);

	if(c)
		return c;
	else if(pow(pevot.x - n->x,2) + pow(pevot.y - n->y,2) > pow(pevot.x - m->x,2) + pow(pevot.y - m->y,2) ) 
		return 1;
	else if(pow(pevot.x - n->x,2) + pow(pevot.y - n->y,2) < pow(pevot.x - m->x,2) + pow(pevot.y - m->y,2) )  
		return -1;	

	return 0;
}

bool GS()
{
	int i;
	T=0;
	stk[T++] = p[0];	
	stk[T++] = p[1];	
	stk[T++] = p[2];	
	
	for(i=3;i<n;i++)
	{	
		if(cross(stk[T-2],stk[T-1],p[i]) < 0) // 0 or 1 no fact 
			return true;
		stk[T++] = p[i];
	}	
	return false;
}

int main()
{
	int i,j,x;
	
	while(scanf("%d",&n)==1&& n)
	{
		x=0;
		for(i=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		pevot = p[0];
		for(i=1;i<n;i++)
			if(pevot.y > p[i].y)
				pevot = p[i];
			else if(pevot.y == p[i].y && pevot.x > p[i].x)
				pevot = p[i];
			
		qsort(p,n,sizeof(P),comp);	
		
		
		if(GS())
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}

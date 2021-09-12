#include	<stdio.h>
#include	<stdlib.h>
#include	<math.h>


typedef struct{
	int x,y;
	}P;

P p[102],stk[102],pvt;
int T;	
	
int Cross(P a,P b,P c){
		return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
	}		
	
int comp(const void *a,const void *b)	{
	int c;
	
	P *X = (P*) a;	
	P *Y = (P*) b;	
	
	c = Cross(pvt,*Y,*X);
	
	if(c)
		return c;
	else if(pow(pvt.x-X->x,2)+pow(pvt.y-X->y,2) > pow(pvt.x-Y->x,2)+pow(pvt.y-Y->y,2))
		return 1;	
	else if(pow(pvt.x-X->x,2)+pow(pvt.y-X->y,2) < pow(pvt.x-Y->x,2)+pow(pvt.y-Y->y,2))
		return -1;	
	
	return 0;	
}


	
void Grhams_Scan(int n)	{
	int i;
	T=0;
	
	stk[T++] = p[0];
	stk[T++] = p[1];
	stk[T++] = p[2];
	
	for(i=3;i<n;i++){
		while( Cross(stk[T-2],stk[T-1],p[i]) < 0 )
			T--;
		stk[T++] = p[i];	
		}
	}
	
int main()
{
	int n,i,j,m,t=1,w;	
	double x,A_tile,A_convex,ar;
	
	while(scanf("%d",&n)==1 && n)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);

		pvt = p[0];
		for(i=1;i<n;i++)
			if(pvt.y > p[i].y)
				pvt = p[i];
			else if(pvt.y == p[i].y && pvt.x > p[i].x)
				pvt = p[i];
		
		p[n] = p[0]; 
		ar = 0 ;
		for(i=0;i<n;i++)
			ar += ( p[i].x * p[i+1].y - p[i].y * p[i+1].x);
		if(ar<0)	ar *= -1;
		A_tile = ar /2.0;		
		
		qsort(p,n,sizeof(P),comp);
			
		Grhams_Scan(n);
		
		stk[T] = stk[0]; 
		ar = 0 ;
		for(i=0; i < T ;i++)
			ar += ( stk[i].x * stk[i+1].y - stk[i].y * stk[i+1].x);
		if(ar<0)	ar *= -1;
		
		A_convex = ar /2.0;		

		x = A_convex - A_tile;
		printf("Tile #%d\nWasted Space = %.2lf %\n\n",t++,(x/A_convex)*100);			
	}

	return 0;
}

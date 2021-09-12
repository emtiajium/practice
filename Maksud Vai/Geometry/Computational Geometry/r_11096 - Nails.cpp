#include	<stdio.h>
#include	<stdlib.h>
#include	<math.h>

typedef struct{long long x,y;}P;

P p[102],stk[102],pevot;

long long T;

int cross(P a,P b,P c){
	if((b.x-a.x)*(c.y-a.y) > (c.x-a.x)*(b.y-a.y))
		return 1;
	else if((b.x-a.x)*(c.y-a.y) < (c.x-a.x)*(b.y-a.y))
		return -1;
	return 0;
}

int  comp(const void *a,const void *b)
{
	int c;
	P *X = (P*) a;
	P *Y = (P*) b;

	c = cross(pevot,*Y,*X);
	if(c)
		return c;
	if((pow( (pevot.x - X->x), 2) + pow( (pevot.y - X->y), 2) ) > ( pow( (pevot.x - Y->x),2) + pow( (pevot.y - Y->y), 2) ) )
		return 1;
	return -1;
}


int main()
{	
	long long i,j,t,k,n,m;
	double il,fl;
	P temp,min;

	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lf%lld",&il,&n);
		scanf("%lld%lld",&p[0].x,&p[0].y);
		pevot=p[0];
		for(i=1;i<n;i++)
		{
			scanf("%lld%lld",&p[i].x,&p[i].y);
			if(pevot.y > p[i].y)
				pevot=p[i];
			else if(pevot.y == p[i].y && pevot.x > p[i].x)
					pevot = p[i];
			
		}
		if(n==1)
		{
			printf("%.5lf\n",il);
			continue;
		}
		if(n==2)
		{
			fl = 2*sqrt(pow(p[0].x - p[1].x,2)+pow(p[0].y - p[1].y,2));	
			
			if(fl>il)
				printf("%.5lf\n",fl);
			else
				printf("%.5lf\n",il);
			
			continue;	
		}
		qsort(p,n,sizeof(P),comp);

		T = 0;

		stk[T++] = 	p[0];
		stk[T++] = 	p[1];
		stk[T++] = 	p[2];

		for(i=3;i<n;i++)
		{
			while(cross(stk[T-2],stk[T-1],p[i]) < 0)
				T--;
			stk[T++] = 	p[i];
		}

		for(fl=0,i=1;i<T;i++)
			fl += sqrt( pow( stk[i-1].x - stk[i].x,2) + pow( stk[i-1].y - stk[i].y,2));
		fl += sqrt( pow( stk[0].x - stk[i-1].x,2) + pow( stk[i-1].y - stk[0].y,2));
		
		if(fl>il)
			printf("%.5lf\n",fl);
		else
			printf("%.5lf\n",il);
	}

	return 0;
}

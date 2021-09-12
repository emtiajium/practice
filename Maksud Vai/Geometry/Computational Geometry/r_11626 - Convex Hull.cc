#include	<stdio.h>
#include	<stdlib.h>
#include	<math.h>
#include	<algorithm>

using namespace std;

typedef struct{long long x,y;} P;
P p[100004],pvt;
int T;

long long Cross(P a,P b,P c){	
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x) ;	
}

int comp(const void *a,const void *b){
	long long c;
	
	P *X = (P*) a;
	P *Y = (P*) b;
	
	c = Cross(pvt,*Y,*X);
	
	if(c>0)	return 1;
	else if(c<0) return -1;
	else if( pow(pvt.x - X->x,2) + pow(pvt.y - X->y,2)  > pow(pvt.x - Y->x,2) + pow(pvt.y - Y->y,2)  ) 
		return 1;
	else if( pow(pvt.x - X->x,2) + pow(pvt.y - X->y,2)  < pow(pvt.x - Y->x,2) + pow(pvt.y - Y->y,2)  ) 
		return -1;
	return 0;
}

bool com(P a,P b)
{
	if( a.y < b.y )
		return false;
	return true;
}

int main()
{
	int t,n,i,j,m,A,B,C;
	char ty[3];

	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&m);
		
		for(i=n=0;i<m;i++)
		{
			scanf("%lld%lld%s",&p[n].x,&p[n].y,ty);
			if(ty[0] == 'Y')
				n++;
		}
		

		pvt = p[0];
		for(i=1;i<n;i++)
			if(pvt.y>p[i].y)
				pvt = p[i];
				else if(pvt.y==p[i].y && pvt.x>p[i].x)
					pvt = p[i];
				
		qsort(p,n,sizeof(P),comp);			
		A = p[0].y - p[n-1].y;
		B = p[n-1].x - p[0].x;		
		C = p[0].y * p[n-1].x -	p[0].x * p[n-1].y;	
				
		m = n ;		
		
		for(i=n-1;i>0;i--)		
			if(A*p[i].x + B*p[i].y == C)
				m = i;
			else 
				break;
		if(m != n)	
			sort(&p[m],&p[n],com);		
		
		printf("%d\n",n);
		pvt = p[0];		
		j=0;		
		for(i=1;i<n;i++)		
			if(pvt.x > p[i].x)
			{
				pvt = p[i];
				j = i;				
			}
			else if(pvt.x == p[i].x && pvt.y > p[i].y)
			{
				pvt = p[i];
				j = i;				
			}
				
		for(i=j;i<n;i++)
			printf("%lld %lld\n",p[i].x,p[i].y);
		for(i=0;i<j;i++)
			printf("%lld %lld\n",p[i].x,p[i].y);
	}
	return 0;
}

#include	<stdio.h>
#include	<math.h>

int main()
{
	int t,i=1,j=0;
	double ab,cd,bc,ad,area,half,high,low,mid,A,B,D,x,y,e,f,l,ERR=1e-7,a;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&ab,&cd,&ad,&bc);
		
		D = ab - cd;
		x = ( pow(ad,2) - pow(bc,2) + D*D ) / (2*D);
		y = D - x;
		A = acos(x/ad);
		B = acos(y/bc);
		l = sqrt(ad*ad - x*x );
		area  = 0.5 * (ab + cd) * l;
		half = area/2;
		
		low = 0 ;
		high = l;
		
		
		j=0;
		while(low<=high)
		{
			j++;
			if(j>200)	break;
			mid = ( low + high ) / 2 ;
			a = 0.5 * (2*ab - mid/tan(A) - mid/tan(B) ) * mid;
			if( a < half )
				low = mid;
			else if( a > half )
				high = mid;					
			else if( half - a < ERR || a - half < ERR )
				break;
		}
		e = mid/sin(A);
		f = mid/sin(B);
		
		printf("Land #%d: %lf %lf\n",i++,e,f);	
	}
	return 0;
}

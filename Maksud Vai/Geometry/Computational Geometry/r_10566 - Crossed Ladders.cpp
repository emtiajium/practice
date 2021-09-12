#include<iostream>
#include<cmath>

#define ERR 1e-4

int main()
{
	double x,y,c,h,l,m,f;

	while(scanf("%lf%lf%lf",&x,&y,&c)==3)
	{
		h = x;
		if(y<h)
			h = y;
		l=0;

		while(l<h)
		{
			m = (l+h)/2;

			f = c/(tan(acos(m/x))) + c/(tan(acos(m/y)));  
			if(f>m)
				h=m;
			else
				l = m;
			if(fabs(f-m)<ERR)
				break;
		
		}
		printf("%.3lf\n",m);
	}


	return 0;
}

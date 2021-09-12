#include <stdio.h>

double x[100], y[100];
int n;

int point_in_poly(double xx, double yy)
{
	int i, j, c=0;
	for (i = 0, j = n-1; i < n; j = i++)
	{
		if ( ((y[i]>yy) != (y[j]>yy)) && (xx < (x[j]-x[i]) * (yy-y[i]) / (y[j]-y[i]) + x[i]) )
	       c = !c;
	}
  return c;
}

int main()
{
	int i, check;
	double xx, yy;
	while(scanf("%d", &n)==1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lf %lf", &x[i], &y[i]);
		}
		printf("Enter the tested point\n");

		scanf("%lf %lf", &xx, &yy);

		check = point_in_poly(xx, yy);

		if(check)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}


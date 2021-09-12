#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;


typedef struct
{
    double x, y;
}point;

point pnts[102],stk[102],piv;

int cross(point a,point b,point c){
	if((b.x-a.x)*(c.y-a.y) > (c.x-a.x)*(b.y-a.y))
		return 1;
	else if((b.x-a.x)*(c.y-a.y) < (c.x-a.x)*(b.y-a.y))
		return -1;
	return 0;
}

int comp(const void *a, const void *b)
{
	int cr;
	point *c = (point*) a;
	point *d = (point*) b;

	cr = cross(piv,*d,*c);
	if(cr)
		return cr;
	if((pow( (piv.x - c->x), 2) + pow( (piv.y - c->y), 2) ) > ( pow( (piv.x - d->x),2) + pow( (piv.y - d->y), 2) ) )
		return 1;
	return -1;
}

int main()
{
    int total, i;

    scanf("%d", &total);

	scanf("%lf%lf", &pnts[0].x, &pnts[0].y);

	piv = pnts[0];

    for(i=1;i<total;i++)
    {
        scanf("%lf%lf", &pnts[i].x, &pnts[i].y);

		if(pnts[i].y < piv.y)
			piv = pnts[i];
		else if(pnts[i].y == piv.y)
		{
			if(pnts[i].x < piv.x)
				piv = pnts[i];
		}
	}

    qsort(pnts, total, sizeof(point), comp);

    int top = 0;

	stk[top++] = pnts[0];
	stk[top++] = pnts[1];
	stk[top++] = pnts[2];


    for(i=3;i<total;i++)
    {

        while(cross(stk[top-2],stk[top-1],pnts[i]) < 0)
			top--;

        stk[top++] = pnts[i];
    }

    for(i=0;i<top;i++)
    {
        printf("%lf %lf\n", stk[i].x, stk[i].y);
    }


    return 0;
}

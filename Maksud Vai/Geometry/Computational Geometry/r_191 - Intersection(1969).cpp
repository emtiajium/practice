#include<iostream>
#include<cstdio>
using namespace std;

#define MIN(a,b)	(a<b?a:b)
#define MAX(a,b)	(a>b?a:b)
#define CP(a,b,c)	( (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x) )
#define OS(a,b,c)	( MAX(a.x,b.x)<=c.x && c.x<=MAX(a.x,b.x))&& (MIN(a.y,b.y)<=c.y && c.y<=MAX(a.y,b.y)?true:false)
#define	PS(a)		(cout<<a<<endl)
#define IR(ul,lr,p)	(ul.x<=p.x && p.x<=lr.x && lr.y<=p.y && p.y<=ul.y ? true : false )

typedef struct {int x,y;}P;

bool IsIntersect(P p1,P p2,P p3,P p4){
	int d1,d2,d3,d4;
	
	d1 = CP(p1,p2,p3);
	d2 = CP(p1,p2,p4);
	d3 = CP(p3,p4,p1);
	d4 = CP(p3,p4,p2);

	if(0> d1*d2 && 0> d3*d4)		return true;
	else if(d1 == 0 && OS(p1,p2,p3))	return true;
	else if(d2 == 0 && OS(p1,p2,p4))	return true;
	else if(d3 == 0 && OS(p3,p4,p1))	return true;
	else if(d4 == 0 && OS(p3,p4,p2))	return true;
	return false;
}

bool TST(P ul,P lr,P s,P e){
	P ur,ll;
	ur.x = lr.x;
	ur.y = ul.y;
	ll.x = ul.x;
	ll.y = lr.y;

	if(IsIntersect(ll,lr,s,e))	return true;
	if(IsIntersect(lr,ur,s,e))	return true;
	if(IsIntersect(ur,ul,s,e))	return true;
	if(IsIntersect(ul,ll,s,e))	return true;
	return IR(ul,lr,s); 
}

int main()
{
	P ul,lr,s,e;
	int x1,x2,y1,y2;
	int t;
	
	cin>>t;
	while(t--)
	{
		scanf("%d%d%d%d%d%d%d%d",&s.x,&s.y,&e.x,&e.y,&x1,&y1,&x2,&y2);
		ul.x=MIN(x1,x2);
		ul.y=MAX(y1,y2);
		lr.x=MAX(x1,x2);
		lr.y=MIN(y1,y2);

		if(TST(ul,lr,s,e))
			PS("T");
		else
			PS("F");
	}

	return 0;
}


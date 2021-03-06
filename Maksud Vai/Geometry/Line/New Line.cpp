typedef struct {double a,b,c;}L;
typedef struct {double x,y;}P;
//typedef struct {double a,b,c; void print(){printf("a:%lf b:%lf c:%lf\n",a,b,c);}}L;
//typedef struct {double x,y;   void print(){printf("x:%lf y:%lf\n",x,y);}}P;




L MakeLine(P p1,P p2){return (L){p1.y-p2.y,p2.x-p1.x,p1.x*p2.y - p2.x*p1.y};}
L PerpendicularLine(L l,P p){    return (L){l.b,-l.a,l.a*p.y-l.b*p.x};}
double DIS(P p1,P p2){return  sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y));}
P Intersection(L l1,L l2)
{
    return
    (P){
    (l1.b*l2.c-l2.b*l1.c)/(l1.a*l2.b-l2.a*l1.b),
    (l2.a*l1.c-l2.c*l1.a)/(l1.a*l2.b-l2.a*l1.b)
    };
}


int Number_of_IntersectionPoint(L l1,L l2)
{

///	 	-1 means same line
///		0 means parellal
///		1 means there is an intersection point.

    if(l1.a == 0 && l1.b == 0 && l1.c != 0) return 0;
    if(l2.a == 0 && l2.b == 0 && l2.c != 0) return 0;
    if(l1.a == 0 && l1.b == 0) return -1;
    if(l2.a == 0 && l2.b == 0) return -1;
    if(l1.a * l2.b != l2.a * l1.b) return 1;
    if(l1.a * l2.c == l1.c * l2.a && l1.b * l2.c == l1.c * l2.b) return -1;
    return 0;
}



P CircumCenter(P p1,P p2,P p3)
{
    /// When all points are not colinear

    L l1=MakeLine(p1,p2);
    L l2=MakeLine(p3,p2);

    l1=PerpendicularLine(l1,(P){(p1.x+p2.x)/2.,(p1.y+p2.y)/2.});
    l2=PerpendicularLine(l2,(P){(p3.x+p2.x)/2.,(p3.y+p2.y)/2.});

    return Intersection(l1,l2);
}
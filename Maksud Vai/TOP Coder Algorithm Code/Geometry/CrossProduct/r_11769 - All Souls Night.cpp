#include<stdio.h>
#include<math.h>

typedef struct {double x,y,z;}P;
P p[26];

inline double sqr(double x){return x*x;}
inline P CRS(P a,P b){P r; r.x = a.y*b.z - a.z*b.y;    r.y = a.z*b.x - a.x*b.z;    r.z=a.x*b.y-a.y*b.x;    return r;}
inline double DOT(P a,P b){return a.x*b.x+a.y*b.y+a.z*b.z;}
inline double ABS(P a) {return sqrt(sqr(a.x)+sqr(a.y)+sqr(a.z));}
inline P MAKE(P a,P b){P r; r.x = b.x-a.x; r.y = b.y-a.y; r.z = b.z-a.z; return r;}

int main()
{
    P a,b,c,abc;
    //freopen("in.in","r",stdin);
    int i,n,j,k,l,ks=1,si,op,tmp;
    double area;

    while(scanf("%d",&n)==1 && n)
    {
        area = 0.0;
        for(i=0;i<n;i++)    scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);

        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                for(k=j+1;k<n;k++)
                {
                    si =op=0;
                    a = MAKE(p[i],p[j]);
                    b = MAKE(p[i],p[k]);
                    abc = CRS(a,b);
                    for(l=0;l<n;l++)
                    {
                        c = MAKE(p[i],p[l]);
                        tmp = DOT(abc,c);
                        if(tmp>0)   si++;
                        else if(tmp<0)  op++;
                    }
                    if(!op || !si)
                    {
                        area +=ABS(abc);
                    }

                }
        area/=2.0;
        printf("Case %d: %.2lf\n",ks++,area);
    }
    return 0;
}

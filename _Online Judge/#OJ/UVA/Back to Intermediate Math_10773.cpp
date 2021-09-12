#include<stdio.h>
#include<math.h>
int _case,t;
double d,u,v,t1,t2,differ;
int main()
{
    scanf("%d",&_case);
    for(t=1;t<=_case;t++)
    {
        scanf("%lf %lf %lf",&d,&u,&v);
        if(v==0||u==0||v<=u) printf("Case %d: can't determine\n",t);
        else{
            t1=d/sqrt(v*v-u*u);
            t2=d/v;
            if(t1>t2) differ=t1-t2;
            else differ=t2-t1;
            printf("Case %d: %.3lf\n",t,differ);
        }
    }
return 0;
}

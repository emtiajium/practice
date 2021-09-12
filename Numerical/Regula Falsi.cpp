#include<stdio.h>
#include<math.h>

const double ACC=0.001;
double low,high,mid,fa,fb,fc;
int i,deg,arr[15];

double func(double a,double c=0.0){
    for(int i=deg;i>=0;i--)
        c+=arr[i]*pow(a,i);
    return c;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	while(scanf("%d",&deg)==1){
        for(i=deg;i>=0;i--) scanf("%d",&arr[i]);
        scanf("%lf%lf",&low,&high);
        fa=func(low);
        fb=func(high);
        if(fa*fb>0){
            printf("No solution.\n");
            continue;
        }
        while(fabs(low-high)>ACC){
            mid=(low*fb-high*fa)/(fb-fa);
            fc=func(mid);
            if(fc<0.0) low=mid;
            else high=mid;
        }
        printf("root: %.3lf\n",mid);
	}
	return 0;
}

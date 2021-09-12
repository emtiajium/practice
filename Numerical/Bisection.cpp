#include<stdio.h>
#include<math.h>
const double ACC=0.001;
double low,high,mid,fa,fb,fc;
int i,deg,arr[15];
int main()
{
    //freopen("input.txt","r",stdin);//input.in
    //freopen("output.txt","w",stdout);//output.out
	while(scanf("%d",&deg)==1){
        for(i=deg;i>=0;i--) scanf("%d",&arr[i]);
        scanf("%lf%lf",&low,&high);
        fa=fb=0.0;
        for(i=deg;i>=0;i--){
            fa+=arr[i]*pow(low,i);
            fb+=arr[i]*pow(high,i);
        }
        if((int)(fa*fb)>0) printf("No solution.\n");
        else{
            while(fabs(low-high)>ACC){
                mid=(low+high)/2;
                for(fc=0.0,i=deg;i>=0;i--){
                    fc+=arr[i]*pow(mid,i);
                }
                if(fc<0.0) low=mid;
                else high=mid;
            }
            printf("root: %.3lf\n",mid);
        }
	}
	return 0;
}

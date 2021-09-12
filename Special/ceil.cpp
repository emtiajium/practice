#include<stdio.h>
int main()
{
    double a,b;
    while(scanf("%lf",&a)==1){
        b=a-(int)a;
        if(b==0) printf("No ceil: %0.0f\n",a);
        else printf("Yes ceil:so now %d\n",(int)(a)+1);
    }
	return 0;
}

#include<stdio.h>
int main()
{
    int t,i,c,f;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d %d",&c,&f);
        double cf=(9*(double)c/5)+32;
        double sum=cf+(double)f;
        double fc=(5*(sum-32))/9;
        printf("Case %d: %.2lf\n",i,fc);
    }
    return 0;
}

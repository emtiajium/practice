#include<stdio.h>
#include<math.h>
int main()
{
    int t,i;
    double tax, income;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%lf",&income);
        if(income<=180000) printf("Case %d: 0\n",i);
        else if(income>180000&&income<=480000) {
            tax=(double)(((income-180000)*10)/100);
            tax=ceil(tax);
            if(tax<2000) printf("Case %d: 2000\n",i);
            else printf("Case %d: %0.0lf\n",i,tax);
        }
        else if(income>=480001&&income<=880000){
            tax=(double)((((income-480000)*15)/100));
            tax=tax+30000;
            tax=ceil(tax);
            printf("Case %d: %0.0lf\n",i,tax);
        }
        else if(income>=880001&&income<=1180000){
            tax=(double)((((income-880000)*20)/100));
            tax=tax+90000;
            tax=ceil(tax);
            printf("Case %d: %0.0lf\n",i,tax);
        }
        else if(income>1180000){
            tax=(double)((((income-1180000)*25)/100));
            tax=tax+150000;
            tax=ceil(tax);
            printf("Case %d: %0.0lf\n",i,tax);
        }
    }
    return 0;
}

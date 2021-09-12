#include<stdio.h>
int h1,h2,m1,m2,M_1,M_2;
int main()
{
    while(scanf("%d %d %d %d",&h1,&m1,&h2,&m2)&&(h1!=0||m1!=0||h2!=0||m2!=0)){
        M_1=h1*60+m1;
        M_2=h2*60+m2;
        if(M_2<M_1) M_2+=1440;//24*60=1440;
        printf("%d\n",M_2-M_1);
    }
    return 0;
}

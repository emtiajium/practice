#include<stdio.h>
#include<math.h>
#include<time.h>
int main()
{
    long int h,o,d;
    time_t start_time,end_time;
    while(scanf("%ld%ld",&h,&o)==2){
        start_time=clock();
        if(h>o) d=h-o;
        else d=o-h;
        printf("%ld\n",d);
        end_time=clock();
        printf("time=%d sec.\n",(end_time-start_time)/CLOCKS_PER_SEC);
    }
    return 0;
}

#include<stdio.h>
#include<math.h>
int t,k,l,lower,upper,condition,max,num,count,x;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&lower,&upper);
        max=0;
        for(k=lower;k<=upper;k++){
            x=k%2;
            condition=sqrt((double)k);
            for(l=1,count=0;l<=condition;){
                if(k%l==0) count++;
                if(x==0) l++;
                else l+=2;
            }
            count=count+count;// *2;
            if(condition*condition==k) count=count-1;
            if(count>max){
                max=count;
                num=k;
            }
        }
printf("Between %d and %d, %d has a maximum of %d divisors.\n",lower,upper,num,max);
    }
    return 0;
}

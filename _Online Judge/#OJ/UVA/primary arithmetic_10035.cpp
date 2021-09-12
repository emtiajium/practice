#include<stdio.h>
#include<math.h>
long long a,b,c,d,i,sum,carry,toadd,x,y,t,z;
int main()
{
    while(scanf("%lld %lld",&a,&b)&&a&&b){
        carry=0;
        x=log10(a)+1;
        y=log10(b)+1;
        if(y>x){
            t=a;
            a=b;
            b=t;
            z=y;
        }
        else z=x;
        toadd=0;
        for(i=1;i<=z;i++){
            c=(a%10)+toadd;
            if(b==0) d=0;
            else d=b%10;
            sum=c+d;
            if(sum>9) carry++;
            toadd=sum/10;
            a=a/10;
            b=b/10;
        }
        if(carry==0) printf("No carry operation.\n");
        else if(carry==1) printf("%lld carry operation.\n",carry);
        else  printf("%lld carry operations.\n",carry);
    }
    return 0;
}

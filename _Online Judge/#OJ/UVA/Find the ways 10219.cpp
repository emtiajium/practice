#include<stdio.h>
#include<math.h>
int n,r,i,ini;
double digit;
int main()
{
    while(scanf("%d %d",&n,&r)==2){
        digit=0.0;
        if(r>n-r) ini=r+1;
        else ini=n-r+1;
        for(i=ini;i<=n;i++)
            digit+= log10(i) - log10(n-i+1);
        digit=floor(digit)+1;
        printf("%d\n",(int)digit);
    }
return 0;
}
/*
12C4 = (12.11.10.9) / (1.2.3.4)
*/

#include<stdio.h>
#include<math.h>
int t,c,n,t_n,mod,len,sum;
int main()
{
    scanf("%d",&t);
    for(c=1;c<=t;c++){
        scanf("%d",&n);
        t_n=n;
        len=log10(n)+1;
        while(1){
            sum=0;
            while(n!=0){
                mod=n%10;
                sum+=(mod*mod);
                n/=10;
            }
            len=log10(sum)+1;
            n=sum;
            if(len==1) break;
        }
        if(sum==1) printf("Case #%d: %d is a Happy number.\n",c,t_n);
        else printf("Case #%d: %d is an Unhappy number.\n",c,t_n);
    }
    return 0;
}

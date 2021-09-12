#include<stdio.h>
#include<string.h>
#include<math.h>
char num[1005];
long long todeci(long long,long long);
long long bigmod(long long ,long long,long long);
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long long base,mod,deci,res,p,i;
    while(scanf("%lld",&base)&&base){
        getchar();
        scanf("%s %lld",num,&mod);
        deci=todeci(base,mod);
        res=0;
        p=strlen(num)-1;
        for(i=0;num[i];i++){
            res+=bigmod(base,p,deci)*((num[i]-48)%deci);
            res%=deci;
            p--;
        }
        res%=deci;
        i=0;
        do{
            num[i++]=(res%base)+48;
            res/=base;
        }while(res!=0);//do while incase res=0
        for(p=i-1;p>=0;p--)
            printf("%c",num[p]);
        puts("");
    }
    return 0;
}

long long todeci(long long b,long long num){
    long long rem,sum,i;
    if(b==10) return num;
    sum=i=0;
    while(num!=0){
        rem=num%10;
        if(rem) sum+=rem*(long long)pow(b,i);
        num/=10;
        i++;
    }
    return sum;
}
long long bigmod(long long b,long long p,long long m){
    long long r=1;
    while(p!=0){
        if(p%2==1) r=(r*b)%m;
        b=(b*b)%m;
        p/=2;
    }
    return r;
}

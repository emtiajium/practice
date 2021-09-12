#include<stdio.h>
#include<string.h>
const int SIZE=1005;
char sign,divident[SIZE],quotient[SIZE];
long long divisor,mod,i,j,k,q,emti,coun;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%s %c %lld",divident,&sign,&divisor)!=EOF){
        for(i=0,j=0,k=0;divident[i];i++){
            emti=(divident[i]-48)+k;
            q=emti/divisor;
            mod=emti%divisor;
            k=mod*10;
            quotient[j++]=q+48;
        }
        quotient[j]='\0';
        coun=0;
        if(sign=='/'){
            for(i=0;quotient[i];i++){
                if(quotient[i]>48){
                    coun++;
                    break;
                }
            }
            if(!coun) printf("0");
            else{
                for(j=i;quotient[j];j++)
                    putchar(quotient[j]);
            }
        }
        else if(sign=='%') printf("%lld",mod);
        puts("");
    }
    return 0;
}

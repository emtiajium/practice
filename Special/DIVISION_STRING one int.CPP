#include<stdio.h>
const int SIZE=1005;
char divident[SIZE],quotient[SIZE];
int divisor,mod,i,j,k,len,q,temp,coun;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("real.txt","w",stdout);
    while(scanf("%s %d",divident,&divisor)!=EOF){
        //printf("%s / %d :\n",divident,divisor);
        if((divident[0]=='0'&&divident[1]=='\0')&&divisor==0) printf("INDETERMINATE\n");
        else if(divisor==0) printf("UNDEFINED\n");
        else{
            for(i=0,j=0,k=0;divident[i];i++){
                temp=(divident[i]-48)+k;
                q=temp/divisor;
                mod=temp%divisor;
                k=mod*10;
                quotient[j++]=q+48;
            }
            quotient[j]='\0';
            coun=0;
            for(i=0;quotient[i];i++){
                if(quotient[i]>48){
                    coun++;
                    break;
                }
            }
            if(!coun){
                quotient[0]='0';quotient[1]='\0';
            }
            else{
                for(j=i,k=0;quotient[j];j++)
                    quotient[k++]=quotient[j];

                quotient[k]='\0';
            }
            //printf("QUOTIENT -> %s MOD  -> %d\n",quotient,mod);
            printf("%d\n",mod);
        }
    }
    return 0;
}

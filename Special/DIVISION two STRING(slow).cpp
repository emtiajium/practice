#include<stdio.h>
#include<string.h>
const int SIZE=505;
char divident[SIZE],divisor[SIZE],tmp[SIZE],quotient[SIZE];
bool sign;
int l1,l2,m,n,i,j,hold,diff,sum;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%s %s",divident,divisor)!=EOF){
        m=strcmp(divident,"0");
        n=strcmp(divisor,"0");
        if(!m && !n){
            puts("INDETERMINATE");
            continue;
        }
        else if(!n){
            puts("UNDEFINED");
            continue;
        }
        strcpy(quotient,"0");
        while(1){
            l1=strlen(divident);
            l2=strlen(divisor);
            sign=false;
            if(l1<l2) sign=true;
            else if(l1==l2){
                if(strcmp(divident,divisor)<0) sign=true;
            }
            if(sign==true) break;
            //diff
            m=l1-1;
            n=l2-1;
            for(i=0,hold=0;i<l1;i++,m--,n--){
                if(n>=0)diff=(divident[m]-48)-(divisor[n]-48)-hold;
                else diff=(divident[m]-48)-hold;
                if(diff<0){
                    hold=1;
                    tmp[i]=diff+48+10;
                }
                else{
                    tmp[i]=diff+48;
                    hold=0;
                }
            }
            tmp[i]=NULL;
            for(i=l1-1;i>0;i--){//1269-1125=4410//reverse
                if(tmp[i]>48) break;//this loop is for 4410
            }
            tmp[i+1]=NULL;
            for(j=i,i=0;j>=0;j--,i++)
                divident[i]=tmp[j];
            divident[i]=NULL;
            //addition
            l1=strlen(quotient);
            m=l1-1;
            n=0;
            for(i=0,hold=0;i<l1;i++,m--,n--){
                if(n>=0) sum=(quotient[m]-48)+ 1 +hold;
                else sum=(quotient[m]-48)+hold;
                tmp[i]=sum%10+48;
                hold=sum/10;
            }
            if(hold) tmp[i++]=hold+48;
            tmp[i]=NULL;
            for(j=i-1,i=0;j>=0;j--,i++)
                quotient[i]=tmp[j];
            quotient[i]=NULL;
        }
        printf("QUOTIENT -> %s MOD  -> %s\n",quotient,divident);
    }
    return 0;
}

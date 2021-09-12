#include<stdio.h>
#include<string.h>

void addit(char [],int,char [],int);
void subtra(char [],int,char [],int);
void multi(char [],int,char [],int);

const int SIZE=1005;
char divident[SIZE],divisor[SIZE],quotient[SIZE],mod[SIZE];
char add[SIZE],mul[SIZE],t_add[SIZE],temp[SIZE],temp2[SIZE];
char t_divident[SIZE],n1[SIZE],n2[SIZE],n3[SIZE];
int main()
{
    int m,n,z,x,nnn,l1,l2,i,j,k;
    freopen("division.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(scanf("%s %s",divident,divisor)==2){
        printf("%s / %s :\n",divident,divisor);
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
        for(z=x=nnn=0;divident[z];z++){
            t_divident[x++]=divident[z];
            t_divident[x]=NULL;
            if(!strcmp(t_divident,"0")){// 102 / 1
                quotient[nnn++]=48;
                quotient[nnn]=NULL;
                strcpy(mod,"0");
                x=0;
                continue;
            }
            l1=strlen(divisor);
            l2=strlen(t_divident);
            m=strcmp(divisor,t_divident);
            if(l1>l2){// 12/1
                quotient[nnn++]=48;
                quotient[nnn]=NULL;
                strcpy(mod,t_divident);
                continue;
            }
            else if(l1==l2){
                if(m==0){ //12/12
                    quotient[nnn++]=49;
                    quotient[nnn]=NULL;
                    strcpy(mod,"0");
                    x=0;
                    continue;
                }
                else if(m>0){// 12/11
                    quotient[nnn++]=48;
                    quotient[nnn]=NULL;
                    strcpy(mod,t_divident);
                    continue;
                }
            }//else 20/12
            strcpy(add,"1");
            while(1){
                strcpy(n1,divisor);
                strcpy(n2,add);
                /* যেহেতু call by reference অতএব multi() এর swap যদি কাজ করে
                                    তবে divisor,add এর ভ্যালুও পরিবর্তন হয়ে যাবে, তাই multi call হওয়ার আগে
                                    অন্য ভ্যারিয়বলে রেখে দিয়ে পরে আবার divisor, add এ অ্যাসাইন করে দিলাম।
                */
                multi(divisor,strlen(divisor),add,strlen(add));
                strcpy(divisor,n1);
                strcpy(add,n2);
                l1=strlen(mul);
                l2=strlen(t_divident);
                if(l1>l2) break;
                else if(l1==l2){
                    if(strcmp(t_divident,mul)<0) break;
                }
                strcpy(n3,add);//temporary quotient
                addit(add,strlen(add),"1",1);
                strcpy(add,t_add);
            }
            for(k=0;n3[k];k++)
                quotient[nnn++]=n3[k];
            quotient[nnn]=NULL;
            multi(divisor,strlen(divisor),n3,strlen(n3));
            subtra(t_divident,strlen(t_divident),mul,strlen(mul));//a=bq+r
            if(!strcmp(mod,"0")) x=0;
            else{
                strcpy(t_divident,mod);
                x=strlen(mod);
            }
        }
        for(i=k=0;quotient[i];i++){//leading zero
            if(quotient[i]>48){
                k++;
                break;
            }
        }
        if(!k) strcpy(quotient,"0");
        else{
            for(j=i,i=0;quotient[j];j++)
                quotient[i++]=quotient[j];
            quotient[i]=NULL;
        }
        printf("QUOTIENT -> %s MOD  -> %s\n\n",quotient,mod);
    }
    return 0;
}

void multi(char s1[],int l1,char s2[],int l2){
    int i,j,m,n,k,hold,sum,l3,l4,x;
    strcpy(mul,"0");
    l1=strlen(s1);
    l2=strlen(s2);
    if(l1<l2){
        l1=l1^l2;
        l2=l1^l2;
        l1=l1^l2;
        strcpy(temp,s1);
        strcpy(s1,s2);
        strcpy(s2,temp);
    }
    if(!strcmp(s2,"0")) strcpy(mul,"0");
    else{
        for(i=0,n=l2-1;i<l2;i++,n--){
            memset(temp,48,i);
            for(j=0,k=i+j,m=l1-1,hold=0;j<l1;j++,k++,m--){
                sum=(s2[n]-48)*(s1[m]-48)+hold;
                hold=sum/10;
                temp[k]=(sum%10)+48;
            }
            if(hold) temp[k++]=hold+48;
            temp[k]=NULL;
            for(x=k-1,j=0;x>=0;x--,j++)
                temp2[j]=temp[x];
            temp2[j]=NULL;
            l3=strlen(temp2);
            l4=strlen(mul);
            addit(temp2,l3,mul,l4);
        }
        strcpy(mul,t_add);
    }
}

void addit(char s1[],int l1,char s2[],int l2){
    int m,n,hold,sum,i,j;
    if(l2>l1){
        l1=l1^l2;
        l2=l1^l2;
        l1=l1^l2;
        strcpy(temp,s1);
        strcpy(s1,s2);
        strcpy(s2,temp);
    }
    m=l1-1;
    n=l2-1;
    for(i=0,hold=0;i<l1;i++,m--,n--){
        if(n>=0) sum=(s1[m]-48)+(s2[n]-48)+hold;
        else sum=(s1[m]-48)+hold;
        temp[i]=sum%10+48;
        hold=sum/10;
    }
    if(hold) temp[i++]=hold+48;
    for(j=i-1,i=0;j>=0;j--,i++)
        t_add[i]=temp[j];
    t_add[i]=NULL;
}

void subtra(char s1[],int l1,char s2[],int l2){//divident>remainder
    int i,j,m,n,hold,diff;
    if(l1==l2 && !strcmp(s1,s2)) strcpy(mod,"0");
    else{
        m=l1-1;
        n=l2-1;
        for(i=0,hold=0;i<l1;i++,m--,n--){
            if(n>=0)diff=(s1[m]-48)-(s2[n]-48)-hold;
            else diff=(s1[m]-48)-hold;
            if(diff<0){
                hold=1;
                temp[i]=diff+48+10;
            }
            else{
                temp[i]=diff+48;
                hold=0;
            }
        }
        temp[i]=NULL;
        for(i=l1-1;i>0;i--){
            if(temp[i]>48) break;
        }
        temp[i+1]=NULL;
        for(j=i,i=0;j>=0;j--,i++)
            mod[i]=temp[j];
        mod[i]=NULL;
    }
}

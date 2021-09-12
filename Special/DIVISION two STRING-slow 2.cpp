#include<stdio.h>
#include<string.h>

void addit(char [],int,char [],int);
void subtra(char [],int,char [],int);
void multi(char [],int,char [],int);

const int SIZE=100005;
char divident[SIZE],divisor[SIZE],quotient[SIZE],mod[SIZE];
char add[SIZE],mul[SIZE],t_add[SIZE],temp[SIZE],temp2[SIZE];
char n1[SIZE],n2[SIZE];
int l1,l2,m,n,i,j,hold,diff,sum,coun;

int main()
{
    freopen("input.txt","r",stdin);
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
        strcpy(add,"1");
        coun=0;
        while(1){
            strcpy(n1,divisor);
            strcpy(n2,add);
            multi(divisor,strlen(divisor),add,strlen(add));
            strcpy(divisor,n1);
            strcpy(add,n2);
            l1=strlen(mul);
            l2=strlen(divident);
            if(l1>l2) break;
            else if(l1==l2){
                if(strcmp(divident,mul)<0) break;
            }
            if(!coun)strcpy(quotient,"1");
            else strcpy(quotient,add);
            addit(add,strlen(add),"1",1);
            strcpy(add,t_add);
            coun++;
        }
		strcpy(n1,quotient);
        multi(divisor,strlen(divisor),quotient,strlen(quotient));
        subtra(divident,strlen(divident),mul,strlen(mul));
		strcpy(quotient,n1);
        printf("QUOTIENT -> %s MOD  -> %s\n",quotient,mod);
    }
    return 0;
}

void multi(char s1[],int l1,char s2[],int l2){
    int i,j,k,x,m,n,l3,l4;
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
            strcpy(mul,t_add);
        }
        strcpy(mul,t_add);
    }
}

void addit(char s1[],int l1,char s2[],int l2){
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

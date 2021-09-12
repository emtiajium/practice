// Subtract 5 times the last digit from the rest.
// 221: 22 − 1 × 5 = 17.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX=120;
char s1[MAX],s2[MAX],tmp[MAX],leading_zero[MAX],result[MAX],final[MAX];
int i,j,l1,l2,m,temp,zero,hold,difference;

char str[MAX],s_l[MAX];
int len,last,number;
int main()
{
    //freopen("input.txt","r",stdin);
    while(gets(str)){
        if(str[0]==48&&str[1]=='\0') break;
        while(1){
            for(i=0;str[i];i++)
                s1[i]=str[i];

            s1[i-1]='\0';
            last=5*(str[i-1]-48);
            if(last>9){ //two digit
                for(i=0;last!=0;i++){
                    s_l[i]=(last%10)+48;
                    last/=10;
                }
                s_l[i]='\0';
                for(j=i-1,i=0;j>=0;j--,i++){
                    s2[i]=s_l[j];
                }
                s2[i]='\0';
            }
            else{
                s2[0]=(5*(str[i-1]-48))+48;
                s2[1]='\0';
            }
            l1=strlen(s1);
            l2=strlen(s2);
            if(l1<l2){
                temp=l1;
                l1=l2;
                l2=temp;
                strcpy(tmp,s1);
                strcpy(s1,s2);
                strcpy(s2,tmp);
            }
            if(l1==l2){
                if(strcmp(s1,s2)<0){
                    strcpy(tmp,s1);
                    strcpy(s1,s2);
                    strcpy(s2,tmp);
                }
            }
            zero=l1-l2;
            for(i=0;i<zero;i++)
                leading_zero[i]='0';

            leading_zero[i]='\0';
            for(i=zero,j=0;i<l1;i++,j++)
                leading_zero[i]=s2[j];

            leading_zero[i]='\0';
            for(i=0,m=l1-1,hold=0;i<l1;i++,m--){
                difference=(s1[m]-'0')-(leading_zero[m]-'0')-hold;
                if(difference<0){
                    hold=1;
                    result[i]=10+difference+'0';
                }
                else{
                    result[i]=difference+'0';
                    hold=0;
                }
            }
            for(i=l1-1;i>0;i--){
                if(result[i]!='0') break;
            }
            result[i+1]='\0';
            for(j=i,i=0;j>=0;j--,i++)
                final[i]=result[j];

            final[i]='\0';
            len=strlen(final);
            if(len<3) break;
            strcpy(str,final);
        }
        number=atoi(final);
        if(number%17==0) puts("1");
        else puts("0");
    }
return 0;
}

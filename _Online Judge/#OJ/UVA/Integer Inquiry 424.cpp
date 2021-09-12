//Integer Inquiry 424
#include<stdio.h>                                                                                                                       #include<stdio.h>
#include<string.h>
const int MAX=200;
char s1[MAX],s2[MAX],tmp[MAX],res[MAX],a[MAX];
long int l1,l2,i,j,temp,m,n,sum,hold;

char str[120][MAX],summa[MAX];
int k,len;
int main()
{
    //freopen("input.txt","r",stdin);
    k=0;
    while(1){
        gets(str[k]);
        if((strcmp(str[k],"0"))==0) break;
        k++;
    }
    len=k;
    strcpy(summa,"0");
    for(k=0;k<len;k++){
        strcpy(s1,str[k]);
        strcpy(s2,summa);
        l1=strlen(s1);
        l2=strlen(s2);
        if(l2>l1){
            temp=l1;
            l1=l2;
            l2=temp;
            strcpy(tmp,s1);
            strcpy(s1,s2);
            strcpy(s2,tmp);
        }
        m=l1-1;
        n=l2-1;
        for(i=0,hold=0;i<l1;i++,m--,n--){
            if(n>=0)sum=(s1[m]-'0')+(s2[n]-'0')+hold;
            else sum=(s1[m]-'0')+hold;
            res[i]=sum%10+'0';
            hold=sum/10;
        }
        if(hold) res[i++]=hold+'0';
        for(j=i-1,i=0;j>=0;j--,i++)
            a[i]=res[j];

        a[i]='\0';
        strcpy(summa,a);
    }
    puts(a);
    return 0;
}

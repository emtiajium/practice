#include<stdio.h>                                                                                                                       #include<stdio.h>
#include<string.h>
char s1[1000],s2[1000],tmp[10000],add[10000];
int l1,l2,i,j,temp,m,n,sum,hold;
int main()
{
    scanf("%s %s",s1,s2);
    //printf("%s %s\n",s1,s2);
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
    //printf("%s %s\n",s1,s2);
    m=l1-1;
    n=l2-1;
    for(i=0,hold=0;i<l1;i++,m--,n--){
        if(n>=0) sum=(s1[m]-48)+(s2[n]-48)+hold;
        else sum=(s1[m]-48)+hold;
        tmp[i]=sum%10+48;
        hold=sum/10;
    }
    if(hold) tmp[i++]=hold+48;
    for(j=i-1,i=0;j>=0;j--,i++)
        add[i]=tmp[j];

    add[i]='\0';
    puts(add);
return 0;
}

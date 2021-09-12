#include<stdio.h>                                                                                                                       #include<stdio.h>
#include<string.h>
char s1[205],s2[205],tmp[505],str[505];
int t,l1,l2,i,j,temp,m,n,sum,hold;

void revs(char *tmp){
    int i,j,len=strlen(tmp);
    for(i=len-1;i>0;i--)
        if(tmp[i]>48) break;
    tmp[i+1]=NULL;
    for(j=i,i=0;j>=0;j--,i++)
        str[i]=tmp[j];
    str[i]=NULL;
}

int main()
{
    scanf("%d",&t);
    getchar();
    while(t--){
        scanf("%s %s",s1,s2);
        revs(s1);
        strcpy(s1,str);
        revs(s2);
        strcpy(s2,str);
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
            if(n>=0) sum=(s1[m]-48)+(s2[n]-48)+hold;
            else sum=(s1[m]-48)+hold;
            tmp[i]=sum%10+48;
            hold=sum/10;
        }
        if(hold) tmp[i++]=hold+48;
		tmp[i]=NULL;
        revs(tmp);
        strcpy(s1,str);
        revs(s1);
        puts(str);
    }
return 0;
}

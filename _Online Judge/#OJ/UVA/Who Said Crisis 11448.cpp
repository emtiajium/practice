//Big Number Subtraction
#include<stdio.h>
#include<string.h>
const int MAX=10005;
char s1[MAX],s2[MAX],tmp[MAX];
int t,i,j,l1,l2,m,n,temp,hold,diff;
bool sign;
int main()
{
    scanf("%d",&t);
    getchar();
    while(t--){
        scanf("%s %s",s1,s2);
        l1=strlen(s1);
        l2=strlen(s2);
        sign=0;
        if(l1<l2){
            temp=l1;
            l1=l2;
            l2=temp;
            strcpy(tmp,s1);
            strcpy(s1,s2);
            strcpy(s2,tmp);
            sign=1;
        }
        if(l1==l2){
            if(strcmp(s1,s2)<0){
                strcpy(tmp,s1);
                strcpy(s1,s2);
                strcpy(s2,tmp);
                sign=1;
            }
        }
        m=l1-1;
        n=l2-1;
        for(i=0,hold=0;i<l1;i++,m--,n--){
            if(n>=0)diff=(s1[m]-48)-(s2[n]-48)-hold;
            else diff=(s1[m]-48)-hold;
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
        for(i=l1-1;i>0;i--){
            if(tmp[i]!=48) break;
        }
        tmp[i+1]=NULL;
        if(sign==1) printf("-");
        for(j=i;j>=0;j--,i++)
            putchar(tmp[j]);
        puts("");
    }
return 0;
}

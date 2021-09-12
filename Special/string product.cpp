#include<stdio.h>
#include<string.h>

const int SIZE=1005;
char fir[SIZE],sec[SIZE],temp[SIZE],s1[SIZE],s2[SIZE];
int l1,l2,l3,l4,m,n,p,q,hold,i,j,k,x,sum;

int main()
{
    while(scanf("%s %s",fir,sec)!=EOF){
        strcpy(s2,"0");
        l1=strlen(fir);
        l2=strlen(sec);
        if(l1<l2){
            l1=l1^l2;
            l2=l1^l2;
            l1=l1^l2;
            strcpy(temp,fir);
            strcpy(fir,sec);
            strcpy(sec,temp);
        }
        if(!strcmp(sec,"0")) puts("0");
        else{
            for(i=0,n=l2-1;i<l2;i++,n--){
                memset(temp,48,i);
                for(j=0,k=i+j,m=l1-1,hold=0;j<l1;j++,k++,m--){
                    sum=(sec[n]-48)*(fir[m]-48)+hold;
                    hold=sum/10;
                    temp[k]=(sum%10)+48;
                }
                if(hold) temp[k++]=hold+48;
                temp[k]=NULL;

                for(x=k-1,j=0;x>=0;x--,j++)
                    s1[j]=temp[x];

                s1[j]=NULL;
                l3=strlen(s1);
                l4=strlen(s2);
                if(l4>l3){
                    l3=l3^l4;
                    l4=l3^l4;
                    l3=l3^l4;
                    strcpy(temp,s1);
                    strcpy(s1,s2);
                    strcpy(s2,temp);
                }
                p=l3-1;
                q=l4-1;
                for(x=0,hold=0;x<l3;x++,p--,q--){
                    if(q>=0) sum=(s1[p]-48)+(s2[q]-48)+hold;
                    else sum=(s1[p]-48)+hold;
                    temp[x]=sum%10+48;
                    hold=sum/10;
                }
                if(hold) temp[x++]=hold+48;
                for(j=x-1,x=0;j>=0;j--,x++)
                    s2[x]=temp[j];

                s2[x]=NULL;
            }
            puts(s2);
        }
    }
    return 0;
}

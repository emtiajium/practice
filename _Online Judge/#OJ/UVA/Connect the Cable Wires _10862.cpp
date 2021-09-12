#include<stdio.h>
#include<string.h>

const int MAX=1005;
char tmp[MAX],fib[4050][MAX]={"0","1"};
int l1,l2,i,j,m,n,sum,hold,k,x,y;

int main()
{
    for(k=2;k<4020;k++){
        x=k-1;
        y=k-2;
        l1=strlen(fib[x]);
        l2=strlen(fib[y]);
        if(l2>l1){
            l1=l1^l2;
            l2=l1^l2;
            l1=l1^l2;
            strcpy(tmp,fib[x]);
            strcpy(fib[x],fib[y]);
            strcpy(fib[y],tmp);
        }
        m=l1-1;
        n=l2-1;
        for(i=0,hold=0;i<l1;i++,m--,n--){
            if(n>=0)sum=(fib[x][m]-'0')+(fib[y][n]-'0')+hold;
            else sum=(fib[x][m]-'0')+hold;
            tmp[i]=sum%10+'0';
            hold=sum/10;
        }
        if(hold) tmp[i++]=hold+'0';
        for(j=i-1,i=0;j>=0;j--,i++)
            fib[k][i]=tmp[j];

        fib[k][i]='\0';
    }

    while(scanf("%d",&k)&&k){
        k+=k;
        puts(fib[k]);
        //printf("len %d\n",strlen(fib[k]));
    }
    return 0;
}

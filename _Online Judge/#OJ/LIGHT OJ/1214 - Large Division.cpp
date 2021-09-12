#include<stdio.h>
#include<string.h>
const int SIZE=205;
char divident[SIZE];
int t,c,i,j,len;
long long divisor,k,emti,mod,q;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    //getchar();
    for(c=1;c<=t;c++){
        scanf("%s %lld",divident,&divisor);
        if(divisor<0) divisor=(-1)*divisor;
        len=strlen(divident);
        if(divident[0]=='-'){
            for(i=1,j=0;i<len;i++){
                divident[j++]=divident[i];
            }
            divident[j]='\0';
            len=len-1;
            //puts(divident);
        }
        for(i=0,k=0;i<len;i++){
            emti=(divident[i]-48)+k;
            mod=emti%divisor;
            k=mod*10;
        }
        printf("Case %d: ",c);
        if(mod==0) puts("divisible");
        else puts("not divisible");
    }
    return 0;
}

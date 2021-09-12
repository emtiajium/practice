#include<stdio.h>
#include<string.h>
const int SIZE=2005;
char divident[SIZE];
int t,i;
long long divisor,k,emti,mod;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    //getchar();
    while(t--){
        scanf("%lld %s",&divisor,divident);
        for(i=0,k=0;divident[i];i++){
            emti=(divident[i]-48)+k;
            mod=emti%divisor;
            k=mod*10;
        }
        printf("%d\n",mod);
    }
    return 0;
}

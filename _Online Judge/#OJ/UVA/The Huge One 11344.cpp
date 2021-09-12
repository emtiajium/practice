#include<stdio.h>
char divident[1005];
int t,divisor,m,n;
long long mod,i,k,emti;
bool flag;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        getchar();
        scanf("%s",divident);
        flag=false;
        scanf("%d",&n);
        for(m=0;m<n;m++){
            scanf("%d",&divisor);
            for(i=k=0;divident[i];i++){
                emti=(divident[i]-48)+k;
                mod=emti%divisor;
                k=mod*10;
            }
            if(mod>0) flag=true;
        }
        if(flag==false) printf("%s - Wonderful.\n",divident);
        else if(flag==true) printf("%s - Simple.\n",divident);
    }
    return 0;
}

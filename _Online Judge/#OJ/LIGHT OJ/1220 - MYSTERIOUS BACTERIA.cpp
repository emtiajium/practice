#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int SIZE=46350;
int t,cases,i,j,r,n,cnd,gcd;
bool flag[SIZE]={1,1};
int prime[4795]={2};
struct TT{
    int val,countt;
};
TT arr[5005];
int GCD(int u, int v){
    if(u == v || u == 0 || v == 0)
        return u|v;
    if( (u & 1)==0 ){
        if( (v & 1)==0 )
            return (2*GCD(u>>1, v>>1));
        else
            return  GCD(u>>1, v);
    }
    else if( (v & 1) == 0)
        return GCD(u, v>>1);
    else{
        if(u > v)
            return GCD((u-v)>>1, v);
        else
            return GCD((v-u)>>1, u);
    }
}
int main()
{
    for(i=3;i<216;i+=2){
        if(flag[i]==false){
            r=i<<1;
            for(j=i*i;j<SIZE;j+=r)
                flag[j]=true;
        }
    }
    for(i=3,j=1;i<SIZE;i+=2){
        if(flag[i]==false) prime[j++]=i;
    }
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("Case %d: ",++cases);
        if(n==-2147483648){
            puts("31");
            continue;
        }
        flag[1]=false;
        if(n<0){
            n=-n;
            flag[1]=true;
        }
        cnd=sqrt(n)+1;
        for(i=j=0;n!=1&&prime[i]<cnd;i++){
            r=0;
            while(n%prime[i]==0){
                n/=prime[i];
                r++;
            }
            if(r){
                arr[j].val=prime[i];
                arr[j].countt=r;
                j++;
            }
        }
        if(n>1){
            arr[j].val=n;
            arr[j].countt=1;
            j++;
        }
        if(j==1){
            if(flag[1]==true&&(arr[0].countt&1)==0){
                while((arr[0].countt&1)==0)
                    arr[0].countt>>=1;
            }
            printf("%d\n",arr[0].countt);
            continue;
        }
        gcd=GCD(arr[0].countt,arr[1].countt) ;
        for(i=2;i<j;i++)
            gcd=GCD(gcd,arr[i].countt);
        if(flag[1]==true && (gcd&1)==0){
            while((gcd&1)==0)
                gcd>>=1;
        }
        printf("%d\n",gcd);
    }
    return 0;
}

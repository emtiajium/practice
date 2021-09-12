#include<stdio.h>
#include<math.h>
using namespace std;
int summing(int);
const int SIZE=31630;
int i,j,k,r,t,u,v,sum,sum2,coun,zz,prod;
bool flag[SIZE]={1,1},xlag;
int prime[3408]={2};
int main()
{
    //freopen("input.txt","r",stdin);
    for(i=3;i<178;i+=2){
        r=i+i;
        if(flag[i]==false){
            for(j=i*i;j<SIZE;j+=r)//j+=2*i;
                flag[j]=true;
        }
    }
    for(i=3,j=1;i<SIZE;i+=2){
        if(flag[i]==false) prime[j++]=i;
    }
    //last prime val 31627
    scanf("%d",&t);
    while(t--){
        scanf("%d",&k);
        for(u=k;;u++){
            sum=summing(u);
            v=u;
            j=sqrt(v);
            sum2=0;
            prod=1;
            for(i=0;v!=1&&prime[i]<=j;i++){
                xlag=false;
                coun=0;
                while(v%prime[i]==0){
                    v/=prime[i];
                    coun++;
                    xlag=true;
                }
                if(xlag){
                    zz=summing(prime[i]);
                    for(r=0;r<coun;r++){
                        sum2+=zz;
                        prod*=prime[i];
                    }
                }
            }
            if(v==u) continue;//prime is not smith num
            if(v>1){
                sum2+=summing(v);
                prod*=v;
            }
            if(prod==k) continue;//Smith num is larger than input
            if(sum2==sum){
                printf("%d\n",u);
                break;
            }
        }
    }
    return 0;
}

int summing(int a){
    int b,sum=0;
    while(a!=0){
        b=a%10;
        a=a/10;
        sum+=b;
    }
    return sum;
}

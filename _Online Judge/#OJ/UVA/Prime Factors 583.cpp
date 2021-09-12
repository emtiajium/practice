#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
const int SIZE=46360;
int i,j,k,r;
bool flag[SIZE]={1,1};
vector<int>prime;
int main()
{
    prime.push_back(2);
    for(i=3;i<=215;i+=2){ //sqrt(SIZE)=752;
        r=i+i;
        if(!flag[i]){
            for(j=i*i;j<=SIZE;j+=r)//j+=2*i;
                flag[j]=1;
        }
    }
    for(i=3;i<=SIZE;i+=2){
        if(!flag[i]) prime.push_back(i);
    }
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&k)&&k){
        if(k==-2147483648){
            puts("-2147483648 = -1 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2 x 2");
            continue;
        }
        if(k<0){
            printf("%d = -1 x ",k);
            k=-k;
        }
        else printf("%d = ",k);
        j=sqrt((double)k);
        for(i=0;prime[i]<=j&&k!=1;i++){
            while(k%prime[i]==0){
                k/=prime[i];
                printf("%d",prime[i]);
                if(k>1)printf(" x ");
            }
        }
        if(k>1) printf("%d",k); // for case like this 2147483645 = 5 x 19 x 22605091
        puts("");
    }
    return 0;
}

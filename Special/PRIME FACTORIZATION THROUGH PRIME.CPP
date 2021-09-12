#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
const int SIZE=46352;
int i,j,k,r;
bool flag[SIZE]={1,1};
vector<int>prime;
int main()
{
    prime.push_back(2);
    k=sqrt(SIZE)+1;
    for(i=3;i<k;i+=2){
        if(!flag[i]){
            r=i+i;
            for(j=i*i;j<SIZE;j+=r)//j+=2*i;
                flag[j]=1;
        }
    }
    for(i=3;i<SIZE;i+=2){
        if(!flag[i]) prime.push_back(i);
    }
    //last prime val 46351
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&k)==1){
        printf("%d = ",k);
        j=sqrt(k)+1;
        for(i=0;k!=1&&prime[i]<j;i++){
            while(k%prime[i]==0){
                k/=prime[i];
                printf("%d",prime[i]);
                if(k>1) printf(" x ");
            }
        }
        if(k>1) printf("%d",k); // for case like this 2147483645 = 5 x 19 x 22605091
        puts("");
    }
    return 0;
}

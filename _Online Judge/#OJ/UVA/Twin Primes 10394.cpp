#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
const int SIZE=18409210;// 100000th tw P (18409199, 18409201)
vector<bool>flag(SIZE);
vector<int>prime;
int i,j,k,r,n;
struct twin{
    int aaa,bbb;
};
twin arr[100005];

int main()
{
    for(i=3;i<4291;i+=2){
        if(flag[i]==false){
            for(j=i*i,r=i<<1;j<SIZE;j+=r)//j+=2*i;
                flag[j]=true;
        }
    }
    prime.push_back(2);
    for(i=3;i<SIZE;i+=2){
        if(flag[i]==false) prime.push_back(i);
    }
    for(i=j=1;prime[i]<18409202;i++){
        if(prime[i+1]-prime[i]==2){
            arr[j].aaa=prime[i];
            arr[j].bbb=prime[i+1];
            j++;
        }
    }
    while(scanf("%d",&n)==1){
        printf("(%d, %d)\n",arr[n].aaa,arr[n].bbb);
    }
    prime.clear();
    flag.clear();
    return 0;
}

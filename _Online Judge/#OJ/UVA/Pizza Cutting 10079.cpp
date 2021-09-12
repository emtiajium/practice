#include<cstdio>
using namespace std;

unsigned long long pizza,pizza2;
int n,i;
int main()
{
    while(scanf("%d",&n)&&(n>=0)){
        if(n==0) printf("1\n");
        else if(n==1) printf("2\n");
        else{
            for(i=2,pizza=2;i<=n;i++){
                pizza2=pizza+i;
                pizza=pizza2;
            }
            printf("%llu\n",pizza);
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

//const double PI=2*acos(0.0);
const int SIZE=100003;
typedef long long LL;
#define SLL(a) scanf("%lld",&a)
#define PLL(a) printf("%lld",a)

int t,cases,n,i,j,coun,free2,arr[SIZE];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        coun=0;
        free2=0;
        for(j=0;j<n;j++){
            if(arr[j]>0) free2+=arr[j];
            else if(arr[j]==-1 && free2>0){
                free2--;
            }
            else{
                coun++;
            }
        }
        printf("%d\n",coun);
    }
    return 0;
}

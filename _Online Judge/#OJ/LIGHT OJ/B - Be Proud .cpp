#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
//const double PI=3.14159265358979323846264338327950288419716939937511;
int arr[1005],arr2[1005];
int t,L,P,M,Q,i,j,k,coun,sum,high,ans;
bool flag;
int main()
{
    //freopen("input.txt","r",stdin);//input.in
    //freopen("output.txt","w",stdout);//output.out
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&L,&P,&M,&Q);
        for(i=0;i<L;i++) scanf("%d",&arr[i]);
		high=-1;
		ans=-1;
        for(i=0,k=0;i<=Q;i++){
            coun=0;
            flag=false;
            for(j=0;j<L;j++){
                sum=arr[j]+i;
                if(sum>=P && sum<=M) coun++;
                if(sum>M){
                    flag=true;
                    break;
                }
            }
            if(flag==true) break;
            if(flag==false && high<coun){
                high=coun;
                ans=i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

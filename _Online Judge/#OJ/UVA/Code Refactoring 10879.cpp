#include<stdio.h>
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int t,cases,n,i,x,cnd,coun;
vector<int>arr;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        cnd=sqrt(n)+1;
        for(i=1,coun=0,x=n%2;i<cnd&&coun<7;){
            if(n%i==0){
                arr.push_back(i);
                arr.push_back(n/i);
                coun+=2;
            }
            if(x==0) i++;
            else i+=2;
        }
        if(arr.size()<5) printf("Case #%d: %d = %d * %d\n",++cases,n,arr[2],arr[3]);
        else printf("Case #%d: %d = %d * %d = %d * %d\n",++cases,n,arr[2],arr[3],arr[4],arr[5]);
        arr.clear();
    }
    return 0;
}

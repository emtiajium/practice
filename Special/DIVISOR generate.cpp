#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
int n,i,x,y,cnd;
vector<int>arr;
int main()
{
    while(scanf("%d",&n)==1){
        cnd=sqrt(n);
        x=n%2;
        for(i=1;i<=cnd;){
            y=n%i;
            if(y==0){
                arr.push_back(i);
                arr.push_back(n/i);
            }
            if(x==0) i++;
            else i+=2;
        }
        if(cnd*cnd==n) arr.pop_back();//for perfect square
        sort(arr.begin(),arr.end());
        x=arr.size();
        for(i=0;i<x;i++)
            printf("%d ",arr[i]);
        printf("\nCount %d\n",x);
        arr.erase(arr.begin(),arr.end());
    }
    return 0;
}

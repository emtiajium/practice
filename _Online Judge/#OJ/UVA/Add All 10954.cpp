#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
//const double PI=3.14159265358979323846264338327950288419716939937511;
struct comp{
    bool operator()(int a,int b){
        return a>b;
    }
};
int arr[5005],n,u,v,sum,i,temp;
priority_queue< int , vector<int> , comp >pq;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&n),n){
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
            pq.push(arr[i]);
        }
        u=pq.top();
        pq.pop();
        v=pq.top();
        pq.pop();
        sum=u+v;
        pq.push(sum);
        while(pq.size()>1){
            u=pq.top();
            pq.pop();
            v=pq.top();
            pq.pop();
            temp=u+v;
            sum+=temp;
            pq.push(temp);
        }
        pq.pop();
        printf("%d\n",sum);
    }
    return 0;
}

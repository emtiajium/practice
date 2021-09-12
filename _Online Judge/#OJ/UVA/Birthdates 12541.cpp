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
using namespace std;
//const double PI=3.14159265358979323846264338327950288419716939937511;
struct TT{
    string name;
    int dd,mm,yy;
};
TT arr[105];
int n,i;
bool comp(TT a,TT b){
    if(a.yy==b.yy){
        if(a.mm==b.mm) return a.dd<b.dd;
        return a.mm<b.mm;
    }
    return a.yy<b.yy;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(i=0;i<n;i++)
        cin>>arr[i].name>>arr[i].dd>>arr[i].mm>>arr[i].yy;
    sort(arr,arr+n,comp);
    cout<<arr[n-1].name<<endl<<arr[0].name<<endl;

    return 0;
}

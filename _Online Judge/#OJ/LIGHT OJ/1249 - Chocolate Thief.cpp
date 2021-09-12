#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct TT
{
    string name;
    int l,w,h,vol;
};

int cases,t,i,n;
bool flag;

bool comp(TT a,TT b)
{
    return a.vol>b.vol;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    TT arr[110];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("Case %d: ",++cases);
        flag=0;
        for(i=0;i<n;i++)
            cin>>arr[i].name>>arr[i].l>>arr[i].w>>arr[i].h;

        for(i=0;i<n;i++){
            arr[i].vol=arr[i].l*arr[i].w*arr[i].h;
        }
        sort(arr,arr+n,comp);
        if(arr[0].vol==arr[1].vol) flag=1;
        if(flag){
            puts("no thief");
            continue;
        }
        cout<<arr[0].name<<" took chocolate from "<<arr[n-1].name<<endl;
    }
    return 0;
}

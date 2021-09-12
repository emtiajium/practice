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
struct TT{
    string str;
    int money;
};
TT arr[105];
map<string,int> MP;
string title,ingredient,name,requirement;
int t,m,n,b,price,i,k,unit,cost,countt;

bool comp(TT a,TT b){
    if(a.money==b.money) return a.str<b.str;
    return a.money<b.money;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    getchar();
    while(t--){
        getline(cin,title);
        scanf("%d%d%d",&m,&n,&b);
        getchar();
        while(m--){
            cin>>ingredient>>price;
            getchar();
            MP[ingredient]=price;
        }
        for(i=0;i<n;i++){
            getline(cin,name);
            scanf("%d",&k);
            getchar();
            cost=0;
            while(k--){
                cin>>requirement>>unit;
                getchar();
                cost+=unit*MP[requirement];
            }
            arr[i].str=name;
            arr[i].money=cost;
        }
        sort(arr,arr+n,comp);
        countt=title.size();
        for(i=0;i<countt;i++){
            if(title[i]>96 && title[i]<123) title[i]=title[i]-32;
            else title[i]=title[i]; // got several WA for it.
            cout<<title[i];
        }
        puts("");
        for(i=countt=0;i<n;i++){
            if(arr[i].money<=b){
                countt++;
                cout<<arr[i].str<<endl;
            }
            else break;
        }
        if(!countt) puts("Too expensive!");
        puts("");
        MP.clear();
    }
    title.clear();
    ingredient.clear();
    name.clear();
    requirement.clear();
    for(i=0;i<105;i++) arr[i].str.clear();
    return 0;
}

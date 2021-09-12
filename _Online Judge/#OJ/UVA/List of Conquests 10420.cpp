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
    string str;
    bool visited;
};
struct PP{
    string str2;
    int val;
};
TT arr[2005];
PP arr2[2005];
int n,i,j,k,si;
bool comp(PP a,PP b){
    return a.str2<b.str2;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&n)==1){
        getchar();
        for(i=0;i<n;i++)
            getline(cin,arr[i].str);

        for(i=0;i<n;i++){
            si=arr[i].str.size();
            for(j=0;j<si;j++){
                if(arr[i].str[j]==' ') break;
            }
            arr[i].str.erase(j);
        }
        k=0;
        for(i=0;i<n;i++){
            if(arr[i].visited==false){
                for(j=i;j<n;j++){
                    if(arr[i].str==arr[j].str){
                        arr2[k].str2=arr[i].str;
                        arr2[k].val++;
                        arr[j].visited=true;
                    }
                }
                k++;
            }
        }
        sort(arr2,arr2+k,comp);
        for(i=0;i<k;i++){
            cout<<arr2[i].str2<<' '<<arr2[i].val<<endl;
    }
    return 0;
}

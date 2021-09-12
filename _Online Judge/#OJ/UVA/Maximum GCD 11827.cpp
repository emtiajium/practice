//http://codeforces.com/blog/entry/9923
#include<stdio.h>
#include<iostream>
#include<sstream>
using namespace std;
int GCD(int,int);
int t,n,i,j,p,cnd,high,gcd,arr[105];
char str[100005];
stringstream emtiaj;
int main()
{
    scanf("%d",&t);
    getchar();
    while(t--){
        i=0;
        gets(str);
        emtiaj<<str;
        while(emtiaj>>p){
            arr[i++]=p;
        }
        emtiaj.clear();
        n=i;
        cnd=n-1;
        high=0;
        for(i=0;i<cnd;i++){
            for(j=i+1;j<n;j++){
                gcd=GCD(arr[i],arr[j]);
                high=max(high,gcd);
            }
        }
        printf("%d\n",high);
    }
    return 0;
}
int GCD(int u, int v){
    if(u == v || u == 0 || v == 0) return u|v;
    if( (u & 1)==0 ){
        if( (v & 1)==0 ) return (2*GCD(u>>1, v>>1));
        else return  GCD(u>>1, v);
    }
    else if( (v & 1) == 0) return GCD(u, v>>1);
    else{
        if(u > v)
            return GCD((u-v)>>1, v);
        else
            return GCD((v-u)>>1, u);
    }
}

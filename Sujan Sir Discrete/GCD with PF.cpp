// GCD with Prime factor
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
const int SIZE=1000007;
struct TT{
    int prm,val;
};
bool flag[SIZE]={true,true};
int prime[SIZE]={2};
vector<TT>vct,vct2;
void sieve(){
    int i,j,cnd,rr;
    cnd=sqrt(SIZE)+1;
    for(i=3;i<cnd;i+=2){
        if(flag[i]==false){
            for(j=i*i,rr=i<<1;j<SIZE;j+=rr)
                flag[j]=true;
        }
    }
    for(i=3,j=1;i<SIZE;i++){
        if(flag[i]==false) prime[j++]=i;
    }
}
void pf(int n,bool xyz){
    int cnd,i,coun;
    TT temp;
    cnd=sqrt(n);
    for(i=0;prime[i]<=cnd&&n!=1;i++){
        coun=0;
        while(n%prime[i]==0){
            n/=prime[i];
            coun++;
        }
        if(coun){
            temp={prime[i],coun};
            if(xyz==true) vct.push_back(temp);
            else vct2.push_back(temp);
        }
    }
    if(n>1){
        temp={n,1};
        if(xyz==true) vct.push_back(temp);
        else vct2.push_back(temp);
    }
}
int power(int b,int p){
    int r=1;
    while(p){
        if(p&1) r=r*b;
        b=b*b;
        p=p>>1;
    }
    return r;
}
int GCD(){
    int size,size2,i,j,gcd;
    size=vct.size();
    size2=vct2.size();
    if(size<size2){
        swap(vct,vct2);
        swap(size,size2);
    }
    for(i=0,gcd=1;i<size;i++){
        for(j=0;j<size2;j++){
            if(vct[i].prm==vct2[j].prm){
                gcd*=power(vct[i].prm,min(vct[i].val,vct2[j].val));
            }
        }
    }
    return gcd;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int cases=0,a,b,gcd,lcm;
    sieve();
    while(scanf("%d%d",&a,&b)==2){
        pf(a,true);
        pf(b,false);
        gcd=GCD();
        lcm=(a*b)/gcd;
        printf("Case %d: GCD %d LCM %d\n",++cases,gcd,lcm);
        vct.clear();
        vct2.clear();
    }
    return 0;
}
/*
input
12 18
23 45
3 9
23 45
output
Case 1: GCD 6 LCM 36
Case 2: GCD 1 LCM 1035
Case 3: GCD 3 LCM 9
Case 4: GCD 1 LCM 1035
*/

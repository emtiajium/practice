/*
Be careful, a mod n means “the remainder when a is divided by n”.
a = b (mod n) means “a and b have the same remainder when divided by n”.
*/
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int SIZE=1000007;
bool flag[SIZE]={true,true,false};
int prime[SIZE]={2},m[SIZE],r[SIZE];
int cases,ttt,B,ci,bi,di,i,j,x,gcd;
int bigmod(int b,int p,int m){
    int r=1;
    b=b%m;
    while(p){
        if(p&1) r=(r*b)%m;
        b=(b*b)%m;
        p=p>>1;
    }
    return r;
}
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
int phi(int n){
    int cnd,i;
    double sum;
    bool xlag;
    cnd=sqrt(n);
    sum=(double)n;
    for(i=0;prime[i]<=cnd&&n!=1;i++){
        flag[0]=false;
        while(n%prime[i]==0){
            n/=prime[i];
            xlag=true;
        }
        if(xlag) sum*=1.0-1.0/(double)prime[i];
    }
    if(n>1) sum*=1.0-1.0/(double)n;
    return (int)sum;
}
int GCD(int a,int b){
    while(b){
        a=a%b;
        swap(a,b);
    }
    return a;
}
int main(){
    freopen("input.txt","r",stdin);
    sieve();
    while(scanf("%d",&ttt)==1){
        printf("Case %d: ",++cases);
        for(i=0,B=1;i<ttt;i++){
            scanf("%d%d",&m[i],&r[i]);
            B*=r[i];
        }
        gcd=GCD(r[0],r[1]);
        for(i=2;i<ttt;i++)
            gcd=GCD(gcd,r[i]);
        if(gcd!=1) puts("No solution");
        //If p is prime, and p does not divide a, then gcd(p,a) = 1.
        else if(gcd==1){
            for(i=0,x=0;i<ttt;i++){
                bi=B/r[i];
                ci=m[i];
                di=bi%r[i];
                x+=bi*bigmod(di,phi(r[i])-1,r[i])*ci;
            }
            x=x%B;
            printf("All solutions are %d + %dt;\n",x,B);
        }
    }
    return 0;
}
/*
2
14 15
6 7
3
2 3
4 5
6 7
2
2 12
4 35
2
12 18
23 49
2
7 21
34 64
2
12 36
11 18
2
3 5
12 15
*/

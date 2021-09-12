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
int dp[10005]={1,1,2,6,4,2,2,4,2,8};

int digit(int n){
    int tp,tn,len=log10(n);
    if(len==0) return dp[n];//one digit
    if(dp[n]!=0) return dp[n];
    else{
        tn=tp=n;
        tn/=10;
        tp=n%10;
        if(tn%2==0){
            dp[n]=(6*digit(n/5)*digit(tp))%10;
            return dp[n];
        }
        else{
            dp[n]=(4*digit(n/5)*digit(tp))%10;
            return dp[n];
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    while(scanf("%d",&n)==1){
        printf("%5d -> %d\n",n,digit(n));
    }
    return 0;
}


/*
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

long long bigmod(long long,long long,long long);
const int SIZE=10005;
bool flag[SIZE]={1,1},xlag;
vector<int>prime,val[SIZE],coun[SIZE];
int i,j,k,r,cnd,size,t_i;
long long mod;
char str[]={"11264"};

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("real.txt","w",stdout);
    cnd=sqrt(SIZE)+1;
    for(i=3;i<cnd;i+=2){
        r=i+i;
        if(flag[i]==false){
            for(j=i*i;j<SIZE;j+=r)
                flag[j]=true;
        }
    }
    prime.push_back(2);
    for(i=3;i<SIZE;i+=2){
        if(flag[i]==false) prime.push_back(i);
	}
    val[2].push_back(2);
    coun[2].push_back(1);
    for(i=3;i<SIZE;i++){
        val[i]=val[i-1];
        coun[i]=coun[i-1];
        size=val[i].size();
        t_i=i;
        cnd=sqrt(t_i)+1;
        for(j=0;prime[j]<cnd&&t_i!=1;j++){
            xlag=false;
            r=0;
            while(t_i%prime[j]==0){
                t_i/=prime[j];
                r++;
                xlag=true;
            }
            if(xlag){
                xlag=false;
                for(k=0;k<size;k++){
                    if(val[i][k]==prime[j]){
                        xlag=true;
                        break;
                    }
                }
                if(xlag) coun[i][k]+=r;
                else{
                    val[i].push_back(prime[j]);
                    coun[i].push_back(r);
                }
            }
        }
        if(t_i>1){
            xlag=false;
            for(k=0;k<size;k++){
                if(val[i][k]==t_i){
                    xlag=true;
                    break;
                }
            }
            if(xlag) coun[i][k]++;
            else{
                val[i].push_back(t_i);
                coun[i].push_back(1);
            }
        }
    }
    while(scanf("%d",&r)==1){
        size=val[r].size();
        //printf("size %d\n",size);
        if(r<5){
            printf("%5d -> %c\n",r,str[r]);
            continue;
        }
        mod=1;
        mod*=bigmod(2,coun[r][0]-coun[r][2],10);//only for 2
        for(i=1;i<size;i++){
            if(val[r][i]==5) continue;
            mod*=bigmod(val[r][i],coun[r][i],10);
            mod%=10;
        }
        mod=mod%10;
        printf("%5d -> %lld\n",r,mod);
    }
    prime.clear();
    for(i=0;i<SIZE;i++){
        val[i].clear();
        coun[i].clear();
    }
    return 0;
}

long long bigmod(long long b,long long p,long long m){
    long long r=1;
    while(p!=0){
        if(p&1) r=(r*b)%m;
        b=(b*b)%m;
        p=p>>1;
    }
    return r;
}
*/

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

const int SIZE=10005;
bool flag[SIZE]={1,1},xlag;
vector<int>prime,val[SIZE],coun[SIZE];
int i,j,k,r,cnd,size,t_i;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
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
        k=val[r].size();
        printf("%d->",r);
        for(i=0;i<k;i++)
            printf("%d^%d ",val[r][i],coun[r][i]);

        puts("");
    }
    return 0;
}

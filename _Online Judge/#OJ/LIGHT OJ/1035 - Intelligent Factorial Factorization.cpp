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
bool flag[102]={1,1},xlag;
int prime[27]={2};
vector<int>val[102],coun[102];
int t,cases,i,j,k,r,cnd,size,t_i;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=3;i<11;i+=2){
        r=i<<1;
        if(flag[i]==false){
            for(j=i*i;j<102;j+=r)
                flag[j]=true;
        }
    }
    for(i=3,j=1;i<102;i+=2){
        if(flag[i]==false) prime[j++]=i;
	}
    val[2].push_back(2);
    coun[2].push_back(1);
    for(i=3;i<102;i++){
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
    scanf("%d",&t);
    while(t--){
        scanf("%d",&r);
        printf("Case %d: %d =",++cases,r);
        k=val[r].size()-1;
        for(i=0;i<k;i++)
            printf(" %d (%d) *",val[r][i],coun[r][i]);
        printf(" %d (%d)\n",val[r][k],coun[r][k]);
    }
    return 0;
}

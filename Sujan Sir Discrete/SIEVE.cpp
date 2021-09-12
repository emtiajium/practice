// Generate Prime with SIEVE
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
int i,j,cnd,r;
bool flag[SIZE]={true,true};
vector<int>prime;
int main()
{
    prime.push_back(2);
    cnd=sqrt(SIZE)+1;
    for(i=3;i<cnd;i+=2){
        if(flag[i]==false){
            for(j=i*i,r=i<<1;j<SIZE;j+=r)
                flag[j]=true;
        }
    }
    printf("%d\t",prime[0]);
    for(i=3,j=1;i<SIZE;i+=2){
        if(flag[i]==false){
            prime.push_back(i);
            printf("%d\t",prime[j]);
            j++;
        }
    }
    printf("\n\nBetween 0 & %d, there are %d Prime numbers\n\n",SIZE,prime.size());
    prime.clear();
    return 0;
}

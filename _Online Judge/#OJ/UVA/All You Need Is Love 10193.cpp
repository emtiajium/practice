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
char str[35],str2[35];
int t,cases,len,len2,deci,deci2,gcd;
int todeci(char *str,int len){
    int p=len-1,sum=0,i;
    for(i=0;i<len;i++){
        if(str[i]==49) sum+=(int)pow(2,p);
        p--;
    }
    return sum;
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
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    getchar();
    while(t--){
        gets(str);
        gets(str2);
        len=strlen(str);
        len2=strlen(str2);
        deci=todeci(str,len);
        deci2=todeci(str2,len2);
        gcd=GCD(deci,deci2);
        printf("Pair #%d: ",++cases);
        if(gcd>1) puts("All you need is love!");
        else puts("Love is not all you need!");
    }
    return 0;
}

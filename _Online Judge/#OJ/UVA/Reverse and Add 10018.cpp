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
unsigned reverse(unsigned);
unsigned t,num,coun,rev;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%u",&t);
    while(t--){
        scanf("%u",&num);
        coun=0;
        rev=reverse(num);
        while(num!=rev){
            num+=rev;
            coun++;
            rev=reverse(num);
        }
        printf("%u %u\n",coun,num);
    }
    return 0;
}

unsigned reverse(unsigned num){
    unsigned mod,i,sum=0;
    double len=log10(num);
    i=len;
    while(num!=0){
        mod=num%10;
        num/=10;
        sum+=mod*pow(10,i);
        i--;
    }
    return sum;
}

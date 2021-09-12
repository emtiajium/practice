//পারফেক্ট কিউব বাদে 7, 19, 37, 61, 91, 127, 169, 217,.................. সংখ্যাগুলোকে দুটি সংখ্যার কিউবের বিয়োগফল রূপে প্রকাশ করা যাবে।
//Un=(n+1)^3 - n^3
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

int n,i,j,y,sq;
bool flag;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&n)&&n){
        sq=sqrt(n);
        for(i=1;i<=sq;i++){
            flag=false;
            for(j=0;j<sq;j++){
                y=i*i*i - j*j*j;
                if(y==n){
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) printf("%d %d\n",i,j);
        else puts("No solution");
    }
    return 0;
}

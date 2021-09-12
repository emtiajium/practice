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
char str[12];
int n,len;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&n);
    getchar();
    while(scanf("%s",str)==1){
        len=strlen(str);
        sort(str,str+len);
        do{
            puts(str);
        }while(next_permutation(str,str+len));
        puts("");
    }
    return 0;
}

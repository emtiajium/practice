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

//const double PI=3.14159265358979323846264338327950288419716939937511;
string str,str2;
int test,cases,i,len,sq;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&test);
    getchar();
    while(test--){
        getline(cin,str);
        for(i=0;str[i];i++){
            if(isalpha(str[i])) str2+=str[i];
        }
        str=str2;
        reverse(str2.begin(),str2.end());
        printf("Case #%d:\n",++cases);
        if(str==str2){
            len=str.size();
            sq=sqrt((double)len);
            if(sq*sq==len) printf("%d\n",sq);
            else puts("No magic :(");
        }
        else puts("No magic :(");
        str.clear();
        str2.clear();
    }
    return 0;
}


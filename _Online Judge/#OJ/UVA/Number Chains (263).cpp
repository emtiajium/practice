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
char str[12];
map<int,int>MP;
int num,num2,len,asg,diff,countt;

bool comp(char a, char b){
    return a>b;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%s",str)){
        sscanf(str,"%d",&num); // string to int
        if(num==0) break;
        printf("Original number was %d\n",num);
        countt=asg=0;
        while(true){
            sprintf(str,"%d",num); // int to string
            len=strlen(str);
            sort(str,str+len,comp);
            sscanf(str,"%d",&num);
            sort(str,str+len);
            sscanf(str,"%d",&num2);
            diff=num-num2;
            printf("%d - %d = %d\n",num,num2,diff);
            countt++;
            num=diff;
            if(MP.find(diff)==MP.end()) MP[diff]=asg++;
            else break;
        }
        printf("Chain length %d\n",countt);
        puts("");
        MP.clear();
    }
    return 0;
}

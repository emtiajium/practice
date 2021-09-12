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
#include<map>
using namespace std;
//const double PI=3.14159265358979323846264338327950288419716939937511;
char str[130];
stack<char>st;
int t,i;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    getchar();
    while(t--){
        gets(str);
        for(i=0;str[i];i++){
            if(str[i]=='(' || str[i]=='[') st.push(str[i]);
            if(str[i]==')'){
                if(!st.empty() && st.top()=='(') st.pop();
                else st.push(str[i]);
            }
            if(str[i]==']'){
                if(!st.empty() && st.top()=='[') st.pop();
                else st.push(str[i]);
            }
        }
        if(st.empty()) puts("Yes");
        else{
            puts("No");
            while(!st.empty())
                st.pop();
        }
    }
    return 0;
}

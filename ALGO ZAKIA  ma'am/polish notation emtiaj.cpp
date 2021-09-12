#include<stdio.h>
#include<iostream>
#include<string>
#include<stack>
using namespace std;

string post,str;
stack<char>stk;

void func(char);
int priority(char);

int main()
{
    freopen("input.txt","r",stdin);
    while(cin>>str){
        str+=')';
        stk.push('(');
        for(int i=0;str[i];i++){
            if((str[i]>64&&str[i]<91)||(str[i]>96&&str[i]<123)) post+=str[i];
            else if(str[i]=='(') stk.push(str[i]);
            else if(priority(str[i])) func(str[i]);
            else if(str[i]==')'){
                while(stk.top()!='('){
                    post+=stk.top();
                    stk.pop();
                }
                stk.pop();
            }
        }
        cout<<post<<endl;
        str.clear();
        post.clear();
    }
    return 0;
}

void func(char ch){
    int p=priority(ch);
    while(priority(stk.top())>=p){
        post+=stk.top();
        stk.pop();
    }
    stk.push(ch);
}

int priority(char ch){
    if(ch=='+'||ch=='-') return 1;
    else if(ch=='*'||ch=='/') return 2;
    else if(ch=='^') return 3;
    return 0;
}

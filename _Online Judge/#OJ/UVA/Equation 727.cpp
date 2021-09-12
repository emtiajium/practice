#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<stack>
using namespace std;
char ch[52][3];
string post,str;
stack<char>stk;
void func(char);
int priority(char);
int t,i,len;
bool flag;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--){
        if(flag==true) puts("");
        flag=true;
        i=0;
        while(gets(ch[i])){
            if(ch[i][0]==NULL) break;
            i++;
        }
        len=i;
        for(i=0;i<len;i++){
            str+=ch[i];
        }
        str+=')';
        stk.push('(');
        for(i=0;str[i];i++){
            if(isdigit(str[i])) post+=str[i];
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
    return 0;
}

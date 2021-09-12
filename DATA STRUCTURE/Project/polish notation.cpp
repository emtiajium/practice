#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;

int len,i,j;
char ostr[50],gstr[50];
stack<char>exp;
void jump(char ch);

int main()
{
    while(gets(gstr)){
        len=strlen(gstr);
        gstr[len]=')';
        gstr[len+1]='\0';
        i=0;j=0;
        exp.push('(');
        while(gstr[i])
        {
            if(gstr[i]>=65&&gstr[i]<=90) ostr[j++]=gstr[i];
            else if(gstr[i]=='(') exp.push(gstr[i]);
            else if(gstr[i]=='+'||gstr[i]=='-'||gstr[i]=='*'||gstr[i]=='/'||gstr[i]=='^') jump(gstr[i]);
            else if(gstr[i]==')'){
                while(exp.top()!='(')
                      {
                    ostr[j++]=exp.top();
                    exp.pop();
                }
                exp.pop();
            }
            i++;
        }
        ostr[j]='\0';
        puts(ostr);
    }
return 0;
}


void jump(char ch)
{

    if(ch=='+'||ch=='-')
     {
        while(exp.top()=='*'||exp.top()=='/'||exp.top()=='^'||exp.top()=='+'||exp.top()=='-')
               {
                   ostr[j++]=exp.top();
                   exp.pop();
               }
         exp.push(ch);
     }

    else if(ch=='/'||ch=='*')
     {
        while(exp.top()=='^'||exp.top()=='*'||exp.top()=='/')
         {
           ostr[j++]=exp.top();
           exp.pop();
         }
         exp.push(ch);
     }
    else
    {
         while(exp.top()=='^')
         {
           ostr[j++]=exp.top();
           exp.pop();
         }
      exp.push(ch);
    }

}

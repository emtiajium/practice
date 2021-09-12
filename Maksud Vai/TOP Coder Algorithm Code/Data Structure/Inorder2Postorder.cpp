#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <sstream>
#include <stack>

using namespace std;

string in2post(string in);
bool isoperator(char ch);
int precedence(char sign);

int main()
{
    string in,post;

    while(cin>>in)
    {
        post=in2post(in);
        cout<<post<<endl;
    }

    return 0;
}

string in2post(string in)
{
    stack<char>stk;
    char temp;
    string post;
    int i,val1,val2;

    stk.push('(');
    in+=")";
    for(i=0;i<in.size();i++)
    {
        if(isalpha(in[i]) || isdigit(in[i]))
            post.push_back(in[i]);
        else if(in[i]=='(')
            stk.push(in[i]);
        else if(in[i]==')')
        {
            while(true)
            {
                temp=stk.top();
                stk.pop();
                if(temp=='(')
                    break;
                post.push_back(temp);
            }
        }
        else if(isoperator(in[i]))
        {
            val1=precedence(in[i]);
            while(true)
            {
                temp=stk.top();
                stk.pop();
                val2=precedence(temp);
                if(val2<val1)
                {
                    stk.push(temp);
                    stk.push(in[i]);
                    break;
                }
                post.push_back(temp);
            }
        }
    }
    return post;
}

bool isoperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
        return true;
    return false;
}

int precedence(char sign)
{
    if(sign=='+' || sign=='-')
        return 1;
    if(sign=='*' || sign=='/')
        return 2;
    if(sign=='^')
        return 3;
    return 0;
}
/*
    Input:

    5*(6+2)-8/4
    2+5*(5+6)


    Output:

    562+*84/-
    2556+*+
*/

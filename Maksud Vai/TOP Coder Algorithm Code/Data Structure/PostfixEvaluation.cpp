#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int post_eval(string post);

int main()
{
    string post;
    int val;

    while(cin>>post)
    {
        val=post_eval(post);
        cout<<val<<endl;
    }

    return 0;
}

int post_eval(string post)
{
    stack<int>stk;
    int i,val1,val2;

    for(i=0;i<post.size();i++)
    {
        if(isdigit(post[i]))
            stk.push(post[i]-'0');
        else
        {
            val2=stk.top();
            stk.pop();
            val1=stk.top();
            stk.pop();
            if(post[i]=='+')
            {
                stk.push(val1+val2);
            }
            if(post[i]=='-')
            {
                stk.push(val1-val2);
            }
            if(post[i]=='*')
            {
                stk.push(val1*val2);
            }
            if(post[i]=='/')
            {
                stk.push(val1/val2);
            }
        }
    }
    return stk.top();
}

/*
    Input:

    562+*84/-
    2556+*+


    Output:
    38
    57

*/

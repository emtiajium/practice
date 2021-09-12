/*
            Evaluate the Expression
            In this problem, we will consider a mathematical expression according to the following BNF grammar:
<expression> = <variable> | <expression><operator><expression>| “(“<expression>“)”
<operator> = “+” | “*”
<variable> = “a” | “b” | “c” | … | “y” | “z”

When evaluating such expressions, you have to follow the conventional rules. That means you have to do things in the brackets first and multiplications have to be done before addition.
Example:  2*(3+4*2) = 22
Given an expression and some inequalities, you have to assign each variable with a positive integer so that the value of the expression is minimized.

Consider an example:
Expression = a+b*c and Inequalities = a>b,  c>b

Assignment of: a=2, b=1 and c=2 will give us the minimum value. => 2 + 1*2 = 4

Input

The first line of input is an integer T(T<100) that gives us the number of test cases. Each case starts with a line that gives you the expression. The length of the expression is at most 300. The next line contains an integer I(I<400) that gives you the number of inequalities. Each of the next I lines will give you an inequality of the format x>y where x and y are lowercase alphabets that are present in the given expression and x is not equal to y. All the inequalities will be distinct.

Output
For each case, output the case number first. Then output the minimum value of the expression that can be obtained by assigning positive integers to each variable that abides by the given inequalities. You can assume the output will fit in 32 bit signed integer. If the inequalities are inconsistent, then output -1 instead.

Sample Input                            Output for Sample Input
3
a+b*c
2
a>b
c>b
z*(x+y)
3
z>x
x>y
z>y
a+b+c+a
0

Case 1: 4
Case 2: 9
Case 3: 4

*/


#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

#define SIZE 128

int topological_sort(vector<int>adj[],int nodes,string str);
string in2post(string in);
int post_eval(string post,vector<int>val);
bool isoperator(char ch);
int precedence(char sign);

int main()
{
    int test,n,i,val,Case=1;
    string str;
    vector<int>adj[SIZE];
    char x,y,str1[5];

    scanf("%d",&test);
    while(test--)
    {
        cin>>str;
        scanf("%d",&n);
        for(i=0;i<SIZE;i++)
            adj[i].clear();
        for(i=0;i<n;i++)
        {
            scanf("%s",str1);
            adj[str1[2]].push_back(str1[0]);
        }
        val=topological_sort(adj,126,str);
        printf("Case %d: %d\n",Case++,val);
    }

    return 0;
}

int topological_sort(vector<int>adj[],int nodes,string str)
{
    vector<int>Q,indeg(nodes),val(nodes,1),color(nodes);

    int i,j,Front;

    for(i=0;i<nodes;i++)
    {
        for(j=0;j<adj[i].size();j++)
            indeg[adj[i][j]]++;
    }

    Front=0;
    while(true)
    {
        for(i=0;i<nodes;i++)
        {
            if(indeg[i]==0 && color[i]==0)
            {
                Q.push_back(i);
                color[i]=1;
            }
        }
        if(Front==Q.size())
            break;
        for(Front=Front;Front<Q.size();Front++)
        {
            for(i=0;i<adj[Q[Front]].size();i++)
            {
                indeg[adj[Q[Front]][i]]--;
                val[adj[Q[Front]][i]]=val[Q[Front]]+1;
            }
        }
    }

    for(i=0;i<nodes;i++)
        if(indeg[i])
            return -1;
    str=in2post(str);
    return post_eval(str,val);
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

int post_eval(string post,vector<int>val)
{
    stack<int>stk;
    int i,val1,val2;

    for(i=0;i<post.size();i++)
    {
        if(isalpha(post[i]))
            stk.push(val[post[i]]);
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

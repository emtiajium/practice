/*
                        Problem:Expression Evaluation
In this problem, we will consider a mathematical expression according to the following BNF grammar:
<expression> = <variable> | <expression><operator><expression>| “(“<expression>“)”
<operator> = “+” | “*”
<variable> = “a” | “b” | “c” | … | “y” | “z”

When evaluating such expressions, you have to follow the conventional rules. 
That means you have to do things in the brackets first and multiplications have to be done before addition.
Example:  2*(3+4*2) = 22
Given an expression and some inequalities, you have to assign each variable with 
a positive integer so that the value of the expression is minimized.

Consider an example:
Expression = a+b*c and Inequalities = a>b,  c>b

Assignment of: a=2, b=1 and c=2 will give us the minimum value. => 2 + 1*2 = 4

Input

The first line of input is an integer T(T<100) that gives us the number
 of test cases. Each case starts with a line that gives you the expression.
 The length of the expression is at most 300. The next line contains an integer 
I(I<400) that gives you the number of inequalities. Each of the next I lines will
 give you an inequality of the format x>y where x and y are lowercase alphabets that
 are present in the given expression and x is not equal to y. All the inequalities will be distinct.

Output
For each case, output the case number first. Then output the minimum value of 
the expression that can be obtained by assigning positive integers to each variable that 
abides by the given inequalities. You can assume the output will fit in 32 bit signed integer. 
If the inequalities are inconsistent, then output -1 instead.
Input:
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
Output:
Case 1: 4
Case 2: 9
Case 3: 4
*/




#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

#define SIZE 10000
#define NILL -1
#define white 1
#define gray 2
#define black 3

vector<int>adj[SIZE],Dis(SIZE),Par(SIZE),Array(SIZE),Color(SIZE),Fin(SIZE),Indeg(SIZE),Rank(SIZE);
int Time,K;

int TopologicalSort(int nodes);
int DFS(int nodes);
void DFS_Visit(int u);
string in2post(string in);
int post_eval(string post);
bool isoperator(char ch);
int precedence(char sign);

int main()
{
    int i,j,nodes,edges,u,v,val,test,Case=1;
    string str;
    char str1[10];

    scanf("%d",&test);
    nodes=128;
    while(test--)
    {
        cin>>str;
        scanf("%d",&edges);
        for(i=0;i<nodes;i++)
        {
            adj[i].clear();
            Indeg[i]=0;
            Rank[i]=1;
        }
        for(i=0;i<edges;i++)
        {
            scanf("%s",str1);
            adj[str1[2]].push_back(str1[0]);
            Indeg[str1[0]]++;
        }
        val=TopologicalSort(nodes);
        if(val)
        {
            str=in2post(str);
            val=post_eval(str);
            printf("Case %d: %d\n",Case++,val);
        }
        else printf("Case %d: -1\n",Case++);

    }
    return 0;
}

int TopologicalSort(int nodes)
{
    int i,j;

    DFS(nodes);
    reverse(&Array[0],&Array[K]);
    for(i=0;i<K;i++)
    {
        if(Indeg[Array[i]]) //Impossible Case Check
            return 0;
        for(j=0;j<adj[Array[i]].size();j++)
        {
            Indeg[adj[Array[i]][j]]--;
            if(Rank[adj[Array[i]][j]]<=Rank[Array[i]])
                Rank[adj[Array[i]][j]]=Rank[Array[i]]+1;
        }
    }
    return 1;
}

int DFS(int nodes)
{
    int i;

    for(i=0;i<nodes;i++)
    {
        Color[i]=white;
        Par[i]=NILL;
    }
    Time=K=0;
    for(i=0;i<nodes;i++)
        if(Color[i]==white)
            DFS_Visit(i);
}

void DFS_Visit(int u)
{
    Color[u]=gray;      //White Vertex u Has just been Discovered
    Dis[u]=++Time;        //Discoverd u Vertex
    for(int i=0;i<adj[u].size();i++)
        if(Color[adj[u][i]]==white)
        {
            Par[adj[u][i]]=u;
            DFS_Visit(adj[u][i]);
        }
    Color[u]=black;     //Blacken u,it is finished
    Fin[u]=++Time;
    Array[K++]=u;
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

int post_eval(string post)
{
    stack<int>stk;
    int i,val1,val2;

    for(i=0;i<post.size();i++)
    {
        if(isalpha(post[i]))
            stk.push(Rank[post[i]]);
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

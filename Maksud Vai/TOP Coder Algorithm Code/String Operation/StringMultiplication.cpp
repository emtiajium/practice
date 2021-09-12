#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>

using namespace std;

string Multiplication(string str1,string str2);
string Addition(string str1,string str2);

int main()
{
    char s1[100],s2[100];
    string str1,str2,str;
    int i;

    while(scanf("%s %s",s1,s2)==2)
    {
        str1.clear();
        for(i=0;s1[i]!='\0';i++)
            str1.push_back(s1[i]);
        str2.clear();
        for(i=0;s2[i]!='\0';i++)
            str2.push_back(s2[i]);
        str=Multiplication(str1,str2);
        cout<<str<<endl;
    }

    return 0;
}

string Multiplication(string str1,string str2)
{
    int i,j,multi,carry;
    string str,temp;

    str="0";
    for(j=str2.size()-1;j>=0;j--)
    {
        temp.clear();
        carry=0;
        for(i=str1.size()-1;i>=0;i--)
        {
            multi=(str1[i]-'0')*(str2[j]-'0')+carry;
            temp.push_back(multi%10+'0');
            carry=multi/10;
        }
        if(carry)
            temp.push_back(carry+'0');
        reverse(temp.begin(),temp.end());
        for(i=j+1;i<str2.size();i++)
            temp.push_back('0');
        str=Addition(str,temp);
    }
    return str;
}

string Addition(string str1,string str2)
{
    int i,j,carry,sum;
    string str;

    for(carry=0,i=str1.size()-1,j=str2.size()-1;i>=0 && j>=0;i--,j--)
    {
        sum=(str1[i]-'0')+(str2[j]-'0')+carry;
        carry=sum/10;
        str.push_back(sum%10+'0');
    }
    for(i=i;i>=0;i--)
    {
        sum=(str1[i]-'0')+carry;
        carry=sum/10;
        str.push_back(sum%10+'0');
    }
    for(j=j;j>=0;j--)
    {
        sum=(str2[j]-'0')+carry;
        carry=sum/10;
        str.push_back(sum%10+'0');
    }
    if(carry)
        str.push_back(carry+'0');
    reverse(str.begin(),str.end());
    return str;
}

/*
Input:
4578
5689

642545565695
662245879662

10
10

1
2

2
3

7
8

99
99

9999
99

Output:
26044242
425523153376602685395090
100
2
6
56
9801
989901
*/

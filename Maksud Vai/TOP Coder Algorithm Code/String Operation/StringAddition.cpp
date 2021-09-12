#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

string Addition(string str1,string str2);

int main()
{
    string str1,str2,str;
    char s1[100],s2[100];
    int i;

    while(scanf("%s %s",s1,s2)==2)
    {
        str1.clear();
        for(i=0;s1[i]!='\0';i++)
            str1.push_back(s1[i]);
        str2.clear();
        for(i=0;s2[i]!='\0';i++)
            str2.push_back(s2[i]);
        str=Addition(str1,str2);
        cout<<str<<endl;
    }
    return 0;
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
1254
1256

2356
5689

124545
26564545

6568945454514
36565656565656

2365545454
26564545

Output:
2510

8045

26689090

43134602020170

2392109999
*/

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string result;
    string s1 = "hello ";
    string s2 = "world";
    result = s1 + s2;
    cout<<result<<endl;
    // result now contains "hello world"
    return 0;
}

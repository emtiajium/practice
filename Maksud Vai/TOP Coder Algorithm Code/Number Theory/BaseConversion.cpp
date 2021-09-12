//Xbase To Ybase
#include <iostream>
#include <string>
using namespace std;
string BaseConversion(string xstr,int xbase,int ybase);
int main()
{
    string xstr,ystr;
    int xbase,ybase;
    while(cin>>xstr>>xbase>>ybase)
    {
        ystr=BaseConversion(xstr,xbase,ybase);
        cout<<ystr<<endl;
    }
}
string BaseConversion(string xstr,int xbase,int ybase)
{
    string str="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    long long store[128],i,multi,sum;
    string ystr;

    for(i=sum=0;i<str.size();i++)
        store[str[i]]=i;
    multi=1;
    for(i=xstr.size()-1;i>=0;i--)
    {
        sum+=(store[xstr[i]]*multi);
        multi*=xbase;
    }
    while(true)
    {
        ystr.push_back(str[sum%ybase]);
        sum/=ybase;
        if(sum==0)
            break;
    }
    reverse(ystr.begin(),ystr.end());
    return ystr;
}
/*
Input & Output:
155CBA 16 2          ->101010101110010111010
BCDAE 16 8            ->2746656
abc457 42 9           ->13403018311
*/

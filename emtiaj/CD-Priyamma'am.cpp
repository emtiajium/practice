#include <bits/stdc++.h>
using namespace std;


int main()
{
    stringstream sstr;
    string str,temp;
    int len;

    while(getline(cin,str)){
        sstr<<str;
        while(sstr>>temp){
            if(temp==","||temp=="."||temp==";"||temp=="?")
                continue;
            len=temp.size();
            if(temp[len-1]==','||temp[len-1]=='.'||temp[len-1]==';'||temp[len-1]=='?'){
                temp.erase(len-1);
                cout<<temp<<" ";
            }
            else cout<<temp<<" ";
            temp.clear();
        }
        cout<<endl;
        sstr.clear();
    }
    str.clear();
    return 0;
}





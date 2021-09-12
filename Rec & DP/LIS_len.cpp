#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n , inp ;
    set < int > s;
    set < int > ::iterator it;
    scanf("%d",&n); // number of input
    while(n--)
    {
        cin >> inp;
        s.insert(inp);
        it = s.find(inp);
        it++;
        if(it!=s.end()) s.erase(it);
    }
    cout<<s.size()<<endl; // lis value
    return 0;
}

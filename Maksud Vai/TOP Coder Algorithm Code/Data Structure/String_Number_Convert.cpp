#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

int main()
{
    string str="120 52 5623";
    int i;

    //string to number convert
    istringstream iss;

    iss.str(str);
    while(iss>>i)
        cout<<i<<endl;
    //number to string convert
    ostringstream oss;

    str.clear();
    iss.clear();
    i=54;
    oss<<i;
    iss.str(oss.str());
    iss>>str;
    cout<<str<<endl;
    return 0;
}
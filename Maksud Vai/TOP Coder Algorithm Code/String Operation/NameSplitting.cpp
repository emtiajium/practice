#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> namesplitting(vector<string>board);

int main()
{
    int i;
    vector<string>board,name;
    string str;

    for(i=0;i<10;i++)
    {
        getline(cin,str);
        board.push_back(str);
    }

    name=namesplitting(board);
    for(i=0;i<name.size();i++)
        cout<<name[i]<<endl;
    return 0;
}

vector<string> namesplitting(vector<string>board)
{
    int i;
    vector<string>name;
    string str;
    for(i=0;i<board.size();i++)
    {
        istringstream iss;
        iss.str(board[i]);
        while(iss>>str)
            name.push_back(str);
    }
    return name;
}

/*
Input:
Forhad Ahmed
Maksud Hossain
Fouzia Sultana
Ashish pal
Shoikot
appropriate flag has
the first function
If the delimiter is found
it is extracted and discarded
these string versions a
Output:
Forhad
Ahmed
Maksud
Hossain
Fouzia
Sultana
Ashish
pal
Shoikot
appropriate
flag
has
the
first
function
If
the
delimiter
is
found
it
is
extracted
and
discarded
these
string
versions
a
*/

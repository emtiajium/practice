#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> NumberSplitting(vector<string> board);

int main()
{
    vector<string>board;
    vector<int>num;
    string str;
    int i;

    for(i=0;i<5;i++)
    {
        getline(cin,str);
        board.push_back(str);
    }
    num=NumberSplitting(board);
    for(i=0;i<num.size();i++)
        cout<<num[i]<<endl;

    return 0;
}

vector<int> NumberSplitting(vector<string> board)
{
    int i;
    vector<int>num;
    int temp;
    string str;

    for(i=0;i<board.size();i++)
    {
        istringstream iss;
        iss.str(board[i]);
        while(iss>>temp)
        {
            num.push_back(temp);
        }
    }
    return num;
}

/*
Input:
45648 574584 124587 2356
12487 124548 12
1248 3565 124 124 32
12478 12
124
Output:
45648
574584
124587
2356
12487
124548
12
1248
3565
124
124
32
12478
12
124
*/

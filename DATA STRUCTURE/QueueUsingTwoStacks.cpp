#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack <int> s,temp;
    string choice;
    int a;
    while(cin >> choice) {
        if(choice == "push") {
            cin >> a;
            s.push(a);
        }
        else if(choice == "front") {
            cout << "peeking front value " << s.top() << endl;
        }
        else if(choice == "pop") {
            while(!s.empty()) {
                temp.push(s.top());
                s.pop();
            }
            // handle exception for these two lines
            cout << "poping " << temp.top() << endl;
            temp.pop();
            while(!temp.empty()) {
                s.push(temp.top());
                temp.pop();
            }
        }
    }
    return 0;
}

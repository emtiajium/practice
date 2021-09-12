#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    stack <int> stackA, minimumStack;
    string choice;
    int value, minimumStackTop, stackTop;
    while(cin >> choice) {
        if(choice == "push") {
            cin >> value;
            stackA.push(value);
            cout << "pushing " << value << endl;
            if(minimumStack.empty()) {
                minimumStack.push(value);
                continue;
            }
            minimumStackTop = minimumStack.top();
            if(stackA.top() < minimumStackTop) {
                minimumStack.pop();
                minimumStack.push(stackA.top());
            }
        }
        else if(choice == "pop") {
            cout << "poping " << endl;
            stackTop = stackA.top();
            stackA.pop();
            cout << stackTop << endl;
            if(stackA.top() < minimumStackTop) {
                minimumStack.pop();
                minimumStack.push(stackA.top());
            }
        }
        else if(choice == "minimum") {
            cout << minimumStack.top() << endl;
        }
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

void stackSorting(stack<int> stackA) {
    // Priority Queue
    stack<int> stackB;
    int topElement;
    while(!stackA.empty()) {
        topElement = stackA.top();
        stackA.pop();
        while(!stackB.empty() && stackB.top() > topElement) {
            stackA.push(stackB.top());
            stackB.pop();
        }
        stackB.push(topElement);
    }
    while(!stackB.empty()) {
        cout << stackB.top() << " ";
        stackB.pop();
    }
    puts("");
}

int main() {
    //freopen("input.txt", "r", stdin);
    stack <int> stackA;
    string choice;
    int value;
    while(cin >> choice) {
        if(choice == "push") {
            cin >> value;
            stackA.push(value);
            stackSorting(stackA);
        }
        else if(choice == "pop") {
            stackA.pop();
            stackSorting(stackA);
        }
    }
    return 0;
}

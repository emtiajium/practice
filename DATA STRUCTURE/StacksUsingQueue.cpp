//push:
//1. enqueue new element.
//2. If n is the number of elements in the queue, then remove and insert element n-1 times.

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    queue <int> q;
    int value, frontElement, queueSize;
    string choice;
    while(cin >> choice) {
        if(choice == "push") {
            cin >> value;
            q.push(value);
            queueSize = q.size();
            while(queueSize>1){
                frontElement = q.front();
                q.pop();
                q.push(frontElement);
                queueSize--;
            }
            cout << "pushing " << value << endl;
        }
        else if(choice == "pop") {
            cout << "poping " << q.front() << endl;
            q.pop();
        }
    }
    return 0;
}

//যেকোন পজিশনে এক্সেস করা না গেলে কিভাবে সম্ভব?
//STL এরটা ভেক্টর/ডিকিউ ইউজ করে।
//2 4 1 5 3
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    queue <int> q, temp;
    string choice;
    int value, frontElement;
    while(cin >> choice) {
        if(choice == "push") {
            cin >> value;
            cout << "pushing " << value << endl;
            if(q.empty()) {
                q.push(value);
                continue;
            }
            while(!q.empty() && value < q.front()) {
                frontElement = q.front();
                q.pop();
                temp.push(frontElement);
            }
            if(value < temp.front()) {
                q.push(value);
                while(!temp.empty()) {
                    frontElement = temp.front();
                    temp.pop();
                    q.push(frontElement);
                }
            }
            else {
                temp.push(value);
                while(!q.empty()) {
                    frontElement = q.front();
                    q.pop();
                    temp.push(frontElement);
                }
                while(!temp.empty()) {
                    frontElement = temp.front();
                    temp.pop();
                    q.push(frontElement);
                }
            }
        }
        else if(choice == "pop") {
            cout << "poping " << q.front() << endl;
            q.pop();
        }
    }
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

struct AStruct {
    int a,b;
    void output() {
        cout << a << " " << b << endl;
    }
};

class AClass {
public:
    int a,b;
    void output() {
        cout << a << " " << b << endl;
    }
};

int main() {
    AStruct p,q;
    p.a = 5; p.b = 6;
    q = p;
    q.a = 15; q.b = 16;
    p.output();
    q.output();

    AClass x,y;
    x.a = 100; x.b = 120;
    y = x;
    y.a = 101; y.b = 121;
    x.output(); // different in C#, Java
    y.output();

    vector <int> vecA,vecB;
    vecA.push_back(1); vecA.push_back(2);
    vecB = vecA;
    vecA.push_back(3);
    cout << vecB.size() << endl;
}

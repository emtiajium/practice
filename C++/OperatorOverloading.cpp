#include <iostream>
using namespace std;

class CVector {
    private: int x,y;
    public: CVector () {};
    public: CVector (int x, int y){
        this -> x = x;
        this -> y = y;
    }
    public: CVector operator + (CVector param){
        CVector temp;
        temp.x = x + param.x;
        temp.y = y + param.y;
        return temp;
    }
    public: CVector operator = (CVector param) {
        x = param.x;
        y = param.y;
        return *this;
    }
    public: void output () {
        cout << x << ", " << y << endl;
    }
};

int main () {
    CVector a (3,1);
    CVector b (5,2);
    CVector c;
    c = a + b;
    c.output();
    //a = b;
    a = c;
    b = c; // a = b = c;
    a.output();
    b.output();
    c.output();
    return 0;
}

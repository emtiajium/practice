#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a;
    switch(a){
        case 4:
            cout << "Hi 4\n";
            break;
        case 5:
            cout << "Hi 5\n";
        case 6:
            cout << "Hi 6\n";
            break;
        default:
            break;
    }
    return 0;
}

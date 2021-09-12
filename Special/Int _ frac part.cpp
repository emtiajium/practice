#include <iostream>
#include <cmath>
using namespace std;
void myfunc(double d)
{
    double intpart,fracpart;
    cout<<"Using modf()\n";
    fracpart = modf(d, &intpart);
    cout << "Fractional part: " << fracpart<<endl;
    cout << "Integer part: " << intpart<<endl<<endl;
}
int main()
{
    int intpart;
    double fracpart;
    myfunc(12.2);
    cout<<"Another way\n";
    intpart=(int)12.2;
    fracpart=12.2-floor(12.2);
    cout<<"Fractional part: "<<fracpart<<endl<<"Integer part: "<<intpart<<endl<<endl;
    myfunc(15.0006);
    cout<<"Another way\n";
    intpart=(int)15.0006;
    fracpart=15.0006-floor(15.0006);
    cout<<"Fractional part: "<<fracpart<<endl<<"Integer part: "<<intpart<<endl;
    return 0;
}

#include<iostream>
using namespace std;
class item
{
    int number;
    double cost;
    public:
        void getdata(int ,double );
        void display(void);
};
void item::getdata(int a,double b)//supplies values to both private variable
{
    number=a;
    cost=b;
}
inline void item::display(void)//making a member fuctn outside class
{
    cout<<number<<' '<<cost<<endl;
}
int main()
{
    item x;//class variable is known as object
    x.getdata(10,25.5);
    x.display();
    return 0;
}

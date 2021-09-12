#include<iostream>
using namespace std;
const int size=2;
class set
{
    int a[size];
    public:
        void input (void);
        int largest(void);
        void display(void);
};
void set::input(void)
{
    cin>>a[0]>>a[1];
}
int set::largest(void)
{
    if(a[0]>a[1]) return a[0];
    else return a[1];
}
void set::display(void)
{
    cout<<"Largest "<<largest()<<endl;
}
int main()
{
    set s;
    s.input();
    s.display();
    return 0;
}

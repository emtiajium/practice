#include<iostream>
using namespace std;
class student
{
    char name[20];
    int age;
    public:
        void getdata(void);
        void display(void);
};
void student::getdata(void)
{
    cin>>name>>age;
}
void student::display(void)
{
    cout<<name<<' '<<age<<endl;
}
const int size=2;
int main()
{
    student arr[size];
    for(int i=0;i<size;i++)
        arr[i].getdata();

    for(int j=0;j<size;j++)
        arr[j].display();
return 0;
}

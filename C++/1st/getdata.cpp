#include<iostream>
using namespace std;
#include<conio.h>

class person
{
    char name[100];
    int age;
    public:
        void getdata(void);
        void display(void);
    };

            void person :: getdata(void)
            {
                cin>>name;
                cin>> age;
            }

            void person :: display(void)
            {
                cout<<name<<"\n";
                cout<<age<<endl;
            }
int main()
{
    person p;
    p.getdata();
    p.display();
    getch();
    return 0;
}






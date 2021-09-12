#include<iostream>
#include<conio.h>
using namespace std;

class fact
{
    long long f,a,i;
    public:
        int getdata(void);
        int display(void);
};
    int fact::getdata(void)//:: indicates getdata fuct belongs to fact class
    {
        cin>>a;
        f=1;
    for(i=2;i<=a;i++)
    {

        f*=i;
    }
}
int fact::display(void)
{
    cout<<f;
}

int main()
{
    fact f;
    f.getdata();
    f.display();
    getch();
    return 0;
}

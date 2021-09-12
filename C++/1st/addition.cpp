#include<iostream>
using namespace std;
class calculation
{
    int a;
    public:
        int b;
        void getdata(void);
        void display(void);
};

void calculation :: getdata(void){
    cin>>a;
    //cin>>b;
}
void calculation :: display(void){
    cout<<a+b<<" "<<a-b<<" "<<a*b<<" "<<(float)a/(float)b<<" "<<endl;
}
int main()
{
    int x;
    calculation p;
    p.getdata();
    cin>>x;
    p.b=x;
    p.display();
    return 0;
}






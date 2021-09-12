#include<iostream>
using namespace std;
class sample
{
    int x,y;
    public:
        sample(int,int);
        int add(void);
};
sample::sample(int i,int j){
    x=i;
    y=j;
}
int sample::add()
{
    return x+y;
}

int main()
{
    sample s(6,14);
    cout<<"Addition is "<<s.add();
return 0;
}

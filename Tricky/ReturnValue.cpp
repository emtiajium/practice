#include <iostream>
using namespace std;

int *func(){
    int a[]={1,2,3};
    return a;
}

int main()
{
    int *v=func(), i;
    for(i=0;i<3;i++)
        cout<<v[i];//<<" ";
    // Why this?
    return 0;
}

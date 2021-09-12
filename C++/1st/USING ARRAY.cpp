#include<iostream>
using namespace std;

class array
{
    int emtiaj[50];
    public:
        void input(void);
        void summation(int [],int);
};
void array::input(void)
{
    int size,i;
    cin>>size;
    for(i=0;i<size;i++)
        cin>>emtiaj[i];

    summation(emtiaj,i);
}
void array::summation(int arr[],int hasan)
{
    int sum=0;
    for(int i=0;i<hasan;i++)
        sum+=arr[i];
    cout<<sum<<endl;
}

int main()
{
    array a;
    a.input();
return 0;
}

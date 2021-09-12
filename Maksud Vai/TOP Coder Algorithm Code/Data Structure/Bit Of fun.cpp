#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int A,B,C,D;

    A=10;   //1010
    B=9;    //1001
    C=A&B;
    cout<<C<<endl;
    C=A|B;
    cout<<C<<endl;
    C=A & ~B;
    cout<<C<<endl;
    C=A^B;
    cout<<C<<endl;
    C=A<<5;
    cout<<C<<endl;
    C=A>>5;
    cout<<C<<endl;
    D=2;
    C=~D;
    cout<<C<<endl;
    //Clear Bit
    C=A & (~(1<<3));
    cout<<C<<endl;
    //Test Bit
    if((A & (1<<3)))
        cout<<"Bit is: 1"<<endl;
    else cout<<"Bit is: 0"<<endl;
    //Set Bit
    C=A | (1<<4);
    cout<<C<<endl;
    //Extracting last Bit which is 1
    D=13;
    C= D & (D-1);
    cout<<C<<endl;
    //Built In Function Count trailing zeros
    C= __builtin_ctz(C);//be Careful For C=0 this case undefined
    cout<<C<<endl;
    //Built In Function Count leading zeros
    C= __builtin_clz(D);
    cout<<C<<endl;
    //How many Bit Set(means 1)
    C=__builtin_popcount(D);
    cout<<C<<endl;
    //If a number is power of two
    D=9;
    if((D & (D-1))==0)
        cout<<"This is power of two"<<endl;
    else cout<<"This is not power of two"<<endl;

    unsigned int E;
    E=10;
    E=~E;
    cout<<E<<endl;
    //Reverse Bit
    unsigned int x;
    x=11;
    cout<<x<<endl;
    x = ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);
    x = ((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2);
    x = ((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4);
    x = ((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8);
    x = ((x & 0xffff0000) >> 16) | ((x & 0x0000ffff) << 16);
    cout<<x<<endl;

    return 0;
}
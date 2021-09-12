#include<iostream>
#include<stdio.h>
using namespace std;

class complex
{
    double x,y;
    public:
        complex(){};
        complex(double real, double imag){
            x=real;
            y=imag;
        }
        complex operator+(complex);
        void display(void);
};

complex complex::operator+(complex c)
{
    complex temp;
    temp.x=x+c.x;
    temp.y=y+c.y;
    return temp;
}

void complex::display(void){
    printf("%0.1lf + %0.1lf\n",x,y);
}

int main()
{
    complex c1;
    complex c2;
    complex c3;
    c1=complex(2.5,3.5);
    c2=complex(1.6,2.7);
    c3=c1+c2;

    c1.display();
    c2.display();
    c3.display();

    return 0;
}

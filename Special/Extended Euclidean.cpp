/*
ax + by = c;
d = gcd(a,b);
If c % d =0 , then one solution may be found by determining u and v such that d = ua + vb
then setting x0 = uc/d and y0 = vc/d.
All other solutions are given by
x = x0 + (b/d)t, y = y0 − (a/d)t; t belongs to Z
Extended Euclid finds u and v
*/

#include <stdio.h>

struct TT{
    int X,Y;
};

TT extendedEuclid(int a, int b) {
    TT temp, temp2;
    if(b == 0){
        temp = {1, 0};
        return temp;
    }
    temp = extendedEuclid(b, a%b);
    temp2 = {temp.Y, temp.X - temp.Y * (a / b)};
    return temp2;
}

int main()
{
    TT input;
    int a,b,gcd;

    while(scanf("%d %d", &a, &b)== 2){
        input = extendedEuclid(a,b);
        gcd = input.X * a + input.Y * b;
        printf("\nX = %d; Y = %d; G = %d\n", input.X, input.Y, gcd);
        printf("\n%d^-1 %% %d = X = %d\n",a,b,input.X);
        printf("\n%d^-1 %% %d = Y = %d\n",b,a,input.Y);
    }
    return 0;
}

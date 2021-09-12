#include <stdio.h>
#include <math.h>
struct TT{
    int u,v;
};

TT extendedEuclid(int a, int b) {
    TT temp, temp2;
    if(b == 0){
        temp = {1, 0};
        return temp;
    }
    temp = extendedEuclid(b, a%b);
    temp2 = {temp.v, temp.u - temp.v * (a / b)};
    return temp2;
}

int main()
{
    TT input;
    long long t,x,k,a,b,p0,q0,d;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld", &x, &k);
        a=floor((double)x/(double)k);
        b=ceil((double)x/(double)k);
        input = extendedEuclid(a,b);
        d = input.u * a + input.v * b;
        p0=(input.u*x)/d;
        q0=(input.v*x)/d;
        printf("%lld %lld\n",p0,q0);
    }
    return 0;
}

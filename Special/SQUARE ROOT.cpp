#include <stdio.h>
double  absoluteValue (double x)
{
    if ( x < 0 )
    x = -x;
    return x;
}

double  squareRoot (double x)
{
    const double  epsilon = 0.00001;
    double        guess   = 1.0;
    while  ( absoluteValue (guess * guess - x) >= epsilon )
        guess = ( x / guess + guess ) / 2.0;
return guess;
}

int main (void)
{
    double number;
    while(scanf("%lf",&number)==1)
    printf ("squareRoot (%lf) = %lf\n",number, squareRoot (number));
return 0;
}

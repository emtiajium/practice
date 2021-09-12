#include <stdio.h>

int exponentiation(int base, int power) {
    if(power == 0) {
        return 1;
    }
    int remainder;
    if(power % 2 == 0) {
        int x = exponentiation(base, power / 2);
        remainder = x * x;
        return remainder;
    }
    remainder = base * exponentiation(base, power - 1);
    return remainder;
}

int main() {
    int base, power;
    while(scanf("%d %d", &base, &power) == 2) {
        printf("%d\n", exponentiation(base, power));
    }
    return 0;
}

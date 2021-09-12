#include<stdio.h>
struct emtiaj{
    int a,b;
};

emtiaj f(){
    emtiaj x;
    x.a=12;
    x.b=13;
    return x;
}

int main()
{
    emtiaj s;
    s.a=2;
    s.b=3;
    printf("%d %d\n",s.a,s.b);
    s=f();
    printf("%d %d\n",s.a,s.b);
    return 0;
}

//beware of 0
//A quadrangle has four sides that each side is shorter than half of the perimeter.
#include<stdio.h>
int t,a,b,c,d,hp;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(a==0||b==0||c==0||d==0) puts("banana");
        else if(a==b&&b==c&&c==d) puts("square");
        else if((a==b&&c==d)||(a==c&&b==d)||(a==d&&b==c)) puts("rectangle");
        else{
            hp=(a+b+c+d)/2;
            if(a<hp&&b<hp&&c<hp&&d<hp) puts("quadrangle");
            else puts("banana");
        }
    }
    return 0;
}

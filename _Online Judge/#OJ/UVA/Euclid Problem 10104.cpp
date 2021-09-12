#include <stdio.h>
struct emtiaj{
    int X,Y,G;
};
emtiaj Extended_Euclid(int fir,int sec)
{
    int x, y, u, v, m, n, quot, mod;
    x = 0; y = 1;
    u = 1; v = 0;
    while(fir){
        quot = sec / fir;
        mod = sec % fir;
        m = x - (u * quot);
        n = y - (v * quot);
        sec = fir, fir = mod, x = u, y = v, u = m, v = n;
    }
    emtiaj local={x,y,sec};
    return local;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    emtiaj input;
    int a,b,mint,x,y;
    while(scanf("%d %d", &a, &b)==2){
        input = Extended_Euclid(a,b);
        mint=(2*input.G*(input.Y-input.X))/(a+b);
/*http://acm.uva.es/board/viewtopic.php?f=22&t=11079&p=48051&hilit=10104&sid=08a9c351e72afe68d43ce194d9a4783f#p48051*/
        x=input.X+(b/input.G)*mint;
        y=input.Y-(a/input.G)*mint;
        printf("%d %d %d\n",x,y,input.G);
    }
    return 0;
}

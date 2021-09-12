#include<stdio.h>
int GCD( int,int);
int n,m;
int main()
{
    while(scanf("%d%d",&m,&n)==2){
        printf("%d\n",GCD(m,n));
    }
    return 0;
}
int GCD(int u, int v){
    if(u == v || u == 0 || v == 0)
        return u|v;
    if( (u & 1)==0 ){ // if u is even
        /*
        The & and | operators have lower precedence than comparison operators.
        That means that x & 3 == 1 is interpreted
        as x & (3 == 1), which is probably not what you want.
        */
        if( (v & 1)==0 ) // if u and v are even
            return (2*GCD(u>>1, v>>1));
        else // u is even and v is odd
            return  GCD(u>>1, v);
    }
    else if( (v & 1) == 0) // if u is odd and v is even
        return GCD(u, v>>1);
    else{ // both are odd
        if(u > v)
            return GCD((u-v)>>1, v);
        else
            return GCD((v-u)>>1, u);
    }
}

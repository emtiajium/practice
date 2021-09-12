#include <bits/stdc++.h>
using namespace std;

int m,n;

void query(int idx){
    printf("%d ",idx);
    while(idx>0){
        idx-=(idx & -idx);
        printf("%d ",idx);
    }
    puts("");
    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    while(scanf("%d%d",&m,&n)==2){
        printf("upto %d: ",n);
        query(n);
        printf("upto %d: ",m);
        query(m);
    }
    return 0;
}

#include <stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int t,c,i;

struct TT{
    string name;
    int attacking,defending ;
};

bool comp(TT a, TT b){
    if(a.attacking == b.attacking){
		if(a.defending == b.defending) return a.name<b.name;
		return a.defending<b.defending;
	}
	return a.attacking > b.attacking;
}
bool comp_N(TT a, TT b){
    return a.name<b.name;
}

int main(void)
{
    //freopen("input.txt","r",stdin);
    TT player[100];
    scanf("%d",&t);
    for(c=1;c<=t;c++){
        printf("Case %d:\n",c);
        for(i=0; i<10; i++)
            cin>>player[i].name>>player[i].attacking>>player[i].defending;

        sort(player,player+10,comp);

        sort(player,player+5,comp_N);// [0,5)

        printf("(");
        for(i=0;i<5;i++){
            cout<<player[i].name;
            if(i<4) printf(", ");
        }
        printf(")\n");

        sort(player+5,player+10,comp_N);

        printf("(");
        for(i=5;i<11;i++){
            cout<<player[i].name;
            if(i<9) printf(", ");
        }
        printf(")\n");

    }
    return 0;
}

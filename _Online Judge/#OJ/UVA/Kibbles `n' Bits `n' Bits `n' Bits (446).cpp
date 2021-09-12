#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;

//const double PI=2*acos(0.0);
char str[17],num[7],num2[7],sign[3];
string temp,t;
int test,i,val,val2,len;
map<string,string>MP;

void mapping();

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    mapping();
    scanf("%d",&test);
    while(test--){
        scanf("%s %s %s",num,sign,num2);
        sscanf(num,"%X",&val);
        sscanf(num2,"%X",&val2);
        for(i=0;num[i];i++){
            t=num[i];
            temp+=MP[t];
        }
        strcpy(str,temp.c_str());
        len=strlen(str);
        len=13-len;
        for(i=0;i<len;i++) putchar('0'); //zero-padding of printf only work for number [%013s]
        printf("%s %s ",str,sign);
        temp.clear();
        for(i=0;num2[i];i++){
            t=num2[i];
            temp+=MP[t];
        }
        strcpy(str,temp.c_str());
        len=strlen(str);
        len=13-len;
        for(i=0;i<len;i++) putchar('0');
        printf("%s = ",str);
        temp.clear();
        if(strcmp(sign,"+")==0) printf("%d\n",val+val2);
        else printf("%d\n",val-val2);

    }
    MP.clear();
    t.clear();
    return 0;
}

void mapping(){
    MP["0"]="0000";
    MP["1"]="0001";
    MP["2"]="0010";
    MP["3"]="0011";
    MP["4"]="0100";
    MP["5"]="0101";
    MP["6"]="0110";
    MP["7"]="0111";
    MP["8"]="1000";
    MP["9"]="1001";
    MP["A"]="1010";
    MP["B"]="1011";
    MP["C"]="1100";
    MP["D"]="1101";
    MP["E"]="1110";
    MP["F"]="1111";
    return;
}

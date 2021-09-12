/*
No negative zero handle
No input given by Jan in discuss board
*/
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

//const double PI=3.14159265358979323846264338327950288419716939937511;
char str[1005],temp[105];
int test,cases,len;
double I,U,P;
bool flag[5];
stringstream sstr;

double faltu(int k,int len){
    int i,j=0;
    double num;
    char blah[35];
    for(i=k;i<len;i++){
        blah[j++]=temp[i];
    }
    blah[j]=NULL;
    num=atof(blah);
    for(i=strlen(blah)-1;i>=0;i--){
        if(blah[i]=='m') num=num*1e-3;
        if(blah[i]=='k') num=num*1e3;
        if(blah[i]=='M') num=num*1e6;
    }
    return num;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&test);
    getchar();
    while(test--){
        gets(str);
        sstr<<str;
        while(sstr>>temp){
            len=strlen(temp);
            if(temp[1]=='='){
                if(temp[0]=='I'){
                    flag[0]=true;
                    I=faltu(2,len);
                }
                else if(temp[0]=='U'){
                    flag[1]=true;
                    U=faltu(2,len);
                }
                else if(temp[0]=='P'){
                    flag[2]=true;
                    P=faltu(2,len);
                }
            }
        }
        sstr.clear();
        printf("Problem #%d\n",++cases);
        if(flag[0]==false){
            I=P/U;
            printf("I=%.2lfA\n\n",I);
        }
        else if(flag[1]==false){
            U=P/I;
            printf("U=%.2lfV\n\n",U);
        }
        else{
            P=U*I;
            printf("P=%.2lfW\n\n",P);
        }
        memset(flag,false,sizeof(flag));
    }
    return 0;
}
/*
6
I=1A P=0W
A light-bulb yields P=-1MW and the voltage is U=2kV. Compute the current, please.
A light-bulb yields P=0W and the voltage is U=220mV. Compute the current, please.
A light-bulb yields I=-1MA and the voltage is U=-2V. Compute the current, please.
I=-.002MA. U=10mV
I=-1kA U=2mV
*/

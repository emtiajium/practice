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
void HEX(int,int);
string str,temp,real;
int N,tN,pos,two,i,sum,len,numzero;
bool flag;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&N)==1){
        if(N==-2147483648){
            printf("-2147483648 converts to 128\n");
            continue;
        }
        flag=false;
        if(N<0){
            flag=true;
            tN=(-1)*N;
        }
        else tN=N;
        str="";
        while(tN){
            str+=(tN&1)+48;
            tN=tN>>1;
        }
        reverse(str.begin(),str.end());
        len=str.size();
        numzero=32-len-1;
        temp.insert(temp.begin(),numzero,48);
        temp=temp+str;
        str="0"+temp;
        if(flag==true){
            for(i=31;i>=0;i--){
                if(str[i]=='1'){
                    pos=i;
                    break;
                }
            }
            for(i=0;i<pos;i++){
                if(str[i]=='1') str[i]='0';
                else str[i]='1';
            }
        }
        HEX(24,31);
        HEX(16,23);
        HEX(8,15);
        HEX(0,7);
        for(i=31,two=1,sum=0;i>=0;i--){
            sum+=(real[i]-48)*two;
            two=two<<1;
        }
        printf("%d converts to %d\n",N,sum);
        str.clear();
        temp.clear();
        real.clear();
    }
    return 0;
}

void HEX(int i,int j){
    for(int k=i;k<=j;k++)
        real+=str[k];
    return;
}

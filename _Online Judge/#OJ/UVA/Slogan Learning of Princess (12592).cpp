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
string arr[25],str;
map<string,int> MP;
int N,Q,asg,xx;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&N);
    getchar();
    asg=0;
    while(N--){
        getline(cin,str);
        MP[str]=asg;
        getline(cin,str);
        arr[asg]=str;
        asg++;
    }
    scanf("%d",&Q);
    getchar();
    while(Q--){
        getline(cin,str);
        xx=MP[str];
        cout<<arr[xx]<<endl;
    }
    MP.clear();
    return 0;
}

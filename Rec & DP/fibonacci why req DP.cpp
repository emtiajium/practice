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
#include<time.h>
using namespace std;
//const double PI=3.14159265358979323846264338327950288419716939937511;
long long n,call,fibo;
clock_t start,end;
double tttime;
long long rec(long long n){
    call++;
    long long f;
    if(n<=1) return n;
    f=rec(n-1)+rec(n-2);
    return f;
}
int main()
{
    freopen("fibo.txt","r",stdin);//input.in
    //freopen("output.txt","w",stdout);//output.out
    while(scanf("%lld",&n)==1){
        start=clock();
        call=0;
        fibo=rec(n);
        end=clock();
        tttime=(double(end-start))/CLOCKS_PER_SEC;
        printf("%lldth fibonacci is %lld; required %lld calls & %lf seconds\n\n",n,fibo,call,tttime);
    }
    return 0;
}
/*
20th fibonacci is 6765; required 21891 calls & 0.000000 seconds

30th fibonacci is 832040; required 2692537 calls & 0.015000 seconds

31th fibonacci is 1346269; required 4356617 calls & 0.016000 seconds

32th fibonacci is 2178309; required 7049155 calls & 0.047000 seconds

40th fibonacci is 102334155; required 331160281 calls & 1.934000 seconds

45th fibonacci is 1134903170; required 3672623805 calls & 21.325000 seconds

46th fibonacci is 1836311903; required 5942430145 calls & 34.055000 seconds

50th fibonacci is 12586269025; required 40730022147 calls & 235.218000 seconds

60th fibonacci is 1548008755920; required 5009461563921 calls & 29775.864000 seconds

*/

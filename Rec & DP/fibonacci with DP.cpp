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
long long n,call,fibo,dp[93];
bool visited[93];
clock_t start,end;
double tttime;
long long rec(long long n){
    call++;
    if(n<=1) return n;
    if(visited[n]==true) return dp[n];
    else{
        visited[n]=true;
        dp[n]=rec(n-1)+rec(n-2);
        return dp[n];
    }
}
int main()
{
    //freopen("fibo.txt","r",stdin);//input.in
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
20th fibonacci is 6765; required 39 calls & 0.000000 seconds

30th fibonacci is 832040; required 21 calls & 0.000000 seconds

31th fibonacci is 1346269; required 3 calls & 0.000000 seconds

32th fibonacci is 2178309; required 3 calls & 0.000000 seconds

40th fibonacci is 102334155; required 17 calls & 0.000000 seconds

45th fibonacci is 1134903170; required 11 calls & 0.000000 seconds

46th fibonacci is 1836311903; required 3 calls & 0.000000 seconds

50th fibonacci is 12586269025; required 9 calls & 0.000000 seconds

60th fibonacci is 1548008755920; required 21 calls & 0.000000 seconds

70th fibonacci is 190392490709135; required 21 calls & 0.000000 seconds

80th fibonacci is 23416728348467685; required 21 calls & 0.000000 seconds

90th fibonacci is 2880067194370816120; required 21 calls & 0.000000 seconds

92th fibonacci is 7540113804746346429; required 5 calls & 0.000000 seconds

*/

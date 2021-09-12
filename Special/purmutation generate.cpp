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

char str[25];
vector<char>result;
bool visited[25];
int N;

void call(){
    int i;
    if(result.size()==N){
        for(i=0;i<N;i++)
            putchar(result[i]);
        puts("");
        return;
    }
    for(i=0;i<N;i++){
        if(visited[i]==false){
            visited[i]=true;
            result.push_back(str[i]);
            call();
            visited[i]=false;
            result.pop_back();
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);//input.in
    //freopen("output.txt","w",stdout);//output.out
    while(scanf("%s",str)==1){
        N=strlen(str);
        call();
        memset(visited,false,sizeof(visited));
    }
    return 0;
}

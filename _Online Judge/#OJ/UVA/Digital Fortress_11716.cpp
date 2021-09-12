#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;
char ch,str[10004],mat[105][105];
int t,i,j,k,len,sq;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    getchar();
    while(t--){
        gets(str);
        len=strlen(str);
        sq=sqrt(len);
        if(sq*sq==len){
            k=0;
            for(i=0;i<sq;i++){
                for(j=0;j<sq;j++){
                    mat[i][j]=str[k++];
                }
            }
            for(j=0;j<sq;j++){
                for(i=0;i<sq;i++){
                    putchar(mat[i][j]);
                }
            }
            puts("");
        }
        else puts("INVALID");
    }
    return 0;
}

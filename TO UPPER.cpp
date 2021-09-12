#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;
char str[50005],str2[50005];
int i,j;
int main()
{
    //freopen("input.txt","r",stdin);
    while(gets(str)){
        for(i=0,j=0;str[i];i++,j++){
            if(isalpha(str[i])==0) str2[j]=str[i];
            else{
                if(islower(str[i])>0) str2[j]=toupper(str[i]);
                else str2[j]=str[i];
            }
        }
        str2[j]='\0';
        puts(str2);
    }
    return 0;
}

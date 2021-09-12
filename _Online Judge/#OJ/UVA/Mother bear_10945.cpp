#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;

char str[50005],str2[50005];
bool flag;
int i,j,len;

int main()
{
    //freopen("input.txt","r",stdin);
    while(gets(str)){
        if(str[0]=='D'&&str[1]=='O'&&str[2]=='N'&&str[3]=='E'&&str[4]=='\0') break;
                for(i=0,j=0;str[i];i++){
                    if(isalpha(str[i])==0) continue;
                    else{
                        if(isupper(str[i])>0) str2[j]=tolower(str[i]);
                        else str2[j]=str[i];
                        j++;
                    }
                }
                str2[j]='\0';
                len=strlen(str2);
                for(i=0,j=len-1;i<len;i++,j--){
                    if(str2[i]==str2[j]) flag=1;
                    else{
                        flag=0; break;
                    }
                }
                if(len==0) printf("You won't be eaten!\n");//empty string
                else if(flag==1) printf("You won't be eaten!\n");
                else printf("Uh oh..\n");
    }
    return 0;
}

#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;

char str[55];
bool flag;
int t,c,i,j,len;

int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    getchar();
    for(c=1;c<=t;c++){
        gets(str);
        printf("Case %d: ",c);
        len=strlen(str);
        for(i=0,j=len-1;i<len;i++,j--){
            if(str[i]==str[j]) flag=1;
            else{
                flag=0; break;
            }
        }
        if(flag==1) puts("Yes");
        else puts("No");
    }
    return 0;
}

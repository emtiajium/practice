#include<stdio.h>
#include<string.h>
using namespace std;


int n,i,j,pos;
bool flag;
char str[10][101],min[101],tmp[101];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",str[i]);
    }
    /*for(i=0;i<n;i++){
        printf("%s ",str[i]);
    }puts("");*/
    for(i=0;i<n;i++){
        flag=false;
        strcpy(min,str[i]);
        for(j=i;j<n;j++){
            if(strcmp(str[j],min)<0){
                pos=j;
                flag=true;
                strcpy(min,str[j]);
            }
        }
        if(flag){
            strcpy(tmp,str[i]);
            strcpy(str[i],str[pos]);
            strcpy(str[pos],tmp);
        }
    }
    for(i=0;i<n;i++){
        printf("%s ",str[i]);
    }
    return 0;
}


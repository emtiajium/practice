#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
int fib[55]={0,1},arr[55];
char str[110],str2[110];
int t,i,j,k,p,q,n,high;
int main()
{
    for(i=1;i<24;i++){
        fib[2*i-1]=fib[i-1]*fib[i-1]+fib[i]*fib[i];
        fib[2*i]=(2*fib[i-1]+fib[i])*fib[i];
    }
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        q=arr[i-1];
        getchar();
        gets(str);
		memset(str2,' ',sizeof(str2));
		high=0;
        for(i=j=0;;i++){
            if(!isupper(str[i])) continue;
            for(k=2;;k++){
                if(arr[j]==fib[k]){
                    p=k-1;
                    if(p>high) high=p;
                    break;
                }
            }
            str2[p]=str[i];
            if(arr[j]==q) break;
            j++;

        }
        str2[high+1]=NULL;
        for(i=strlen(str2)-1;!isupper(str2[i]);i--){}
        str2[i+1]=NULL;
        for(j=1;str2[j];j++)
            putchar(str2[j]);
        puts("");
    }
    return 0;
}

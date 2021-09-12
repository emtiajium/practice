#include<stdio.h>
int arr[4];
int t,c,i;
bool flag;
int main()
{
    scanf("%d",&t);
    for(c=1;c<=t;c++){
        for(i=0;i<3;i++)
            scanf("%d",&arr[i]);

        for(i=0;i<3;i++){
            if(arr[i]<=20) flag=1;
            else{
                flag=0;
                break;
            }
        }
        printf("Case %d: ",c);
        if(flag==1) puts("good");
        else puts("bad");
    }
    return 0;
}

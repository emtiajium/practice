#include<stdio.h>
#include<math.h>
#include<string.h>
const int MAX=30;
char word[MAX];
int de[MAX],ss[30];
int t,cases,i,j,l,p;
double c,d;
int main(void)
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%s",word);
        l=strlen(word);
        for(i=j=0;i<l;i++){
            p=word[i]-65;
            ss[p]++;
            if(ss[p]>1) de[j++]=ss[p];
        }
        c=d=1;
        for(i=2;i<=l;i++){
            printf("i %d\n",i);
            c*=i;//factorial
            printf("c %.0lf\n",c);
            if(j>0){ d*=de[--j]; printf("d %.0lf\n",d);}
            bool flag=false;
            if((d!=1) && !(fmod(c,d))){
                c /= d;
                d=1;
                flag=true;
            }
            if(flag){
                printf("**c %.0lf\n",c);
                printf("**d %.0lf\n",d);
            }
        }
        printf("Data set %d: %.0f",++cases,c);
        putchar('\n');
        memset(de,0,sizeof(de));
        memset(ss,0,sizeof(ss));
    }
    return 0;
}

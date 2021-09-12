//Big Number Subtraction
#include<stdio.h>
#include<string.h>
const int MAX=1000;
char s1[MAX],s2[MAX],tmp[MAX],sub[MAX];
int i,j,l1,l2,m,n,temp,hold,diff;
bool sign;
int main()
{
    while(scanf("%s %s",s1,s2)!=EOF){
        l1=strlen(s1);
        l2=strlen(s2);
        sign=0;
        if(l1<l2){
            temp=l1;
            l1=l2;
            l2=temp;
            strcpy(tmp,s1);
            strcpy(s1,s2);
            strcpy(s2,tmp);
            sign=1;
        }
        if(l1==l2){//1234 & 1454 both's len=4 but s1<s2 so swap it
            if(strcmp(s1,s2)<0){
                strcpy(tmp,s1);
                strcpy(s1,s2);
                strcpy(s2,tmp);
                sign=1;
            }
        }
        printf("s1=%s s2=%s\n",s1,s2);
        m=l1-1;
        n=l2-1;
        for(i=0,hold=0;i<l1;i++,m--,n--){
            if(n>=0)diff=(s1[m]-'0')-(s2[n]-'0')-hold;
            /*s1=1269 s2=1185
            2nd itteration 16-8=8 so next step adjacent 2 will be 1
            for that reason -hold*/
            else diff=(s1[m]-'0')-hold;
            if(diff<0){
                hold=1;
                tmp[i]=diff+'0'+10;
            }
            else{
                tmp[i]=diff+'0';
                hold=0;
            }
        }
        tmp[i]=NULL;
        puts(tmp);
        for(i=l1-1;i>0;i--){//1269-1125=4410//reverse
            if(tmp[i]!='0') break;//this loop is for 441
        }
        tmp[i+1]=NULL;
        for(j=i,i=0;j>=0;j--,i++)//114
            sub[i]=tmp[j];

        sub[i]='\0';
        if(sign==1) printf("-%s\n",sub);
        else puts(sub);
    }
return 0;
}

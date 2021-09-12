#include<stdio.h>
#include<string.h>
char name1[25],name2[25];
int main()
{
    int t,i,j,k,l1,l2,x;
    scanf("%d\n",&t);
    for(i=1;i<=t;i++){
        gets(name1);
        gets(name2);
        l1=strlen(name1);
        l2=strlen(name2);
        if(l1==l2){
            for(j=0;j<l1;j++){
                //consonent consonent
                if((name1[j]!='a'&&name1[j]!='e'&&name1[j]!='i'&&name1[j]!='o'&&name1[j]!='u')&&(name2[j]!='a'&&name2[j]!='e'&&name2[j]!='i'&&name2[j]!='o'&&name2[j]!='u'))
                {
                    if(name1[j]==name2[j]) x=2;
                    else{
                        x=3;
                        break;
                    }
                }
                //vowel vowel
                else if((name1[j]=='a'||name1[j]=='e'||name1[j]=='i'||name1[j]=='o'||name1[j]=='u')&&(name2[j]=='a'||name2[j]=='e'||name2[j]=='i'||name2[j]=='o'||name2[j]=='u'))
                {
                    x=2;
                }
                //vowel consonent
                else if((name1[j]=='a'||name1[j]=='e'||name1[j]=='i'||name1[j]=='o'||name1[j]=='u')&&(name2[j]!='a'&&name2[j]!='e'&&name2[j]!='i'&&name2[j]!='o'&&name2[j]!='u'))
                {
                    if(name1[j]==name2[j]) x=2;
                    else{
                        x=3;break;
                    }
                }
                //consonent vowel
                else if((name1[j]!='a'&&name1[j]!='e'&&name1[j]!='i'&&name1[j]!='o'&&name1[j]!='u')&&(name2[j]=='a'||name2[j]=='e'||name2[j]=='i'||name2[j]=='o'||name2[j]=='u'))
                {
                    if(name1[j]==name2[j]) x=2;
                    else{
                        x=3;break;
                    }
                }
            }
            if(x==2) printf("Yes\n");
            else printf("No\n");
        }
        else printf("No\n");
    }
    return 0;
}

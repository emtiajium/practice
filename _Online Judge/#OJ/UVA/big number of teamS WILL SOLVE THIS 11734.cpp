#include<stdio.h>
#include<string.h>
char team[25],judge[25],temp_team[25];
int t,c,i,j,length1,length2,length,_length,answer;
int main(void)
{
    scanf("%d",&c);
    getchar();
    for(t=1;t<=c;t++){
        gets(team);
        gets(judge);
        length1=strlen(team);
        length2=strlen(judge);
        if(length1>=length2) length=length1;
        else length=length2;
        for(i=0;i<length;i++){
            if(team[i]==judge[i]) answer=1;
            else{
                answer=0;break;
            }
        }
        if(answer==1) printf("Case %d: Yes\n",t);
        else{
            //FOR NON YES OUTPUT
            for(i=0,j=0;i<length;i++){
                if(team[i]==' ') continue;
                else if((team[i]>=65&&team[i]<=90)||(team[i]>=97&&team[i]<=122))
                temp_team[j]=team[i];
                j++;
            }//lenght=j;
            if(length2>=j) _length=length2;
            else _length=j;
            for(i=0;i<_length;i++){
                if(temp_team[i]==judge[i]) answer=2;//OFE
                else if(temp_team[i]!=judge[i]){
                    answer=3; break;//WA
                }
            }
            if(answer==2) printf("Case %d: Output Format Error\n",t);
            else if(answer==3) printf("Case %d: Wrong Answer\n",t);
        }
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
char fir[1050],temp[1050],pro[1050];
int p,sec[105],i,j,k,l1,l2,m,n,sum,hold;
int main()
{
    while(gets(fir)){
        scanf("%d",&p);
        getchar();
        for(i=0;p!=0;i++){
            sec[i]=p%10;
            p/=10;
        }
        l1=strlen(fir);
        l2=i;
        m=l1-1;
        hold=0;
        for(i=0;i<l1;i++,m--){
            //n=l2-1;
            for(j=0;j<l2;j++){
                sum=((fir[m]-48)*sec[j])+hold;
                if(j==0){
                    temp[i]=(sum%10)+48;
                    hold=sum/10;
                }
                else hold=sum;
            }
        }
        printf("hold %d\n",hold);
        if(hold){
            while(hold!=0){
                temp[i++]=(hold%10)+48;
                hold/=10;
            }
        }
        for(j=i-1,i=0;j>=0;j--,i++)
            pro[i]=temp[j];

        pro[i]='\0';
        puts(pro);
    }
    return 0;
}

// Super long sums  10013
#include<stdio.h>
const int SIZE=1000005;
char s1[SIZE],s2[SIZE],res[SIZE];
int i,j,m,sum,hold;

char dummy[4000020];
int t,len,b_line,real_len,k,l;
int main()
{
    //freopen("input.txt","r",stdin);
    b_line=1;
    scanf("%d",&t);
    while(t--){
        if(b_line!=1) putchar('\n');
        scanf("%d",&len);
        getchar();
        real_len=len;
        len=(len*3)+len;
        for(i=0;i<len;i++)
            dummy[i]=getchar();

        dummy[i]='\0';
        /*printf("%s",dummy);
        for(j=0;j<i;j++){
            printf("[%d] A%cA",j,dummy[j]);
            printf("\n");
        }*/
		for(i=0,k=0,l=0;dummy[i];i+=4,k++,l++){
            s1[k]=dummy[i];
            s2[l]=dummy[i+2];
		}
		s1[k]='\0';
		s2[l]='\0';
        m=real_len-1;
        for(i=0,hold=0;i<real_len;i++,m--){
            sum=(s1[m]-'0')+(s2[m]-'0')+hold;
            res[i]=sum%10+'0';
            hold=sum/10;
        }
        if(hold) res[i++]=hold+'0';
        for(j=i-1,i=0;j>=0;j--,i++)
            putchar(res[j]);

        putchar('\n');
        b_line++;
    }
    return 0;
}

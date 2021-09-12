#include<stdio.h>
int main()
{
    int i,t,d1,d2,m1,m2,y1,y2,j;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d/%d/%d",&d1,&m1,&y1);
        scanf("%d/%d/%d",&d2,&m2,&y2);
        j=y1-y2;
        if(j>0){
            if(j>131) printf("Case #%d: Check birth date\n",i);
            else if((j)==131 && (m1==m2)&& (d1>=d2)) printf("Case #%d: Check birth date\n",i);
            else{
                if(m1>m2) printf("Case #%d: %d\n",i,j);//output can be 131
                else if(m1<m2) printf("Case #%d: %d\n",i,j-1);
                else if(m1==m2){
                    if(d1>=d2) printf("Case #%d: %d\n",i,j);
                    else if(d1<d2) printf("Case #%d: %d\n",i,j-1);
                }
            }
        }
        else if(!j){
            if(m1>m2) printf("Case #%d: 0\n",i);
            else if((m1==m2)&&(d1<d2)) printf("Case #%d: Invalid birth date\n",i);
            else if(m1<m2) printf("Case #%d: Invalid birth date\n",i);
            else if(m1==m2){
                if(d1>=d2) printf("Case #%d: 0\n",i);
                else if(d1<d2) printf("Case #%d: Invalid birth date\n",i);
            }
        }
        else printf("Case #%d: Invalid birth date\n",i);
    }
    return 0;

}

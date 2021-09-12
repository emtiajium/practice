#include<stdio.h>

struct list{
    int val;
    list *m;
};
list *x,*start,*temp;
int pos,i,n;
int main()
{
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&n)==1){
        x=new list;
        scanf("%d",&x->val);
        start=x;
        for(i=1;i<n;i++){
            x->m=new list;
            x=x->m;
            scanf("%d",&x->val);
        }
        x->m=NULL;
        puts("Before inserting data");
        x=start;
        while(x!=NULL){
            printf("%d %d %d\n",x->val,&x->val,x->m);//ভ্যালু, তার নিজের অ্যাড্রেস, যাকে লিঙ্ক করছে।
            x=x->m;
        }
        temp=new list;
        puts("\nENter data & position");
        scanf("%d%d",&temp->val,&pos);
        printf("New data & it's position\n%d %d\n\n",temp->val,&temp->val);
        x=start;
        if(pos==1){
            temp->m=start;
            start=temp;
        }
        else if(pos==n+1){
            while(x->m!=NULL){
                x=x->m;
            }
            x->m=temp;
            temp->m=NULL;
        }
        else{
            pos--;
            for(i=1;i<=pos;i++){
                if(i==pos){
                    temp->m=x->m;
                    x->m=temp;
                }
                x=x->m;
            }
        }
        x=start;
        while(x!=NULL){
            printf("%d %d %d\n",x->val,&x->val,x->m);
            x=x->m;
        }
        delete x;
        delete temp;
    }
    return 0;
}

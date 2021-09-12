#include<stdio.h>

struct list{
    int val;
    list *m;
};

list *x,*start,*temp;
int pos,i,n,del;

int main()
{
    while(scanf("%d",&n)==1){
        x=new list;//list এর অ্যাড্রেস x এর জন্য নির্ধারিত হবে।
        scanf("%d",&x->val);
        start=x;
        for(i=1;i<n;i++){
            x->m=new list;
            x=x->m;
            scanf("%d",&x->val);
        }
        x->m=NULL;
        puts("Before deleting data");
        x=start;
        while(x!=NULL){
            printf("%d (%d) %d\n",x->val,&x->val,x->m);
            x=x->m;
        }
        puts("");
        x=start;
        scanf("%d",&del);
        for(pos=1;;pos++){
            if(x->val==del)break;
            x=x->m;
            temp=x;
        }
        x=x->m;
        temp=x;// যেটা ডিলিট করবো তারপরেরটা স্টোর করার জন্য
        x=start;
        if(pos==1) start=x->m;
        else if(pos==n){
            pos--;
            for(i=1;i<pos;i++)
                x=x->m;
            x->m=NULL;
        }
        else{
            pos--;
            for(i=1;i<pos;i++)
                x=x->m;
            x->m=temp;
        }
        puts("\nAfter deleting data");
        x=start;
        while(x!=NULL){
            printf("%d (%d) %d\n",x->val,&x->val,x->m);
            x=x->m;
        }
        delete x;
    }
    return 0;
}

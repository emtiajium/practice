#include<stdio.h>

struct node{
    int num;
    node *next,*prev;
};

node *x,*start,*y,*temp;
int i,size,del,pos;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    printf("Enter list size ");
    scanf("%d",&size);
    x= new node;
    start=x;
    scanf("%d",&(*x).num);//x->a & (*x).a equivalent
    (*x).prev=NULL;
    for(i=1;i<size;i++){
        y=x;
        (*x).next=new node;
        x=(*x).next;
        scanf("%d",&(*x).num);
        (*x).prev=y;
    }
    (*x).next=NULL;
    puts("\n\nBefore deleting\n");
    x=start;
    while(x!=NULL){
        printf("%d (%d) %d %d\n",(*x).num,&(*x).num,(*x).prev,(*x).next);
        x=(*x).next;
    }
    puts("\n\nAfter deleting\n");
    x=start;
    scanf("%d",&del);
    for(pos=1;pos<=size;pos++){
        if((*x).num==del) break;
        x=(*x).next;
    }
    x=(*x).next;
    temp=x;// যেটা ডিলিট করবো তারপরেরটা স্টোর করার জন্য
    x=start;
    if(pos==1){
        start=(*x).next;
        (*start).prev=NULL;

    }
    else if(pos==size){
        pos--;
        for(i=1;i<pos;i++)
            x=(*x).next;
        (*x).next=NULL;
    }
    else{
        pos--;
        for(i=1;i<pos;i++)
            x=(*x).next;

        y=x;// যেটা ডিলিট করবো আগেরটা স্টোর করার জন্য
        (*x).next=temp;
        (*temp).prev=y;
    }
    x=start;
    while(x!=NULL){
        printf("%d (%d) %d %d\n",(*x).num,&(*x).num,(*x).prev,(*x).next);
        x=(*x).next;
    }
    delete x;
    return 0;
}

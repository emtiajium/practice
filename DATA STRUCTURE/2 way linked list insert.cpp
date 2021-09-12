#include<stdio.h>

struct node{
    int num;
    node *next,*prev;
};

node *x,*start,*y,*temp;
int i,b,size,pos;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    printf("Enter list size ");
    scanf("%d",&size);
    x= new node;
    start=x;
    scanf("%d",&x->num);
    x->prev=NULL;
    for(i=1;i<size;i++){
        y=x;
        x->next=new node;
        x=x->next;
        scanf("%d",&x->num);
        x->prev=y;
    }
    x->next=NULL;
    puts("\n\nBefore Inserting\n");
    x=start;
    while(x!=NULL){
        printf("%d (%d) %d %d\n",x->num,&x->num,x->prev,x->next);
        x=x->next;
    }
    temp=new node;
    printf("Enter position & data ");
    scanf("%d%d",&pos,&temp->num);
    printf("\nNew data & it's position\n%d %d\n\n",temp->num,&temp->num);
    x=start;
    if(pos==1){
        temp->prev=NULL;
        temp->next=start;
        start=temp;
        x->prev=temp;
    }
    else if(pos==size+1){
        while(x->next!=NULL){
            x=x->next;
        }
        x->next=temp;
        temp->prev=x;
        temp->next=NULL;
    }
    else{
        pos--;
        for(i=1;i<pos;i++){
            x=x->next;
        }
        temp->next=x->next;
        temp->prev=x;
        x->next=temp;
        x=temp->next;
        x->prev=temp;
    }
    x=start;
    while(x!=NULL){
        printf("%d (%d) %d %d\n",x->num,&x->num,x->prev,x->next);
        x=x->next;
    }
    puts("");
    delete x;
    delete temp;
    return 0;
}

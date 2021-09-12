#include<stdio.h>

struct list
{
    int a;
    list *m;
};
list *x,*start;
int i;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    x=new list;
    //printf("Blah %d\n",x);
    scanf("%d",&x->a);
    start=x;
    for(i=1;i<5;i++){
        x->m=new list;
        x=x->m;
        scanf("%d",&x->a);
    }
    x->m=NULL;

    x=start;
    while(x!=NULL){
        printf("%d %d\n",x->a,x->m);
        x=x->m;
    }

    delete x;
    return 0;
}

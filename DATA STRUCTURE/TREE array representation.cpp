#include<stdio.h>
#include<string.h>
char str[50][8],tree[200],root,ch;
int edge,i,j,l_c,r_c,len;
int main()
{
    freopen("input.txt","r",stdin);
    memset(tree,'1',sizeof(tree));
    scanf("%c %d",&root,&edge);
    getchar();
    tree[0]=root;
    for(i=0;i<edge;i++)
        gets(str[i]);

    for(i=0;i<edge;i++){
        for(j=0;tree[j]!=str[i][0];j++){}
        l_c=2*j+1;
        r_c=l_c+1;
        if(str[i][2]=='L') tree[l_c]=str[i][4];
        else if(str[i][2]=='R') tree[r_c]=str[i][4];
    }
    if(l_c>r_c) len=l_c;
    else len=r_c;
	len++;
    tree[len]=NULL;
    for(i=0;i<len;i++){
        if(tree[i]=='1') continue;
		printf("[%3d] -> %c\n",i,tree[i]);
	}
	scanf("%c",&ch);
	putchar(ch);
	for(i=0;tree[i]!=ch;i++){}
	while(tree[i]!=root){
	    j=i;
	    i/=2;
	    l_c=2*i+1;
	    r_c=l_c+1;
	    if(tree[l_c]!=tree[j]||tree[l_c]!=tree[j]) i--;
        printf(" <- %c",tree[i]);
	}
    return 0;
}

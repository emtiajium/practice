#include <stdio.h>
#include <string.h>

int post(char in[],char root,int n);

char par[1000];

int main()
{
    int test,i,j,k,l,n;
    char pre[1000],in[1000],temp;

    scanf("%d",&test);

    for(l=0;l<test;l++)
    {
        memset(par,0,sizeof(par));
        scanf("%d %s %s",&n,pre,in);

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(pre[i]==in[j])
                {
                    temp=par[in[j]];
                    for(k=j-1;k>-1 && par[in[k]]==temp ;k--)
                        par[in[k]]=pre[i];
                    for(k=j+1;k<n && par[in[k]]==temp ;k++)
                        par[in[k]]=pre[i];
                }
            }
        }
        post(in,pre[0],n);
    }
}

int post(char in[],char root,int n)
{

    char stack[1000],left,right,val;
    int TOP=0,i,j;

    stack[TOP++]=root;

    while(TOP)
    {
        val=stack[--TOP];
        left=right='\0';

        for(i=0;i<n;i++)
            if(par[in[i]]==val)
            {
                left=in[i];
                break;
            }
        for(i=i+1;i<n;i++)
            if(par[in[i]]==val)
            {
                right=in[i];
                break;
            }
        if(left=='\0' && right=='\0')
        {
            printf("%c",val);
            par[val]='\0';
        }
        else
        {
            stack[TOP++]=val;
            if(right!='\0')
                stack[TOP++]=right;
            if(left!='\0')
                stack[TOP++]=left;
        }
    }
    printf("\n");
    return 0;
}

/*
Input:

format: n preorder inorder
3
3 xYz Yxz
3 abc cba
6 ABCDEF CBAEDF

Output:
Yzx
cba
CBEFDA
*/
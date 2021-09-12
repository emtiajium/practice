#include<stdio.h>
#include<conio.h>
char name[100];
int main()
{
    int a,b,c,d,e,f,g,h,i,j,count=0;
    printf("    Hello, this is Emtiaj Hasan. This is a quiz program. Participate to it.\n\n");
    printf("\t\tEnter your name please.\n\n\t\t");
    scanf("%[^\n]",name);
    
    printf("\n  A)What is the capital city of Bangladesh?\n\n");
    printf("  1) Dhaka\t2) Chittagong\t3) Rajshahi\t4) Sythet\n>");
    scanf("%d",&a);
    if(a==1)
    printf("  You are right\n");
    else printf("  Sorry,you are wrong\n");
    if(a==1) count++;
    
    
    printf("\n  B)Who gave the thesis of Theory of Relativity?\n\n");
    printf("  1) Jamal Najrul Islam\t2) Einstien\t3) Stephen Hawking\t4) Max Plank\n>");
    scanf("%d",&b);
    if(b==2)
    printf("  You are right\n");
    else printf("  Sorry,you are wrong\n");
    if(b==2) count++;
    
    
    printf("\n  C)How many keywords have ANSI C language?\n\n");
    printf("  1) 25\t2) 20\t3) 32\t4) 40\n>");
    scanf("%d",&c);
    if(c==3)
    printf("  You are right\n");
    else printf("  Sorry,you are wrong\n");
    if(c==3) count++;
   
    
    printf("\n  D)Who made the Cosmic Calendar?\n\n");
    printf("  1) Isaac Asimov\t2) Carl Sagan\t3) Nicolas Caviste\t4) Arthur C. Clarke\n>");
    scanf("%d",&d);
    if(d==2)
    printf("  You are right\n");
    else printf("  Sorry,you are wrong\n");
    if(d==2) count++;
    
    
    printf("\n  E)How many Planets have the Solar system gotten?\n\n");
    printf("  1) 10 \t2) 7\t3) 8\t4) 9\n>");
    scanf("%d",&e);
    if(e==3)
    printf("  You are right\n");
    else printf("  Sorry,you are wrong\n");
    if(e==3) count++;
    
    
    printf("\n  F)Who invented Nylon?\n\n");
    printf("  1) wallace carothers\t2) Frank Whittle\t3) James Clarke\t4) Gottlieb Daimler\n>");
    scanf("%d",&f);
    if(f==1)
    printf("  You are right\n");
    else printf("  Sorry,you are wrong\n");
    if(f==1) count++;
    
    
    
    printf("\n  G)Who gave this equation : e^(i*pi)+1=0?\n\n");
    printf("  1) Carl Friedrich Gauss \t2) Paul Erdos\t3) Srinivasa Ramanujan\t4) Leonhard Euler\n>");
    scanf("%d",&g);
    if(g==4)
    printf("  You are right\n");
    else printf("  Sorry,you are wrong\n");
    if(g==4) count++;
    
    
    printf("\n  H)How many data types have C got?\n\n");
    printf("  1) 6\t2) 5\t3) 7\t4) 8\n>");
    scanf("%d",&h);
    if(h==2)
    printf("  You are right\n");
    else printf("  Sorry,you are wrong\n");
    if(h==2) count++;
    
    
    printf("\n  I)What is not an operating system?\n\n");
    printf("  1) Windows 7\t2) Linux\t3) Ubuntu\t4) Snow leopard\n>");
    scanf("%d",&i);
    if(i==2)
    printf("  You are right\n");
    else printf("  Sorry,you are wrong\n");
    if(i==2) count++;
    
    
    printf("\n  J)Who designed Sears Tower (now Willis Tower)?\n\n");
    printf("  1) Fazlur Rahman Khan\t2) John Hancock \t3) Allen Downey\t4) Jeffrey Elkner\n>");
    scanf("%d",&j);
    if(j==1)
    printf("  You are right\n");
    else printf("  Sorry,you are wrong\n");
    if(j==1) count++;
    

    printf("\n  %s, you have got %d on 10.",name,count);

    getch();
    return 0;
}
    

/*This is my First Project of L-1 T-1>>Muhammad Kamrul Hossain Patwary<<*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(void)
{
int a,b,d,e,f,i,k,j,p,x1,x2,l;
char s[100],s1[10],s2[10],c,name[]="cuet",pass[]="cse10";
q:
//clrscr();
printf("\n\n\n\n\nEnter Name and Password for Playing:\n");
printf("\nType 0 to Quit\n");
printf("\n\n\n\nEnter Name:\n");
gets(s1);
if(s1[0]=='0')
return 0;
x1=strcmp(s1,name);
printf("\n\nEnter Password:\n");
gets(s2);
x2=strcmp(s2,pass);
if(x1!=0||x2!=0)
{printf("\nIncorrect Name and Password Combination\n");
goto q;}
//clrscr();
printf("\n\n\nLog in Successful. WELCOME to PLAY!\n");
printf("----------------------------------------------\n\n\n\n");
r:
printf("\nWhich Game you want to play?\n");
printf("------------------------------------------------\n\n");
printf("\nPress 1 to Play Type Learning Game\n");
printf("\nPress 2 to Play Alien Language Game\n");
printf("\nPress 3 to Quit\n");
c=getch();
if(c=='1')
goto game1;
else if(c=='2')
goto game2;
else
{//clrscr();
printf("\n\nThanx for Exploring! Press any key to Quit.....\n");
c=getch();
return 0;}

game1:
{//clrscr();
printf("\nLearn Type: Type Exactly the Sentence below:\n");
int num=0;
i=0;
char s3[]="This is the last class of cse 10 L-1 T-1 and my first project!";
l=strlen(s3);
printf("\n");
printf("\n%s\n",s3);
 for(i=0;i<l;i++)
 {c=getch();
 if(c==s3[i])
  {putchar(c);
  num++;}
 else
 putchar('?');}
 printf("\n\n\n__________________________________________\n");
 printf("\nYour Result:\n");
 printf("\nTotal Character = %d(with space)\n",l);
 printf("\nTotal   Correct   = %d\n",num);
 printf("\nTotal   Failed     = %d\n",l-num);
 printf("\n----------------------------------------------");
 printf("\n\n\n           Want to play again? Press (Y/N)\n\n");
 c=getch();
 if(c=='Y'||c=='y')
 {//clrscr();
 goto game1;}
 else
 {//clrscr();
 goto r;}
}
game2:
{//clrscr();
printf("\n\n\nWelcome to Alien Language Game!\n\n");
printf("\nType a Sentence and if Finished Press Enter:\n\n\n\n");
printf("Your Language:\n\n\n");
gets(s);
a=strlen(s);
printf("\n\n\nAlien Language!!!:\n\n\n");
p=0;
for(i=0;i<=a;i++)
{
if(s[i]==' '||s[i]=='\0')
{
if(s[i]=='\0'&&s[i-1]==' ')
break;
c=s[p];
s[p]=s[i-1];
s[i-1]=c;
p=i+1;}
}
printf("\n");
for(i=0;i<=a;i++)
{if((s[i]==' '||s[i]=='\0')&&s[i-1]!=' ')
printf("a ");
else
printf("%c",s[i]);}
printf("\n\n\n -----------Want to play again? Press (Y/N)\n\n");
 c=getch();
 if(c=='Y'||c=='y')
 {//clrscr();
 goto game2;}
 else
 {//clrscr();
 goto r;}
}
}

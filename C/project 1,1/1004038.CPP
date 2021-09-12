			/*Project:Quiz Contest*/

#include<stdio.h>
#include<conio.h>
int main()
{
clrscr();
int q[10];
int r,w,n;
textcolor(BLUE);
printf("\n\n\t\t\t  ");
  cprintf("QUIZ CONTEST 2011-2012");
  printf("\n\n\t\t");
  cprintf(" CHITTAGONG UNIVERSITY OF ENGINEERING & TECHNOLOGY");
  printf("\n\n");
  textcolor(YELLOW);
  cprintf("RULES:TEN QUESTIONS WILL BE ASKED.EACH QUESTION HAS FOUR OPTIONS.EVERY CORRECT  ANSWER CONTAINS TEN MARKS AND EVERY WRONG ANSWER CONTAINS MINUS FIVE MARKS.TO   ENTER INTO THE CONTEST PRESS 1.");
  printf("\n");

  r=0;
  w=0;
  scanf("%d",&n);
  printf("\n");
if(n==1)
{ textcolor(WHITE);
  cprintf("Q.1:When 'BIT' was converted into 'Chittagong University of  Engineering &      Technology'?");
  printf("\n");
  cprintf("1)1983 2)1986 3)1993 4)2003");
   printf("\n\n");
   scanf("%d",&q[0]);
  printf("\n");
  if(q[0]==4)
  {
  textcolor(GREEN);
  cprintf("RIGHT ANSWER");
  printf("\n\n");
  r++;}
  else
  {
  textcolor(RED);
  cprintf("WRONG ANSWER");
  printf("\n\n");
  cprintf("RIGHT ANSWER: 4)2003");
  printf("\n\n");
  w++;}
  textcolor(WHITE);
  cprintf("QUES.2:Who discovered the 'Gene Maping' of jute? ");
   printf("\n");
   cprintf("1)Mahbubul Alam 2)Maksudul Alam 3)Mustafijur Rahman 4)Muktar Ahmed");
  printf("\n\n");
  scanf("%d",&q[1]);
  printf("\n");
if(q[1]==2)
  {
  textcolor(GREEN);
  cprintf("RIGHT ANSWER");
  printf("\n\n");
  r++;}
  else
  {
  textcolor(RED);
  cprintf("WRONG ANSWER");
  printf("\n\n");
  cprintf("RIGHT ANSWER: 2)Maksudul Alam");
  printf("\n\n");
  w++;}
  textcolor(WHITE);
  cprintf("Q.3:When the department of CSE was established in Cuet ?");
  printf("\n");
  cprintf("1)1998 2)1999 3)2000 4)2001");
  printf("\n\n");

  scanf("%d",&q[2]);
  printf("\n");
if(q[2]==1)
 {
  textcolor(GREEN);
  cprintf("RIGHT ANSWER");
  printf("\n\n");
  r++;
  }
  else
  {
  textcolor(RED);
  cprintf("WRONG ANSWER");
  printf("\n\n");
  cprintf("RIGHT ANSWER:1)1998");
  printf("\n\n");
  w++;}
  textcolor(WHITE);
  cprintf("Q.4:How many Upazilla are there in Bangladesh");
  printf("\n");
  cprintf("1)493 2)495 3)491 4)393");
  printf("\n\n");
   scanf("%d",&q[3]);
  printf("\n");
if(q[3]==2)
  {
  textcolor(GREEN);
  cprintf("RIGHT ANSWER");
  printf("\n\n");
  r++;}
  else
  {
  textcolor(RED);
  cprintf("WRONG ANSWER");
  printf("\n\n");
  cprintf("RIGHT ANSWER: 2)495");
  printf("\n\n");
  w++;}
  textcolor(WHITE);
  cprintf("Q.5:Which is the second largest economy in the wrold?");
  printf("\n");
  cprintf("1)China 2)India 3)Japan 4)England");
  printf("\n\n");

  scanf("%d",&q[4]);
  printf("\n");
  if(q[4]==1)
  {
  textcolor(GREEN);
  cprintf("RIGHT ANSWER");
  printf("\n\n");
  r++;}
  else
  {
  textcolor(RED);
  cprintf("WRONG ANSWER");
  printf("\n\n");
  cprintf("RIGHT ANSWER:1)China");
  printf("\n\n");
  w++;}
  textcolor(WHITE);
  cprintf("Q.6.What is the atomic number of the element given place in periodic table recently? ");
  printf("\n");
  cprintf("1)114 2)116 3)Both of this 4)None of this");
  printf("\n\n");

  scanf("%d",&q[5]);
  printf("\n");
  if(q[5]==3)
  {
  textcolor(GREEN);
  cprintf("RIGHT ANSWER");
  printf("\n\n");
  r++;}
  else
  {
  textcolor(RED);
  cprintf("WRONG ANSWER");
  printf("\n\n");
  cprintf("RIGHT ANSWER: 3)Both of this");
  printf("\n\n");
  w++;}
  textcolor(WHITE);
  cprintf("QUES.7:Which was the first minicomputer commercilly successful? ");
  printf("\n");
  cprintf("1)CDC 7600 2)Intel 4004 3)IBM 7030 4)PDP-8");
  printf("\n\n");
  scanf("%d",&q[6]);
  printf("\n");
  if(q[6]==4)
  {
  textcolor(GREEN);
  cprintf("RIGHT ANSWER");
  printf("\n\n");
  r++;}
  else
  {
  textcolor(RED);
  cprintf("WRONG ANSWER");
  printf("\n\n");;
  cprintf("RIGHT ANSWER: 4)PDP-8");
  printf("\n\n");
  w++;}
  textcolor(WHITE);
  cprintf("QUES.8:Which programming language is used for scientific research");
  printf("\n");
  cprintf("1)Basic 2)Pascal 3)Fortran 4)none of the above");
  printf("\n\n");
  scanf("%d",&q[7]);
  printf("\n");
  if(q[7]==3)
  {
  textcolor(GREEN);
  cprintf("RIGHT ANSWER");
  printf("\n\n");
  r++;}
  else
  {
  textcolor(RED);
  cprintf("WRONG ANSWER");
  printf("\n\n");
  cprintf("RIGHT ANSWER:3)Fotran");
  printf("\n\n");
  w++;
  }
  textcolor(WHITE);
  cprintf("Q.9:Who is the world no.1 ranked all-rounder in ODI ?");
  printf("\n");
  cprintf("1)Shane Watson 2)Jack Kallis 3)Youvraj Singh 4)Sakib Al-Hasan");
  printf("\n\n");

  scanf("%d",&q[8]);
  printf("\n");
  if(q[8]==1)
  {
  textcolor(GREEN);
  cprintf("RIGHT ANSWER");
  printf("\n\n");
  r++;}
  else
  {
  textcolor(RED);
  cprintf("WRONG ANSWER");
  printf("\n\n");
  cprintf("RIGHT ANSWER:1)Shane Watson");
  printf("\n\n");
  w++;}
  textcolor(WHITE);
  cprintf("Q.10:Which movie was awarded Oscar in 2011?");
  printf("\n");
  cprintf("1)Black Swan 2)The King's speech 3)Inception 4)Heart Locker");
  printf("\n\n");
  scanf("%d",&q[9]);
  printf("\n");
  if(q[9]==2)
  {
  textcolor(GREEN);
  cprintf("RIGHT ANSWER");
  printf("\n\n");
  r++;}
  else
  {
  textcolor(RED);
  cprintf("WRONG ANSWER");
  printf("\n\n");
  cprintf("RIGHT ANSWER: 2)The King's Speech");
  printf("\n\n");
  w++;}
  textcolor(YELLOW);
  printf("\t\t\t");
  cprintf("TOTAL RIGHT ANSWERS=%d",r);
  printf("\n\n\t\t\t");
  cprintf("TOTAL WRONG ANSWERS=%d",w);
  printf("\n\n\t\t\t");
  cprintf("TOTAL MARKS=%d",r*10-w*5);
  printf("\n");
  }
getch();
return 0;
  }
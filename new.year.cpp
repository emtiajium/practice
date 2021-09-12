#include<stdio.h>
#include<conio.h>
#include<windows.h>
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}

int main()
{
char ch;
while(1)
{
   system("CLS");
    int i=0;
    while(i<20)
    {
        gotoxy(i,i);
        printf("WELCOME");
        Sleep(300);
        if(kbhit())
        {
            ch=getche();
            if(ch==13)
            break;
        }
         i++;
    }
    if(ch==13)
    break;
  int   j=0;
    while(i>0)
    {
        i--;
        gotoxy(j,i);
        printf("--2013--");
        Sleep(300);
        if(kbhit())
        {
            ch=getche();
            if(ch==13)
            break;
        }
        j++;
    }
     if(ch==13)
     break;
}

    return 0;
}


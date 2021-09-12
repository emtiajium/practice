#include<stdio.h>
char str[1005];
int i;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(gets(str)){
        for(i=0;str[i];i++){
            switch(str[i]){
                case ' ':
                    putchar(' ');
                    break;
                case ']': case '}':
                    putchar('p');
                    break;
                case '[': case '{':
                    putchar('o');
                    break;
                case 'p': case 'P':
                    putchar('i');
                    break;
                case 'o': case 'O':
                    putchar('u');
                    break;
                case 'i': case 'I':
                    putchar('y');
                    break;
                case 'u': case 'U':
                    putchar('t');
                    break;
                case 'y': case 'Y':
                    putchar('r');
                    break;
                case 't': case 'T':
                    putchar('e');
                    break;
                case 'r': case 'R':
                    putchar('w');
                    break;
                case 'e': case 'E':
                    putchar('q');
                    break;
                case 59: case 58:
                    putchar('k');
                    break;
                case 39: case 34:
                    putchar('l');
                    break;
                case 'l': case 'L':
                    putchar('j');
                    break;
                case 'k': case 'K':
                    putchar('h');
                    break;
                case 'j': case 'J':
                    putchar('g');
                    break;
                case 'h': case 'H':
                    putchar('f');
                    break;
                case 'g': case 'G':
                    putchar('d');
                    break;
                case 'f': case 'F':
                    putchar('s');
                    break;
                case 'd': case 'D':
                    putchar('a');
                    break;
                case 46: case 62:
                    putchar('m');
                    break;
                case 44: case 60:
                    putchar('n');
                    break;
                case 'm': case 'M':
                    putchar('b');
                    break;
                case 'n': case 'N':
                    putchar('v');
                    break;
                case 'b': case 'B':
                    putchar('c');
                    break;
                case 'v': case 'V':
                    putchar('x');
                    break;
                case 'c': case 'C':
                    putchar('z');
                    break;
                default:
                    break;
            }
        }
        puts("");
    }
    return 0;
}

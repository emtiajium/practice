#include<stdio.h>
#include<string.h>
#include<iostream>
#include<conio.h>
using namespace std;
int x,subj,a;
char ch[100];
double C,sum,credit;
int main()
{
    //freopen("input.txt","r",stdin);
    printf("\t\tAt first you should press the number of subject\n\n");
    while(scanf("%d",&subj)==1){
        printf("Enter your grade(respectively) in \nChemistry(theory)\nthen CSE(theory)\nthen Electrical(theory)\nthen MATH\nthen Sociology & Government.\n");
        a=5;sum=0;
        while(a--){
            credit=3;
            scanf("%s",ch);
            if(strcmp(ch,"A+")==0)sum=sum+4*credit;
            else if(strcmp(ch,"A")==0)sum=sum+3.75*credit;
            else if(strcmp(ch,"A-")==0)sum=sum+3.50*credit;
            else if(strcmp(ch,"B+")==0)sum=sum+3.25*credit;
            else if(strcmp(ch,"B")==0)sum=sum+3.00*credit;
            else if(strcmp(ch,"B-")==0)sum=sum+2.75*credit;
            else if(strcmp(ch,"C+")==0)sum=sum+2.50*credit;
            else if(strcmp(ch,"C")==0)sum=sum+2.25*credit;
            else if(strcmp(ch,"D")==0)sum=sum+2.00*credit;
        }
        a=4;
        printf("NOW Enter your grade(respectively) in Chemistry(sessional)\nthen CSE(sessional)\nthen Me(sessional)\nthen EE(sessional)\n");
        while(a--)
        {
            if(a==3)credit=.75;
            else credit=1.5;
            scanf("%s",ch);
            if(strcmp(ch,"A+")==0)sum=sum+4*credit;
            else if(strcmp(ch,"A")==0)sum=sum+3.75*credit;
            else if(strcmp(ch,"A-")==0)sum=sum+3.50*credit;
            else if(strcmp(ch,"B+")==0)sum=sum+3.25*credit;
            else if(strcmp(ch,"B")==0)sum=sum+3.00*credit;
            else if(strcmp(ch,"B-")==0)sum=sum+2.75*credit;
            else if(strcmp(ch,"C+")==0)sum=sum+2.50*credit;
            else if(strcmp(ch,"C")==0)sum=sum+2.25*credit;
            else if(strcmp(ch,"D")==0)sum=sum+2.00*credit;
        }
        sum=sum/20.25;
        printf("YOUR CGPA IS %.4lf\n",sum);
        printf("Now plz enter your GPA of L 1, T 1\n");
        scanf("%lf",&C);
        C=(sum+C);
        printf("The avg is %.4lf\n",C/2.0);

        cout<<"\n\n\t\a\a\athank u for being wid CSE\n";
        getch();
        getch();
    }
    return 0;
}

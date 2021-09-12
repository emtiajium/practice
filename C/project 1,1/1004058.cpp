#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
int a,b,c,d,e,f,g,h,i,j,k=0,l,r,count=0,s;  
printf("##This is a program on a quiz & a calculator##\n\n\n");
printf("##What do u want to do??\n\n\n#For performig in the quiz just press 1\n\n\n#For calculating just press 2\n\n\n#For exit press 3\n\n\n");
scanf("%d",&s);
if(s==1)
{
printf("#This for Quiz is for finding out ur talant\n\nto so be carefull#\n\n\n");
printf("For answering question just press 1 2 3 4.\n\n\nif u can give answer rightly u will get 1 mark\n\n\n");
for(;r=1;)
{
printf("#Q.1 what is capital name of bangladesh\n\n\n1. borisal  2. comilla\n\n3. dhaka  4. mymensingh\n\n\n"); 
scanf("%d",&a);
if(a==3)
{
count++;
printf("ur answer is right\n\n\n");
}
else if(a>=5)
{k++;
printf("\a\a\awrong input\n\n\n");}
else
{
k++;
printf("ur answer is wrong\n\n\n");
}
printf("Q.2 what is best for us\n\n\n1. playing  2. gerdaning\n\n3. chatting  4. eating\n\n\n");
scanf("%d",&b);
if(b==2)
{
count++;
printf("ur answer is right\n\n\n");
} 
else if(b>=5)
{
     k++;
printf("\a\a\awarnig\n ur input is wrong\n\n\n");
}
else
{
k++;
printf("ur answer is wrong\n\n\n");
}
printf("Q.3 who is great leader\n\n1. b bondu  2. s zia\n\n3. easad  4. f hoque\n\n\n");
scanf("%d",&c);
if(c==4)
{
count++;
printf("ur answer is right\n\n\n");        
}    
else if(c>=5)
{
     k++;
printf("\a\a\awrong input\n\n\n");
}
else
{
    k++;
    printf("ur answer is weong\n\n\n");
}
printf("ur score is :%d\n\n\n",count);
printf("u have answered wrong:%d\n\n\n",k);
if(count==3)
printf("!!!!!congratulation!!!!!\n\n\n");
if(k==2)
printf("very bad");
printf("do u want to give answer again\n\nfor giving answer press 1 & for exit press 2\n\n");
scanf("%d",&r);
if(r==1)
continue;
else if(r>=3)
{printf("\a\awrong input\n\n\n");
break;}
else
{r=2;
break;
}
}
}
if(s==2)
{
int x;
for(;x=1;)
{        
int a;
printf("#What type of calculation u want to do:\n\n\n1. For sumission press 1\n\n\n2. For finding out difference press 2\n\n\n3.For multipicaton press 3\n\n\n ");
printf("4. for division press 4\n\n\n");
printf("5. For squre press 5\n\n\n");
printf("6. For squreroot press 6\n\n\n");
printf("7. For finding out sinx's value press 7\n\n\n");
printf("8. For finding out cosx's value press 8\n\n\n");
scanf("%d",&b);
if(b==1)
{
printf("enter values & then  press'0'and enter for the result\n\n\n ");
 c=0;
while(a!=0)
{{
scanf("%d",&a);      
c=float(c+a);
if(a==0)
printf("#resut is:%d\n\n\n",c);
}
}}
if(b==2)
{
printf("enter two numbers\n\n\n ");
scanf("%d%d",&c,&b);
if(c>b)
printf("#the result is:%d\n\n\n",c-b);
if(b>c)
printf("#the result is:%d\n\n\n",b-c);
}
if(b==3)
{
printf("enter two values\n\n\n");
scanf("%d%d",&b,&c);
printf("#the result is:%d\n\n\n",b*c);
}
if(b==4)
{
printf("enter two values");
scanf("%d%d",&b,&c);
printf("the result is:%.3f",float(b/c));
}
if(b==5)
{ double c;
printf("enter avalue\n\n\n");
scanf("%lf",&b);
c=pow(b,2);
printf("#the result is:%lf",c);
}
if(b==6)
{ 
double c;
printf("enter a value:");
scanf("%lf",&c);
c=sqrt(c);
printf("#the sqrt is:%lf",c);
}
if(b==7)
{
    int a,i,j,k,n,fact;
double x,sum;
printf("enetr a value:");
scanf("%lf",&x);
x=x*(3.1416/180);
for(j=1,sum=0.0,i=1;i<=10;i++)
{
if(i==1)
sum=sum+x;
else
{
for(k=1,fact=1;k<=j;k++)
fact=fact*k;
if(i%2==0)
{
sum=sum-pow(x,j)/fact;
}
else
{
sum=sum+pow(x,j)/fact;
}
}
j=j+2;
}
printf("the result is:%lf",sum);    
}
if(b==8)
{
int a,i,j,k,n,fact;
double x,sum;
printf("enter a value:");
scanf("%lf",&x);
x=x*(3.1416/180);
for(j=0,sum=0.0,i=1;i<=15;i++)
{
if(i==1)
sum=sum+1;
else
{
for(k=1,fact=1;k<=i;k++)
fact=fact*k;
if(i%2==0)
{
sum=sum-pow(x,j)/fact;
}
else
{
sum=sum+pow(x,j)/fact;
}
}
j=j+2;
}
printf("%lf",sum);
}
printf("Do u want to give calculate again:\n\n\nFor calculating answer press 1\n\n\nFor exist press 2");
scanf("%d",&x);
if(x==1)
continue;
if(x>=2)
break;
}
}
getch();
}
    
    
    
    
    

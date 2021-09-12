// false - Prime
// true - None Prime
#include<stdio.h>
#include<math.h>
#include<time.h >
#include<vector>
using namespace std;

const int SIZE=105;
int i,j,cnd,r,n;
bool flag[SIZE]={true,true};// 0,1,2তম index এর ভ্যালু।
vector<int>prime;
double t1,t2;
int main()
{
    //freopen("output.txt","w",stdout);
    t1=clock();
    prime.push_back(2);
    cnd=sqrt(SIZE)+1;
    for(i=3;i<cnd;i+=2){
        if(flag[i]==false){
            r=i<<1;
            for(j=i*i;j<SIZE;j+=r)//j+=2*i;
                flag[j]=true;
        }
    }
    printf("%d\t",prime[0]);
    for(i=3,j=1;i<SIZE;i+=2){
        if(flag[i]==false){
            prime.push_back(i);
            printf("%d\t",prime[j]);
            j++;
        }
    }
    while(scanf("%d",&n)==1){
        printf("%d'th prime -> %d\n",n,prime[n-1]);
    }/*
    printf("last prime %d\t",prime[j-1]);
    printf("\n\nBetween 0 & %d, there are %d Prime numbers\n\n",SIZE,prime.size());
    prime.clear();
    t2=clock();
    printf("Time required %lfs\n",(t2-t1)/1000);
    */
    return 0;
}

/*
এটাতো জানাই আছে যে ২ বাদে অন্য জোড় সংখ্যাগুলো প্রাইম না। অতএব ২ প্রাইম লিস্টে স্টোর করে শুধুমাত্র বিজোড় সংখ্যা নিয়েই কাজ করবো।
তাহলে লুপ ৩ থেকে শুরু করে ২ করে বাড়াবো।
সিভ মেথডে ৩ যাদের divisor তাদেরকে composit করে দিবো।
তাহলে প্রথমে পড়ে ৬, কিন্তু যেহেতু ৬ জোড়, তাই তাকে নিয়ে কোন চিন্তা করতে হবে না।
পরে আসছে ৯, তাহলে ৩ থেকে ৯ এ যাওয়া যায় বর্গ করে, তাই ইনার লুপটা শুরু করলাম j=i*i থেকে
পরে ১২ বাদ দিয়ে আসে ১৫ যেটা হচ্ছে ৯ + ৩*২
কোডেও সেটাই করলাম। এভাবে আসবে ২১=১৫+৩*২, ২৭, ৩৩........................
যদি আমি r=i+i না দিয়ে r=2*i; দিতাম তাহলে যোগের বদলে গুণের কাজ করতো। এটাতো জানাই আছে গুণের চেয়ে যোগ করতে কম সময় লাগে।
আর যদিj+=i+i; দিতাম প্রতিবার i+i যোগ করতেই থাকতো, কিন্তু প্রতিবারতো একই রেজাল্টই আসতো , তাই আগেই যোগ করে একটা ভ্যারিয়েবলে রেখে দিয়েছি।

তাহলে এভাবে ৩ এর কাজ শেষ হয়ে ৫ এর কাজ শুরু হবে।
প্রথমে ১০, ১৫ কে নিয়ে কাজ করতে হবে না, যেহেতু আগেই তাদেরকে composit হিসেবে সেট করে রেখেছি।
বাকিটা ৩ এর মতোই।
j এর ভ্যালু হবে ২৫, ৩৫,৪৫, ৫৫,৬৫,৭৫,...........................।এভাবে।
খেয়াল করলে দেখবে i এর ভ্যালু 3 হওয়ার সময়ই ৪৫ কে composit হিসেবে সেট করে দেয়া হয়েছিল।
তাহলে কি নতুন করে আবার ২০২৫, ২১১৫, ২২০৫,................ কে composit হিসেবে সেট করার দরকার আছে?
এইজন্যই if(flag[i]==0) condition দেয়া হল যাতে এককাজ দুইবার করতে না হয়।

array global এ declare করার কারণে 0 দিয়ে initialize হয়ে গেছে, তাই composit বুঝাতে  1 ব্যবহার করবো।
তাহলে যেসব index এর value হিসেবে 0 আছে তারাই প্রাইম, এবং সেগুলোই স্টোর করবো।

bool হচ্ছে C++ এর data type যেটার ভ্যালু শুধুমাত্র ০, ১
bool এর পরিবর্তে  charও ব্যবহার করা যায়।
int এর পরিবর্তে bool অথবা char ব্যবহার করা হয় মেমোরি অপচয় না করার জন্য।
*/

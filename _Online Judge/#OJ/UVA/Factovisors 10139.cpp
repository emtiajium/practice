#include<stdio.h>
#include<math.h>
#include<string.h>
#include<vector>
using namespace std;
const int SIZE=46351;
struct TT{
    int val,coun;
};
struct PP{
    int coun2;
};
TT arr[SIZE];
PP arr2[SIZE];
bool pprr[SIZE]={1,1},flag;
vector<int>prime;
int f,d,t_d,m,n,i,j,cnd;
long long zzz;//int >> –2,147,483,648 to 2,147,483,647
//গুন হতে হতে যদি 2,147,483,647 এর বেশি হয়ে যায় তাহলে RTE, তাই unsigned ব্যবহার করলাম।
//আবার 2,147,483,647! এর জন্য ZZZ এর মান 1; 2,147,483,647 ;1; 2,147,483,647 এভাবে infinite loop এ পড়ে যাবে, তাই long long
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    prime.push_back(2);
    for(i=3;i<216;i+=2){
        if(pprr[i]==false){
            m=i+i;
            for(j=i*i;j<SIZE;j+=m)//j+=2*i;
                pprr[j]=true;
        }
    }
    for(i=3;i<SIZE;i+=2){
        if(pprr[i]==false) prime.push_back(i);
    }
    //last prime val 46349
    while(scanf("%d%d",&f,&d)==2){
        if(d==0){
            printf("0 does not divide %d!\n",f);
            continue;
        }
        else if(d==1){
            printf("1 divides %d!\n",f);
            continue;
        }
        t_d=d;
        cnd=sqrt(t_d)+1;
        for(i=m=n=0;prime[i]<cnd&&t_d!=1;i++){
            flag=false;
            while(t_d%prime[i]==0){
                t_d/=prime[i];
                arr[m].val=prime[i];
                arr[n].coun++;
                flag=true;
            }
            if(flag){
                m++;
                n++;
            }
        }
        if(t_d>1){
            arr[m++].val=t_d;// 2147483645 = 5 x 19 x 22605091
            arr[n++].coun++;
        }
        for(j=0;j<m;j++){
            flag=false;
            zzz=arr[j].val;
            while(zzz<=f){
                arr2[j].coun2+=f/zzz;
                zzz*=arr[j].val;
                if(arr2[j].coun2>=arr[j].coun) break;//5^10/5^9
            }
            if(arr2[j].coun2<arr[j].coun){//2^10/2^11
                flag=true;
                break;
            }
        }
        if(flag==false) printf("%d divides %d!\n",d,f);
        else if(flag) printf("%d does not divide %d!\n",d,f);
        memset(arr,0,sizeof(arr));
        memset(arr2,0,sizeof(arr2));
    }
    prime.clear();
    return 0;
}

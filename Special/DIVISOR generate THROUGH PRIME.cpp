#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdio.h>
using namespace std;
#define size_n 100003
#define size_p 8000

bool flag[size_n];
int prime[size_p],store_prime[size_p],prime_frec[size_p],divisors[100000];
int ans,k;
void seive()
{

    int i,j,c=1,m;
    for(i=3;i<=size_n;i+=2)
        flag[i]=true;

    flag[2]=true;
    prime[c++]=2;
    for(i=3;i<size_n;i+=2){
        if(flag[i]){
            prime[c++]=i;
            if(size_n/i>=i){
                m=i*2;
                for(j=i*i;j<size_n;j+=m)
                    flag[j]=false;

            }
        }
    }

//    cout<<prime[c-1];
}

void  Factors(int n)
{
    int i=1,j,count,val,sum=1;
    k=0;
    val=sqrt(n)+1;
    while(prime[i]<=val){
    	if(n%prime[i]==0){
    		count=0;
    		while(n%prime[i]==0){
    			count++;
    			n/=prime[i];
    		}
    		store_prime[k]=prime[i];
    		prime_frec[k]=count;
    		k++;
			val=sqrt(n)+1;
    	}
    	i++;
    }
    if(n>1){
    	store_prime[k]=n;
		prime_frec[k]=1;
		k++;
    }
}

void Generate(int cur,int num)
{
	int i,val;
	if(cur==k) divisors[ans++]=num;
	else{
		val=1;
		for(i=0;i<=prime_frec[cur];i++){
			Generate(cur+1,num*val);
			val*=store_prime[cur];
		}
	}
}

int main()
{
    seive();
    int  T,ks=1,N,i;
    scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		Factors(N);
		ans=0;
		Generate(0,1);
		sort(&divisors[0],&divisors[ans]);
		printf("Case %d:",ks++);
		for(i=0;i<ans;i++)
			printf(" %d",divisors[i]);

		printf("\n");

	}
    return 0;
}

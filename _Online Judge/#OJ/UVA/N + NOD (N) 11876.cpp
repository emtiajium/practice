/*
ফাংশানে ৬ পাঠালে রিটার্ন করবে ১৮
আর ০ থেকে ৬ এর মধ্যে সংখ্যা আছে ৭টা।
*/
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
const int SIZE=1000002;
int ans[SIZE+1]={1};
vector<int>divi(1000003),res(1000003);

void divisor(void){
    int i,j;
    for(i=2;i<SIZE;i++){
        for(j=i;j<SIZE;j+=i)
            divi[j]++;
        divi[i]++;
    }
}
int func(int n){
    if(n==0) return 1;
    if(ans[n]!=0) return ans[n];
    ans[n]=func(n-1) + divi[func(n-1)];
    return ans[n];
}
int main()
{
    int t,cases=0,k,i,a,b,coun;
    divi[0]=0; divi[1]=1; res[0]=0;
    divisor();
    for(k=1;k<SIZE;k++){
        coun=func(k);
        res[coun]=k+1;
        for(i=t+1;i<coun;i++){
            res[i]=res[coun]-1;
        }
        t=coun;
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        coun=res[b]-res[a-1];
        printf("Case %d: %d\n",++cases,coun);
    }
    divi.clear();
    res.clear();
return 0;
}

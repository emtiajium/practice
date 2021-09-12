#include <bits/stdc++.h>
using namespace std;

//const double PI=2*acos(0.0);
typedef long long LL;
const int SIZE=100005;
int arr[SIZE],coun[SIZE],coun2[SIZE],tree[SIZE*3];
int n,q,i,a,b,val;

void initial(int node,int low,int high){
    if(low==high){
        tree[node]=1;
        return;
    }
    int mid,left,right,temp,temp2;
    mid=(low+high)>>1;
    left=node<<1;
    right=left+1;
    initial(left,low,mid);
    initial(right,mid+1,high);
    if(arr[mid]==arr[mid+1]){
        if((mid-low+1)>coun[mid]) temp=coun[mid];
        else temp=coun[mid]-coun[low]+1;
        if((high-(mid+1)+1)>coun2[mid+1]) temp2=coun2[mid+1];
        else temp2=coun2[mid+1]-coun2[high]+1;
        tree[node]=max(max(tree[left],tree[right]),temp+temp2);
        return;
    }
    tree[node]=max(tree[left],tree[right]);
}

int query(int node,int low,int high,int i,int j){
    if(i>high || j<low) return -1;
    if(low>=i && high<=j) return tree[node];
    int left,right,mid,temp,temp2,temp3,temp4,maxx,highh;
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    temp=query(left,low,mid,i,j);
    temp2=query(right,mid+1,high,i,j);
    if(temp==-1 || temp2==-1) return max(temp,temp2); //that was the culprit
    if(arr[mid]==arr[mid+1]){
        if((mid-max(low,i)+1)>coun[mid]) temp3=coun[mid];
        else temp3=coun[mid]-coun[max(low,i)]+1;
        if((min(high,j)-(mid+1)+1)>coun2[mid+1]) temp4=coun2[mid+1];
        else temp4=coun2[mid+1]-coun2[min(high,j)]+1;
        highh=max((temp3+temp4),max(temp,temp2));
        return highh;
    }
    maxx=max(temp,temp2);
    return maxx;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    while(scanf("%d",&n)&&n){
        scanf("%d",&q);
        for(i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        coun[1]=coun2[n]=1;
        for(i=2;i<=n;i++){
            if(arr[i]==arr[i-1]) coun[i]=coun[i-1]+1;
            else coun[i]=1;
        }
        for(i=n-1;i>0;i--){
            if(arr[i]==arr[i+1]) coun2[i]=coun2[i+1]+1;
            else coun2[i]=1;
        }
        initial(1,1,n);
        while(q--){
            scanf("%d%d",&a,&b);
            val=query(1,1,n,a,b);
            printf("%d\n",val);
        }
    }
    return 0;
}

/*
16 3
-41 -30 67 89 99 99 99 100 100 100 100 100 100 100 100 100
1 8
1 16
1 32
0
*/

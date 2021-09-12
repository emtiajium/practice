const int SIZE=100005;
int arr[SIZE],tree[SIZE*3];
int t,cases,test,n,q,i,a,b,val;

void find(int node,int low,int high){
    int mid,add,left,right;
    if(low==high){
        tree[node]=arr[high];
        return;
    }
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    find(left,low,mid);
    find(right,mid+1,high);
    tree[node]=tree[left]+tree[right];
}

int query(int node,int low,int high,int i,int j){
    if(i>high || j<low) return 0;
    if(low>=i && high<=j) return tree[node];
    int left,right,mid,temp,temp2,add;
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    temp=query(left,low,mid,i,j);
    temp2=query(right,mid+1,high,i,j);
    add=temp+temp2;
    return add;
}

void update(int node,int low,int high,int i,int val){
    if(i>high || i<low) return;
    if(low>=i && high<=i){
        tree[node]=val;
        return;
    }
    int left,right,mid;
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    update(left,low,mid,i,val);
    update(right,mid+1,high,i,val);
    tree[node]=tree[left]+tree[right];
}

int main(){
	find(1,1,n);
	val=query(1,1,n,a,b);
	update(1,1,n,a,b+val);
    return 0;
}

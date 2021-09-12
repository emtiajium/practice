#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int first[10005],second[10005];
int test,m,n,i;
int main (){
    //freopen("input.txt","r",stdin);
	scanf("%d",&test);
	while(test--){
		scanf("%d%d",&m,&n);
		for(i=0;i<m;i++)
			scanf("%d",&first[i]);
		for(i=0;i<n;i++)
			scanf("%d",&second[i]);
		vector<int> v(m+n);
		vector<int>::iterator it;
		sort (first,first+m);
		sort (second,second+n);
		it=set_intersection (first, first+m, second, second+n, v.begin());
		v.resize(it-v.begin());
		cout<<(m+n)-2*v.size()<<endl;
		v.clear();
	}
    return 0;
}

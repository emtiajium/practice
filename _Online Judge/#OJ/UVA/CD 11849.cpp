#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int first[1000005],second[1000005];
int m,n,i;
int main (){
	while(scanf("%d%d",&m,&n)&&m&&n){
		for(i=0;i<m;i++)
			scanf("%d",&first[i]);
		for(i=0;i<n;i++)
			scanf("%d",&second[i]);
		vector<int> v(m+n);
		vector<int>::iterator it;
		sort (first,first+m);
		sort (second,second+n);
		it=set_intersection (first, first+m, second, second+n, v.begin());
		cout <<int(it - v.begin())<<endl;
		v.clear();
	}
    return 0;
}

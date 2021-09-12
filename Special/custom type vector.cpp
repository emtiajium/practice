#include<stdio.h>
#include<vector>
using namespace std;
struct TT{
    int aa,bb;
};
TT temp;
vector<TT>arr;
int i;
int main()
{
    for(i=0;i<3;i++){
		temp.aa=i;
		temp.bb=i+1;
        arr.push_back(temp);
    }
    printf("%d\n",arr.size());
    for(i=0;i<3;i++)
        printf("[%d]->%d %d\n",i,arr[i].aa,arr[i].bb);
    arr.clear();
    return 0;
}

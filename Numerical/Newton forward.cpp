#include<stdio.h>
#include<vector>
using namespace std;

int fact[15]={1};
double X[15],Y[15],arr[15][15];
vector<double>needy;
int N,i,j,size;
double p,x,sum;

void facto(){
    int i;
    for(i=1;i<11;i++){
        fact[i]=fact[i-1]*i;
    }
    return;
}

double p_mult(int x){
    double xx=1.0;
    for(i=0;i<x;i++){
        xx*=p-i;
    }
    return xx;
}

int main()
{
    //freopen("input.txt","r",stdin);
    facto();
    while(scanf("%d",&N)==1){
        for(i=0;i<N;i++){
            scanf("%lf",&X[i]);
        }
        for(i=0;i<N;i++){
            scanf("%lf",&Y[i]);
            arr[0][i]=Y[i];
        }
        needy.push_back(Y[0]);
        scanf("%lf",&x);
        p=(x-X[0])/(X[1]-X[0]);
        size=i;
        for(i=0;size!=1;i++){
            for(j=0;j<size-1;j++){
                arr[i+1][j]=arr[i][j+1]-arr[i][j];
            }
            size=j;
            needy.push_back(arr[i+1][0]);
        }
        size=needy.size();
        sum=needy[0];
        for(i=1;i<size;i++){
            sum+=p_mult(i)*needy[i]/fact[i];
        }
        printf("%.3lf\n",sum);
        needy.clear();
    }
    return 0;
}

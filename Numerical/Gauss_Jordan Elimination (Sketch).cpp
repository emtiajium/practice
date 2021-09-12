#include <stdio.h>
#include<algorithm>
using namespace std;

int n,i,j;
double arr[50][51];

void gauss_solve(){
    int i, j, k, max;
    double t;
    for (i = 0; i < n; i++){
        max = i;
        for (j = i + 1; j < n; j++){
            if (arr[j][i] > arr[max][i])
                max = j;
        }
        for (j = 0; j < n + 1; j++){
            swap(arr[max][j],arr[i][j]);
        }
        for (j = n; j >= i; j--){
            for (k = i + 1; k < n; ++k){
                arr[k][j] -= arr[k][i]/arr[i][i] * arr[i][j];
            }
        }
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < n + 1; j++)
            printf("%.2lf\t", arr[i][j]);
        puts("");
    }
    puts("");
    for (i = n - 1; i >= 0; i--){
        arr[i][n] = arr[i][n] / arr[i][i];
        arr[i][i] = 1;
        for (j = i - 1; j >= 0; j--){
            arr[j][n] -= arr[j][i] * arr[i][n];
            arr[j][i] = 0;
        }
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < n + 1; j++)
            printf("%.2lf\t", arr[i][j]);
        puts("");
    }
    puts("");
}

int main(){
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while(scanf("%d", &n)==1){
        for (i = 0; i < n; i++){
            for (j = 0; j < n + 1; j++)
                scanf("%lf", &arr[i][j]);
        }
        gauss_solve();
    }
    return 0;
}

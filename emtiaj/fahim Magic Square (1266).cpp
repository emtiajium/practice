#include <cstdio>
int test;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;

    while(scanf("%d",&n)==1){
        if(test!=0) puts("");
        int** array = new int*[n];
        for(int i=0; i<n; i++)
            array[i] = new int[n];

        int r = 0, c = n/2, l = n*n;
        for(int i=1; i<=l; i++){
            array[r][c] = i;
            if(!(i%n)){
                r++;
            }else{
                r--;
                c++;
            }
            r += n;
            r %= n;
            c %= n;
        }

        int sum = 0;
        for(int i=0; i<n; i++)
            sum += array[0][i];

        printf("n=%d, sum=%d\n", n, sum);
        if(n <= 3){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    printf(" %d", array[i][j]);
                }
                printf("\n");
            }
        }
        else if(n <= 9){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    printf(" %2d", array[i][j]);
                }
                printf("\n");
            }
        }
        else{
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    printf(" %3d", array[i][j]);
                }
                printf("\n");
            }
        }
        test++;
    }

    return 0;
}

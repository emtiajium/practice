#include <stdio.h>

void print_rev(int low, int high, int *a)
{
    if (low == high)
        return;
    print_rev(low+1, high, a);
    printf("%d ",a[low]);
}

int main()
{
    int i, n, a[10];
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    print_rev(0, n, a);
    printf("\n");
    return 0;
}

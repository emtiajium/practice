#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int arr[10];

bool binarySearch(int low, int high, int val) {
    if (low > high) return false;
    int mid = (low + high) >> 1;
    if (arr[mid] == val)
        return true;
    if (arr[mid] > val)
        return binarySearch(low, mid-1, val);
    if (arr[mid] < val)
        return binarySearch(mid+1, high, val);
    return false;
}

int main () {

    int val, i, n = sizeof(arr)/sizeof(int);

    for (i = 0; i < n; i++) {
        arr[i] = rand();
    }

    sort (arr, arr + n);

    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    cin >> val;

    cout << binarySearch(0, n, val);

    return 0;
}

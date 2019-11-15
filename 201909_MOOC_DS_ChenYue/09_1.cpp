#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 5;
int arr[maxn], n;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ' ';
    }
    return 0;
}

/*
samples:
in:
11
4 981 10 -17 0 -20 29 50 8 43 -5
out:
-20 -17 -5 0 4 8 10 29 43 50 981

*/

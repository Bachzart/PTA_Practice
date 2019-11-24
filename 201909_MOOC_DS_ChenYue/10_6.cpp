#include <iostream>
using namespace std;
const int maxn = 100000 + 5;
int pos[maxn], n, ans = 0;
int main() {
    cin >> n;
    int remains = n - 1, tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        pos[tmp] = i;
        if(tmp == i && tmp != 0) remains--;
    }
    int k = 1;
    while(remains > 0) {
        if(pos[0] == 0) {
            while(k < n) {
                if(pos[k] != k) {
                    swap(pos[0], pos[k]);
                    ans++;
                    break;
                }
                k++;
            }
        }
        while(pos[0] != 0) {
            swap(pos[0], pos[pos[0]]);
            ans++;
            remains--;
        }
    }
    cout << ans;
    return 0;
}

/*
samples:
in:
10
3 5 7 2 6 4 9 0 8 1
out£º
9

in:
5
4 0 2 1 3
out:
3

in:
3
0 2 1
out:
2

in:
5
4 3 2 1 0
out:
4

*/

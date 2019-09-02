#include <iostream>
using namespace std;

int main() {
    int n, a, b, c, d, countA = 0, countB = 0;
    cin >> n;
    while(n--) {
        cin >> a >> b >> c >> d;
        if(a + c == b && a + c == d) continue;	// all win
        else if(a + c != b && a + c != d) continue;	// all lose
        else if(a + c == b) countB++;	// A win
        else countA++;	// B win
    }
    cout << countA << ' ' << countB;
    return 0;
}

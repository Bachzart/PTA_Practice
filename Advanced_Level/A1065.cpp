#include <iostream>
using namespace std;

int main() {
    long long t, a, b, c;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> a >> b >> c;
        cout << "Case #" << i << ": ";
        if(a + b < 0 && a > 0 && b > 0) cout << "true"; // positive overflow
        else if(a + b >= 0 && a < 0 && b < 0) cout << "false";  // negative overflow
        else if(a + b > c) cout << "true";  // normal
        else cout << "false";
        cout << endl;
    }
    return 0;
}

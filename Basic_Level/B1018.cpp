#include <iostream>
using namespace std;
char gesture(int *a) {
    int index = 1;
    char ges = '\0';
    for(int i = 1; i <= 3; i++) {
        if(a[i] > a[index]) index = i;
    }
    switch(index) {
        case 1: ges = 'B'; break;
        case 2: ges = 'C'; break;
        case 3: ges = 'J'; break;
    }
    return ges;
}
int main() {
    int n, tie = 0, win = 0, ar[4] = {0}, br[4] = {0};
    cin >> n;
    char a, b;
    for(int i = 1; i <= n; i++) {
        cin >> a >> b;
        if(a == b) tie++;
        else if(a == 'C' && b == 'J') {
            win++;
            ar[2]++;
        }
        else if(a == 'J' && b == 'B') {
            win++;
            ar[3]++;
        }
        else if(a == 'B' && b == 'C') {
            win++;
            ar[1]++;
        }
        else if(b == 'C' && a == 'J') {
            br[2]++;
        }
        else if(b == 'J' && a == 'B') {
            br[3]++;
        }
        else if(b == 'B' && a == 'C') {
            br[1]++;
        }
    }
    cout << win << ' ' << tie << ' ' << n - tie - win << endl;
    cout << n - tie - win << ' ' << tie << ' ' << win << endl;
    cout << gesture(ar) << ' ' << gesture(br);
    return 0;
}

#include <iostream>
using namespace std;
char playcards[55][5] = {
    " ",
    "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
    "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
    "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
    "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
    "J1", "J2",
};
int main() {
    int k, arr[55], brr[55], order[55], flag = 1;
    cin >> k;
    for(int i = 1; i <= 54; i++) {
            cin >> order[i];
            brr[i] = i;
    }
    while(k--) {
        if(flag) {
            for(int i = 1; i <= 54; i++) {
                arr[order[i]] = brr[i];
            }
            flag = 0;
        } else {
            for(int i = 1; i <= 54; i++) {
                brr[order[i]] = arr[i];
            }
            flag = 1;
        }
    }
    if(!flag) {
        for(int i = 1; i <= 54; i++) {
            cout << playcards[arr[i]];
            if(i != 54) cout << ' ';
        }
    } else {
        for(int i = 1; i <= 54; i++) {
            cout << playcards[brr[i]];
            if(i != 54) cout << ' ';
        }
    }
    return 0;
}

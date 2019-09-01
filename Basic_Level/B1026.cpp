#include <iostream>
using namespace std;
int main() {
    int c1, c2, c;
    scanf("%d %d", &c1, &c2);
    c = (c2 - c1 + 50) / 100;
    printf("%02d:%02d:%02d", c / 3600, c / 60 % 60, c % 60);
    return 0;
}

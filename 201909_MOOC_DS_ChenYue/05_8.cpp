#include <iostream>
using namespace std;
const int maxn = 10000 + 5;
int set[maxn];
void initset() {
    for(int i = 0; i < maxn; i++) {
        set[i] = -1;
    }
}
int Find(int elem) {
    if(set[elem] < 0) return elem;
    else return set[elem] = Find(set[elem]);
}
void Union(int root1, int root2) {
    if(set[root2] < set[root1]) set[root1] = root2;
    else {
        if(set[root1] == set[root2]) set[root1]--;
        set[root2] = root1;
    }
}
int main() {
    initset();
    int n, c1, c2;
    cin >> n;
    char act;
    cin >> act;
    while(act != 'S') {
        cin >> c1 >> c2;
        int root1, root2;
        root1 = Find(c1 - 1);
        root2 = Find(c2 - 1);
        if(act == 'C') {
            if(root1 == root2) cout << "yes\n";
            else cout << "no\n";
        } else if(act == 'I') {
            Union(root1, root2);
        }
        cin >> act;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(set[i] < 0) cnt++;
    }
    if(cnt == 1) cout << "The network is connected.";
    else cout << "There are " << cnt << " components.";
    return 0;
}

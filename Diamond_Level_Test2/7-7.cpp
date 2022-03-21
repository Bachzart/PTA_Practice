
#include <iostream>
#include <set>
using namespace std;
const int maxn = 100000 + 5;
set<int> pairs[maxn], stuff;
int n, m, k;

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int tmp_a, tmp_b;
        cin >> tmp_a >> tmp_b;
        pairs[tmp_a].insert(tmp_b), pairs[tmp_b].insert(tmp_a);
    }
    while(m--) {
        cin >> k;
        stuff.clear();
        for(int i = 0; i < k; i++) {
            int tmp;
            cin >> tmp;
            stuff.insert(tmp);
        }
        bool flag = false;
        for(set<int>::iterator it1 = stuff.begin(); it1 != stuff.end(); it1++) {
            int tmp1 = *it1;
            if(pairs[tmp1].size() == 0) continue;
            else {
                for(set<int>::iterator it2 = pairs[tmp1].begin(); it2 != pairs[tmp1].end(); it2++) {
                    int tmp2 = *it2;
                    if(stuff.find(tmp2) != stuff.end()) {
                        flag = true;
                        break;
                    }
                }
            }
            if(flag) break;
        }
        if(flag) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}

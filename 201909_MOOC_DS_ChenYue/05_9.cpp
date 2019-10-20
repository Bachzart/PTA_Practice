#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
const int maxn = 65 + 5;
int hashTable[128] = {0};
bool issubstr(string a, string b) {
	int flag = true;
	for(int i = 0; i < b.length(); i++) {
		if(b[i] != a[i]) {
			flag = false;
			break;
		}
	}
	return flag;
}
int main() {
    priority_queue<int, vector<int>, greater<int> > q;
    int n;
    cin >> n;
    char ch;
    for(int i = 0; i < n; i++) {
        cin >> ch;
        cin >> hashTable[ch];
        q.push(hashTable[ch]);
    }
    int wpl = 0;
    while(q.size() > 1) {
        int n1, n2, n;
        n1 = q.top();
        q.pop();
        n2 = q.top();
        q.pop();
        n = n1 + n2;
        q.push(n);
        wpl += n;
    }
    int m;
    cin >> m;
    while(m--) {
        string codes[maxn];
        int wpl_tmp = 0;
        for(int i = 0; i < n; i++) {
            cin >> ch >> codes[i];
            wpl_tmp += codes[i].length() * hashTable[ch];
        }
		bool prefix = false;
        for(int i = 0; i < n; i++) {
            string str_tmp = codes[i];
            for(int j = 0; j < n; j++) {
                if(str_tmp != codes[j] && issubstr(codes[j], str_tmp)) {
                    prefix = true;
                    break;
                }
            }
            if(prefix) break;
        }
        bool repetition = false;
        for(int i = 0; i < n - 1; i++) {
            string str_tmp = codes[i];
			if(str_tmp == codes[i + 1]) {
				repetition = true;
				break;
			} 
        }
        if(wpl_tmp == wpl && !prefix && !repetition) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

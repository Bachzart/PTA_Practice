#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string, int> dictory;

int main() {
	string word;
	int n, m, index;
	cin >> n;
	while(n--) {
		cin >> word >> index;
		dictory[word] = index;
	}
	cin >> m;
	while(m--) {
		cin >> word;
		unordered_map<string, int>::iterator it = dictory.find(word);
		if(it == dictory.end()) cout << "Not Found" << endl;
		else cout << it->second << endl;
	}
	return 0;
}

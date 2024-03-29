#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	getchar();
	string str;
	queue<int> q;
	while(1) {
		cin >> str;
		if(str == "#") break;
		int id = 0;
		if(str != "Calling") {
			cin >> id;
			if(q.size() >= n) {
				cout << id << " rejected." << endl;
				continue;
			} else {
				q.push(id);
				cout << id << " joined. Total:" << q.size() << endl;
			}
		} else {
			if(!q.empty()) {
				cout << q.front() << " called. Total:";
				q.pop();
				cout << q.size() << endl;
			} else cout << "No one!" << endl;
		}
	}
	return 0;
}

#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
unordered_map<string, string> couples;
set<string> peo, sdog, notdog;
int n, m;

int main() {
	cin >> n;
	string hs_tmp, wi_tmp, people;
	while(n--) {
		cin >> hs_tmp >> wi_tmp;
		couples[hs_tmp] = wi_tmp;
		notdog.insert(hs_tmp), notdog.insert(wi_tmp);
	}
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> people;
		peo.insert(people);
	}
	for(unordered_map<string, string>::iterator it = couples.begin(); it != couples.end(); it++) {
		hs_tmp = it->first, wi_tmp = it->second;
		if(peo.find(hs_tmp) != peo.end() && peo.find(wi_tmp) == peo.end()) sdog.insert(hs_tmp);
		else if(peo.find(hs_tmp) == peo.end() && peo.find(wi_tmp) != peo.end()) sdog.insert(wi_tmp);
	}
	for(set<string>::iterator it = peo.begin(); it != peo.end(); it++) {
		if(notdog.find(*it) != notdog.end()) continue;
		else sdog.insert(*it);
	}
	cout << sdog.size() << endl;
	set<string>::iterator it = sdog.begin();
	for(int i = 0; i < sdog.size(); i++) {
		cout << *it;
		if(i < sdog.size() - 1) cout << ' ';
		it++;
	}
	return 0;
}

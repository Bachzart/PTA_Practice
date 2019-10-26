#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
template<class T>
struct DisjointSet{
	int *parent;
	T *data;
	set<T> *mates;
	map<T, int> m;
	int capacity;
	int size;
	DisjointSet(int max = 10) {
		capacity = max;
		size = 0;
		parent = new int[max + 1];
		data = new T[max + 1];
		mates = new set<T>[max + 1];
	}
	~DisjointSet() {
		delete [] parent;
		delete [] data;
	}
	bool insert(T x) {
		if(size == capacity) return false;
		size++;
		data[size] = x;
		parent[size] = -1;
		mates[size].insert(x);
		m[x] = size;
		return true;
	}
	int find(T x) {
		typename map<T, int>::iterator it;
		it = m.find(x);
		if(it == m.end()) return -1;
		int rt, i;
		i = rt = it->second;
		while(parent[rt] > 0) rt = parent[rt];
		int tmp;
		for(; i != rt; i = tmp) {
			tmp = parent[i];
			parent[i] = rt;
		}
		return rt;
	}
	void unionSet(T x, T y) {
		int rx, ry;
		rx = find(x);
		ry = find(y);
		if(rx == -1 || ry == -1) return;
		if(rx == ry) return;
		if(parent[rx] < parent[ry]) {
			parent[rx] += parent[ry];
			parent[ry] = rx;
			mates[rx].insert(mates[ry].begin(), mates[ry].end());
			mates[ry].clear();
		} else {
			parent[ry] += parent[rx];
			parent[rx] = ry;
			mates[ry].insert(mates[rx].begin(), mates[rx].end());
			mates[rx].clear();
		}
	}
};
int main() {
	int m, n;
	cin >> n;
	DisjointSet<string> s(n);
	string name;
	for(int i = 0; i < n; i++){
		cin >> name;
		s.insert(name);
	}
	cin >> m;
	string name2;
	for(int i = 0; i < m; i++) {
		cin >> name >> name2;
		s.unionSet(name, name2);
	}
	int maxid = 0, maxsize = 0, numofschools = 0;
	for(int i = 1; i <= n; i++) {
		if(s.mates[i].size() > 0) numofschools++;
		if(s.parent[i] < maxsize) {
			maxsize = s.parent[i];
			maxid = i;
		}
	}
	cout << numofschools << ' ' << s.mates[maxid].size();
	return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 10;
struct human{
	char name[10];
	int height;
} people[maxn], queue[maxn];
int n, k, m;
bool cmp(human a, human b){
	if(a.height != b.height) return a.height > b.height;
	else return strcmp(a.name, b.name) < 0;
}
int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> people[i].name >> people[i].height;
	}
	sort(people, people + n, cmp);
	int t = 0, row = k;
	while(row) {
		if(row == k) m = n / k + n % k;
		else m = n / k;
		queue[m / 2] = people[t];
		// left
		int j = m / 2 - 1;
		for(int i = t + 1; i < t + m; i = i + 2) {
			queue[j--] = people[i];
		}
		// right
		j = m / 2 + 1;
		for(int i = t + 2; i < t + m; i = i + 2) {
			queue[j++] = people[i];
		} 
		// print
		cout << queue[0].name;
		for(int i = 1; i < m; i++) {
			cout << ' ' << queue[i].name;
		}
		cout << endl;
		t = t + m;
		row--;
	}
	return 0;
}
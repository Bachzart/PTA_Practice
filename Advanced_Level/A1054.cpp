#include <iostream>
#include <map>
using namespace std;
map<string, int> color;

int main(int argc, char const *argv[]) {
	int n, m, temp;
	cin >> n >> m;
	temp = n * m;
	getchar();
	while(temp--) {
		string s;
		cin >> s;
		color[s]++;
	}
	temp = n * m;
	map<string, int>::iterator max = color.begin();
	map<string, int>::iterator it = color.begin();
	for(; it != color.end(); it++) {
		if(it->second > max->second) {
			max = it;
		}
	}
	cout << max->first; 
	return 0;
}

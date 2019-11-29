#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 2000000 + 5;
map<string, int> phonenum2num;
map<int, string> num2phonenum;
int times[maxn] = { 0 }, n, index = 1;
int main() {
	cin >> n;
	string num;
	for (int i = 0; i < 2 * n; i++) {
		cin >> num;
		int tmp = phonenum2num.find(num)->second;
		if (!tmp) {
			phonenum2num[num] = index;
			num2phonenum[index] = num;
			times[index] = 1;
			index++;
		} else {
			times[tmp]++;
		}
	}
	int max = times[1], maxindex = 1, count = 1;
	string madman = num2phonenum.find(1)->second;
	for (int i = 2; i < index; i++) {
		if (times[i] > max) {
			max = times[i];
			maxindex = i;
			madman = num2phonenum.find(i)->second;
		} else if (times[i] == max) {
			if (num2phonenum.find(i)->second < num2phonenum.find(maxindex)->second) {
				maxindex = i;
				madman = num2phonenum.find(i)->second;
			}
			count++;
		}
	}
	if (count == 1) cout << madman << ' ' << max;
	else cout << madman << ' ' << max << ' ' << count;
	return 0;
}


/*
samples:
in:
4
13005711862 13588625832
13505711862 13088625832
13588625832 18087925832
15005713862 13588625832
out:
13588625832 3

*/
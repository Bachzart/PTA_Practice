#include <cstdio>
const int MAXN = 200000 + 10;
int seq[MAXN];
int main(int argc, char const *argv[]) {
	int n1, n2, temp, count = 0;
	scanf("%d", &n1);
	for(int i = 1; i <= n1; i++) {
		scanf("%d", &seq[i]);
	}
	seq[n1 + 1] = 0x7fffffff;
	scanf("%d", &n2);
	int median = (n1 + n2 + 1) / 2, i = 1;
	for(int j = 1; j <= n2; j++) {
		scanf("%d", &temp);
		while(seq[i] < temp) {
			count++;
			if(count == median) printf("%d", seq[i]);
			i++;
		}
		count++;
		if(count == median) printf("%d", temp);
	}
	while(i <= n1) {
		count++;
		if(count == median) printf("%d", seq[i]);
		i++;
	}
	return 0;
}

/* Memory limit has been changed to 64 MB. So we can use sort function to slove this problem. */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> arr;
	int n, tmp;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	int pos = arr.size() % 2 == 1 ? arr.size() / 2 : arr.size() / 2 - 1;
	cout << arr[pos]; 
	return 0;
}
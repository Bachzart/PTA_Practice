#include <stdio.h>

int Compare(int *original, int *now, int number);

int main(int argc, char const *argv[]) {
    char Num[22];
    int original[22], now[22], original_occurrence[10] = {0}, now_occurrence[10] = {0};
    scanf("%s", Num);
    char *p = Num;
    int i = 0, j, k, temp = 0, flag = 0;
    //conver the string to an array(int)
    while(*p != '\0') {
    	original[i++] = *p++ - '0';
	}
	//count the occurrence of the original number
	for(j = 0; j < i; j++) {
		original_occurrence[original[j]]++;
	}
	//imitate multiplication
	for(k = 0, j = i - 1; j >= 0; j--, k++) {
		now[k] = (original[j] * 2 + temp) % 10;
		temp = original[j] * 2 / 10;
	}
	if(temp) {
		now[k] = temp;
	} else {
		k -= 1;
	}
	//count the new number 
	for(j = 0; j <= k; j++) {
		now_occurrence[now[j]]++;
	}
	flag = Compare(original_occurrence, now_occurrence, 10);
	//print
	if(flag) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	for(j = k; j > 0; j--) {
		printf("%d", now[j]); 
	}
	printf("%d\n", now[j]);
    return 0;
}

int Compare(int *original, int *now, int number) {
	int i, j, ret = 1;
	for(i = 0; i < number; i++) {
		if(original[i] != now[i]) {
			ret = 0;
			break;
		}
	}
	return ret;
}

/* C++ */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string num;
	cin >> num;
	vector<int> n, dn;
	for(int i = num.size() - 1; i >= 0; i--) {
		n.push_back(num[i] - '0');
	}
	int carry = 0;
	for(int i = 0; i < n.size(); i++) {
		dn.push_back((2 * n[i] + carry) % 10);
		carry = 2 * n[i] / 10;
	}
	if(carry > 0) dn.push_back(carry);
	string ans;
	for(int i = dn.size() - 1; i >= 0; i--) {
		ans.push_back(dn[i] + '0');
	}
	sort(n.begin(), n.end());
	sort(dn.begin(), dn.end());
	if(n == dn) cout << "Yes" << endl;
	else cout << "No" << endl;
	cout << ans;
	return 0;
}
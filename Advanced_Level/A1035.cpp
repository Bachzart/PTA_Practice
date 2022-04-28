#include <cstdio>
const int MAXN = 1000 + 5;
struct info {
	char name[12], password[12];
	int flag;
} Info[MAXN];

int main(int argc, char const *argv[]) {
	int N, count = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%s %s", Info[i].name, Info[i].password);
		char *p = Info[i].password;
		while(*p != '\0') {
			if(*p == '1') {
				*p = '@';
				Info[i].flag = 5;
			} else if(*p == '0') {
				*p = '%';
				Info[i].flag = 5;
			} else if(*p == 'l') {
				*p = 'L';
				Info[i].flag = 5;
			} else if(*p == 'O') {
				*p = 'o';
				Info[i].flag = 5;
			}
			p++;
		}
		if(Info[i].flag != 5) {
			count++;
		}
	}
	if(count == N) {
		if(count == 1) printf("There is %d account and no account is modified\n", count);
		else printf("There are %d accounts and no account is modified", count);
	} else {
		printf("%d\n", N - count);
		for(int i = 0; i < N; i++) {
			if(Info[i].flag == 5) {
				printf("%s %s\n", Info[i].name, Info[i].password);
			}
		}
	}
	return 0;
}

/* C++ */
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, cnt = 0;
	cin >> m;
	string account, password;
	vector<vector<string>> ans;
	for(int i = 0; i < m; i++) {
		cin >> account >> password;
		bool flag = false;
		for(int j = 0; j < password.length(); j++) {
			switch(password[j]) {
				case '1': password[j] = '@'; flag = true; break;
				case '0': password[j] = '%'; flag = true; break;
				case 'l': password[j] = 'L'; flag = true; break;
				case 'O': password[j] = 'o'; flag = true; break;
				default: break;
			}
		}
		if(flag) {
			ans.push_back({account, password});
			cnt++;
		}
	}
	if(!cnt) {
		if(m <= 1) cout << "There is " << m << " account";
		else cout << "There are " << m << " accounts";
		cout << " and no account is modified";
	} else {
		cout << cnt << endl;
		for(int i = 0; i < ans.size(); i++) {
			cout << ans[i][0] << ' ' << ans[i][1] << endl;
		}
	}
	return 0;
}
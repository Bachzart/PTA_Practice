/*
 * version 4: two hashmap
 *
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int matrix[15][1005] = {0}, N, M;
bool player[15] = {false};
const int MAXN = 100000 + 5;
vector<int> nums;
bool num[MAXN] = {false}, diff[MAXN] = {false};

int main(int argc, char const *argv[]) {
	scanf("%d %d", &N, &M);
	nums.push_back(N), nums.push_back(M);
	num[N] = 1, num[M] = 1;
	diff[abs(N - M)] = true;
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			scanf("%d", &matrix[i][j]);
		}
	} 
	for(int j = 1; j <= M; j++) {
		for(int i = 1; i <= N; i++) {
			int tmp = matrix[i][j];
			if(player[i] == true) continue;
			if(num[tmp] == true) {
				printf("Round #%d: %d is out.\n", j, i);
				player[i] = true;
			} else {
				bool flag = false;
				if(diff[tmp] == true)
					flag = true;
				if(!flag) {
					printf("Round #%d: %d is out.\n", j, i);
					player[i] = true;
				} else {
					for(auto &i: nums)
						diff[abs(i - tmp)] = true;
					num[tmp] = true;
					nums.push_back(tmp);
				}
			}
		}
	}
	vector<int> winner;
	for(int i = 1; i <= N; i++) {
		if(player[i] == false) winner.push_back(i);
	}
	if(winner.size() == 0)
		printf("No winner.\n");
	else {
		printf("Winner(s):");
		for(int &i: winner)
			printf(" %d", i);
	}
	return 0;
}



/*
// version 3: use `int` array
// AC

#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int matrix[15][1005] = {0}, N, M;
bool player[15] = {false};
set<int> num;
const int MAXN = 100000 + 5;
int diff[MAXN] = {0};

int main(int argc, char const *argv[]) {
	scanf("%d %d", &N, &M);
	num.insert(N);
	num.insert(M);
	diff[abs(N - M)] = true;
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			scanf("%d", &matrix[i][j]);
		}
	} 
	for(int j = 1; j <= M; j++) {
		for(int i = 1; i <= N; i++) {
			int tmp = matrix[i][j];
			if(player[i] == true) continue;
			if(num.find(tmp) != num.end()) {
				printf("Round #%d: %d is out.\n", j, i);
				player[i] = true;
			} else {
				bool flag = false;
				if(diff[tmp] == true)
					flag = true;
				if(!flag) {
					printf("Round #%d: %d is out.\n", j, i);
					player[i] = true;
				} else {
					for(auto &i: num) 
						diff[abs(i - tmp)] = true;;
					num.insert(tmp);
				}
			}
		}
	}
	vector<int> winner;
	for(int i = 1; i <= N; i++) {
		if(player[i] == false) winner.push_back(i);
	}
	if(winner.size() == 0)
		printf("No winner.\n");
	else {
		printf("Winner(s):");
		for(int &i: winner)
			printf(" %d", i);
	}
	return 0;
}

*/

/* 
// version 2: use set and unordered_set
// time limit exceeded

#include <cstdio>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
int matrix[15][1005] = {0}, N, M;
bool player[15] = {false};
set<int> num;
unordered_set<int> diff;

int main(int argc, char const *argv[]) {
	scanf("%d %d", &N, &M);
	num.insert(N);
	num.insert(M);
	diff.insert(abs(N - M));
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			scanf("%d", &matrix[i][j]);
		}
	} 
	for(int j = 1; j <= M; j++) {
		for(int i = 1; i <= N; i++) {
			int tmp = matrix[i][j];
			if(player[i] == true) continue;
			if(num.find(tmp) != num.end()) {
				printf("Round #%d: %d is out.\n", j, i);
				player[i] = true;
			} else {
				bool flag = false;
				if(diff.find(tmp) != diff.end())
					flag = true;
				if(!flag) {
					printf("Round #%d: %d is out.\n", j, i);
					player[i] = true;
				} else {
					for(auto &i: num) 
						diff.insert(abs(i - tmp));
					num.insert(tmp);
				}
			}
		}
	}
	vector<int> winner;
	for(int i = 1; i <= N; i++) {
		if(player[i] == false) winner.push_back(i);
	}
	if(winner.size() == 0)
		printf("No winner.\n");
	else {
		printf("Winner(s):");
		for(int &i: winner)
			printf(" %d", i);
	}
	return 0;
}
*/

/*
// version 1: use unordered_map and set, but cause
// time limit exceeded. And if use unordered_map and 
// unordered_set will cause memory limit exceeded.

#include <cstdio>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;
int matrix[15][1005] = {0}, N, M;
unordered_map<int, set<int>> number2diff;
bool player[15] = {false};

int main(int argc, char const *argv[]) {
	int init1, init2;
	scanf("%d %d", &init1, &init2);
	set<int> st1, st2;
	if(init1 > init2)
		st1.insert(init1 - init2);
	else
		st2.insert(init2 - init1);
	number2diff.insert({init1, st1});
	number2diff.insert({init2, st2});
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			scanf("%d", &matrix[i][j]);
	for(int j = 1; j <= M; j++) {
		for(int i = 1; i <= N; i++) {
			int tmp = matrix[i][j];
			if(player[i] == true) continue;
			if(number2diff.find(tmp) != number2diff.end()) {
				printf("Round #%d: %d is out.\n", j, i);
				player[i] = true;
			} else {
				bool flag = false;
				for(auto &p: number2diff) {
					auto it = p.second.lower_bound(tmp);
					if(it != p.second.end() && *it == tmp) {
						flag = true;
						break;
					}
				}
				if(!flag) {
					printf("Round #%d: %d is out.\n", j, i);
					player[i] = true;
				} else {
					set<int> st;
					for(auto &p: number2diff) {
						if(p.first < tmp) 
							st.insert(tmp - p.first);
					}
					number2diff.insert({tmp, st});
					for(auto &p: number2diff) {
						if(p.first > tmp) {
							p.second.insert(p.first - tmp);
						}
					}
				}
			}
		}
	}
	vector<int> winner;
	for(int i = 1; i <= N; i++) {
		if(player[i] == false) winner.push_back(i);
	}
	if(winner.size() == 0)
		printf("No winner.\n");
	else {
		printf("Winner(s):");
		for(int &i: winner)
			printf(" %d", i);
	}
	return 0;
}
*/
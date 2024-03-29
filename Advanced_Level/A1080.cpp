#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 40000 + 5;

struct student{
	int ge, gi, sum;
	int r, id;
	int cho[6];
} stu[MAXN];

struct school{
	int quota;
	int stuNum;
	int id[MAXN];
	int lastAdmit;
} sch[110];

bool cmpStu(student a, student b);
bool cmpID(int a, int b);
int main(int argc, char const *argv[]) {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < M; i++) {
		scanf("%d", &sch[i].quota);
		sch[i].stuNum = 0;
		sch[i].lastAdmit = -1;
	}
	for(int i = 0; i < N; i++) {
		stu[i].id = i;
		scanf("%d %d", &stu[i].ge, &stu[i].gi);
		stu[i].sum = stu[i].ge + stu[i].gi;
		for(int j = 0; j < K; j++) {
			scanf("%d", &stu[i].cho[j]);
		}
	}
	sort(stu, stu + N, cmpStu);
	for(int i = 0; i < N; i++) {
		if(i > 0 && stu[i].sum == stu[i - 1].sum 
		&& stu[i].ge == stu[i - 1].ge) {
			stu[i].r = stu[i - 1].r;
		} else {
			stu[i].r = i;
		}
	}
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < K; j++) {
			int choice = stu[i].cho[j];
			int num = sch[choice].stuNum;
			int last = sch[choice].lastAdmit;
			if(num < sch[choice].quota || (last != -1 && 
			stu[i].r == stu[last].r)) {
				sch[choice].id[num] = i;
				sch[choice].lastAdmit = i;
				sch[choice].stuNum++;
				break;
			}
		}
	}
	for(int i = 0; i < M; i++) {
		if(sch[i].stuNum > 0) {
			sort(sch[i].id, sch[i].id + sch[i].stuNum, cmpID);
			for(int j = 0; j < sch[i].stuNum; j++) {
				printf("%d", stu[sch[i].id[j]].id);
				if(j < sch[i].stuNum - 1) {
					printf(" ");
				}
			}
		}
		putchar('\n');
	}
	return 0;
}

bool cmpStu(student a, student b) {
	if(a.sum != b.sum) return a.sum > b.sum;
	else return a.ge > b.ge;
}

bool cmpID(int a, int b) {
	return stu[a].id < stu[b].id;
}

/* C++ */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 40000 + 5;
struct student {
	int ge, gi, id, rank;
	int sum;
	int choices[6];
} stu[maxn];
int n, m, k;
int quota[105] = {0};
int lastrank[105] = {0};
bool cmp(student a, student b) {
	if(a.sum != b.sum) return a.sum > b.sum;
	else return a.ge > b.ge;
}
int main() {
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++) {
		cin >> quota[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> stu[i].ge >> stu[i].gi;
		stu[i].sum = stu[i].ge + stu[i].gi;
		stu[i].id = i;
		for(int j = 0; j < k; j++) {
			cin >> stu[i].choices[j];
		}
	}
	sort(stu, stu + n, cmp);
	stu[0].rank = 1;
	for(int i = 1; i < n; i++) {
		if(stu[i].sum == stu[i - 1].sum && stu[i].ge == stu[i - 1].ge) stu[i].rank = stu[i - 1].rank;
		else stu[i].rank = i + 1;
	}
	vector<vector<int>> ans(105);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++) {
			int school = stu[i].choices[j];
			if(quota[school] != 0) {
				ans[school].push_back(stu[i].id);
				quota[school]--;
				lastrank[school] = stu[i].rank; 
				break;
			} else {
				if(stu[i].rank == lastrank[school]) {
					ans[school].push_back(stu[i].id);
					break;
				}
			}
		}
	}
	for(int i = 0; i < m; i++) {
		int size = ans[i].size();
		if(size == 0) {
			cout << endl;
			continue;
		} else {
			sort(ans[i].begin(), ans[i].end());
			cout << ans[i][0];
			for(int j = 1; j < size; j++) {
				cout << ' ' << ans[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
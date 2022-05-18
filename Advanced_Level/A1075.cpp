#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10000 + 5;
struct user{
	int id, score[6], sum, perfect;
	bool flag;
} us[MAXN];
int N, K, M;
int full[6] = {0};
bool cmp(user a, user b);
void Init();

int main(int argc, char const *argv[]) {
	scanf("%d %d %d", &N, &K, &M);
	Init();
	for(int i = 1; i <= K; i++) {
		scanf("%d", full + i);
	}
	int uid, pid, score_ob;
	for(int i = 0; i < M; i++) {
		scanf("%d %d %d", &uid, &pid, &score_ob);
		if(score_ob != -1) {
			us[uid].flag = true;
		}
		if(score_ob == -1 && us[uid].score[pid] == -1) {
			us[uid].score[pid] = 0;
		}
		if(score_ob == full[pid] && us[uid].score[pid] < full[pid]) {
			us[uid].perfect++;
		}
		if(score_ob > us[uid].score[pid]) {
			us[uid].score[pid] = score_ob;
		}
	}
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= K; j++) {
			if(us[i].score[j] != -1) {
				us[i].sum += us[i].score[j];
			}
		}
	}
	sort(us + 1, us + N + 1, cmp);
	int r = 1;
	for(int i = 1; i <= N && us[i].flag == true; i++) {
		if(i > 1 && us[i].sum != us[i - 1].sum) {
			r = i;
		}
		printf("%d %05d %d", r, us[i].id, us[i].sum);
		for(int j = 1; j <= K; j++) {
			if(us[i].score[j] == -1) {
				printf(" -");
			} else {
				printf(" %d", us[i].score[j]);
			}
		}
		putchar('\n');
	}
	return 0;
}

bool cmp(user a, user b) {
	if(a.sum != b.sum) return a.sum > b.sum;
	else if(a.perfect != b.perfect) return a.perfect > b.perfect;
	else return a.id < b.id;
}

void Init() {
	for(int i = 1; i <= N; i++) {
		us[i].id = i;
		us[i].sum = 0;
		us[i].perfect = 0;
		us[i].flag = false;
		memset(us[i].score, -1, sizeof(us[i].score));
	}
}

/* new version */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 5;
struct student {
	int id, grade[6], cnt;
	bool flag;
} stu[maxn];
int perfect[6], n, k, m;
bool cmp(student a, student b) {
	if(a.grade[0] != b.grade[0]) return a.grade[0] > b.grade[0];
	else if(a.cnt != b.cnt) return a.cnt > b.cnt;
	else return a.id < b.id; 
}
void Init() {
	for(int i = 0; i < maxn; i++) {
		stu[i].id = i;
		stu[i].cnt = 0;
		stu[i].flag = false;
		memset(stu[i].grade, -1, sizeof(stu[i].grade));
		stu[i].grade[0] = 0;
	}
}
int main() {
	scanf("%d %d %d", &n, &k, &m);
	Init();
	for(int i = 1; i <= k; i++) {
		scanf("%d", &perfect[i]);
	}
	int id, grade, pronum;
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", &id, &pronum, &grade);
		if(grade != -1) stu[id].flag = true;
		if(grade == -1 && stu[id].grade[pronum] == -1) stu[id].grade[pronum] = 0;
		if(grade == perfect[pronum] && stu[id].grade[pronum] < perfect[pronum]) stu[id].cnt++;
		if(grade > stu[id].grade[pronum]) stu[id].grade[pronum] = grade;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			if(stu[i].grade[j] > 0) stu[i].grade[0] += stu[i].grade[j];
		}
	}
	sort(stu + 1, stu + n + 1, cmp);
	int rank = 1;
	for(int i = 1; i <= n && stu[i].flag; i++) {
		if(i > 1 && stu[i].grade[0] != stu[i - 1].grade[0]) rank = i;
		printf("%d %05d %d", rank, stu[i].id, stu[i].grade[0]);
		for(int j = 1; j <= k; j++) {
			if(stu[i].grade[j] == -1) printf(" -");
			else printf(" %d", stu[i].grade[j]);
		}
		putchar('\n');
	}
	return 0;
} 
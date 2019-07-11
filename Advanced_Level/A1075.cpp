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

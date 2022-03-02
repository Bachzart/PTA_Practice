#include <cstdio>
#include <cstring>
const int maxn = 1000 + 5;
const int maxm = 100 + 5;
struct question {
	char answer[6];
	int score, c1, c2;
} que[maxm];
char str[1005];
int n, m, times[maxm] = {0};

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d %d %d", &que[i].score, &que[i].c1, &que[i].c2);
		char c;
		getchar();
		int j;
		for(j = 0; j < que[i].c2; j++) {
			scanf("%c%*c", &que[i].answer[j]);
		}
		que[i].answer[j] = '\0';
	}
	for(int i = 1; i <= n; i++) {
		fgets(str, 1005, stdin);
		char ans[6];
		int score = 0, ti, qnum = 1;
		for(int j = 0; str[j] != '\0'; j++) {
			if(str[j] == '(') {
				int k, tmp = 0;
				for(k = j + 1; str[k] != ')'; k++) {
					if('0' <= str[k] && str[k] <= '9') {
						ti = str[k] - '0';
					}
					if('a' <= str[k] && str[k] <= 'z') {
						ans[tmp++] = str[k];
					}
				}
				ans[tmp] = '\0';
				j = k + 1;
				if(ti != que[qnum].c2 || strcmp(que[qnum].answer, ans) != 0) times[qnum]++;
				else score += que[qnum].score;
				qnum++;
			}
		}
		printf("%d\n", score);
	}
	int max = times[0];
	for(int i = 1; i <= m; i++) {
		if(max < times[i]) max = times[i];
	}
	if(max) {
		printf("%d", max);
		for(int i = 1; i <= m; i++) {
			if(max == times[i]) printf(" %d", i);
		}
	} else printf("Too simple");
	return 0;
}
#include <cstdio>
#include <set>
using namespace std;
const int maxm = 100 + 5;
set<char> answer[maxm];
int que[maxm] = {0}, wrong_opt[maxm][6] = {0};
double scores[maxm] = {0.0};
char stu[10005];

int main() {
	int n, m, tmp;
	char ctmp;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		scanf("%lf %d %d%*c", &scores[i], &que[i], &tmp);
		for(int j = 0; j < tmp; j++) {
			scanf("%c%*c", &ctmp);
			answer[i].insert(ctmp);
		}
	}
	for(int i = 1; i <= n; i++) {
		int qnum = 1;
		double sum = 0.0;
		fgets(stu, 10005, stdin);
		for(int j = 0; stu[j] != '\0'; j++) {
			if(stu[j] == '(') {
				bool isappear[6] = {false}, flag = true;
				tmp = stu[++j] - '0';
				if(tmp > answer[qnum].size()) flag = false;
				for(j++; stu[j] != ')'; j++) {
					if(stu[j] == ' ') continue;
					else {
						ctmp = stu[j];
						if(answer[qnum].find(ctmp) == answer[qnum].end()) {
							flag = false;
							wrong_opt[qnum][ctmp - 'a']++;
						}
						isappear[ctmp - 'a'] = true;
					}
				}
				set<char>::iterator it = answer[qnum].begin();
				for(; it != answer[qnum].end(); it++) {
					if(!isappear[*it - 'a']) wrong_opt[qnum][*it - 'a']++;
				}
				if(flag && tmp == answer[qnum].size()) sum += scores[qnum];
				else if(flag && tmp < answer[qnum].size()) sum += (scores[qnum] / 2.0);
				qnum++;
			}
		}
		printf("%.1lf\n", sum);
	}
	int max = wrong_opt[1][0];
	for(int i = 1; i <= m; i++) {
		for(int j = 0; j < 5; j++) {
			max = max > wrong_opt[i][j] ? max : wrong_opt[i][j];
		}
	}
	if(max == 0) {
		printf("Too simple\n");
	} else {
		for(int i = 1; i <= m; i++) {
			for(int j = 0; j < 5; j++) {
				if(max == wrong_opt[i][j]) {
					printf("%d %d-%c\n", max, i, j + 'a');
				}
			}
		}
	}
	return 0;
}

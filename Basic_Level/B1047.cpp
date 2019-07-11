#include <cstdio>

int main(int argc, char const *argv[]) {
	int N, team, score[1010] = {0}, eachScore, maxteam = 0;
	scanf("%d", &N);
	while(N--) {
		scanf("%d-%*d %d", &team, &eachScore);
		score[team] += eachScore;
		if(team > maxteam) {
			maxteam = team;
		}
	}
	int maxscore = -1, index = 0;
	for(int i = 1; i <= maxteam; i++) {
		if(score[i] > maxscore) {
			maxscore = score[i];
			index = i;
		}
	}
	printf("%d %d", index, maxscore);
	return 0;
}

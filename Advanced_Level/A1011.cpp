#include <cstdio>

char change(int index);

int main(int argc, char const *argv[]) {
	double Bet[3][3], Profit = 0.0;
	for(int i = 0; i < 3; i++) {
		scanf("%lf %lf %lf", &Bet[i][0], &Bet[i][1], &Bet[i][2]);
	}
	int max_index[3];
	double max[3] = {0.0};
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(max[i] < Bet[i][j]) {
				max[i] = Bet[i][j];
				max_index[i] = j;
			}
		}
	}
	
	Profit = (max[0] * max[1] * max[2] * 0.65 - 1.0) * 2.0;
	printf("%c %c %c %.2lf\n", change(max_index[0]), change(max_index[1]), change(max_index[2]), Profit);
	return 0;
}

char change(int index) {
	char ret;
	switch(index) {
		case 0:
			ret = 'W';
			break;
		case 1:
			ret = 'T';
			break;
		case 2:
			ret = 'L';
			break;
	}
	return ret;
}

/* simplified */
#include <cstdio>
int main() {
	double turns[3][3], max, maxproduct = 1.0;
	char ans[3];
	for(int i = 0; i < 3; i++) {
		max = -1000;
		for(int j = 0; j < 3; j++) {
			scanf("%lf", &turns[i][j]);
			if(max < turns[i][j]) {
				max = turns[i][j];
				if(j == 1) ans[i] = 'T';
				else if(j == 2) ans[i] = 'L';
				else ans[i] = 'W';
			}
		}
		maxproduct *= max;
	}
	double maxprofit = 0.0;
	maxprofit = (maxproduct * 0.65 - 1) * 2;
	for(int i = 0; i < 3; i++) {
		printf("%c ", ans[i]);
	}
	printf("%.2lf", maxprofit);
	return 0;
} 
#include <cstdio>

char Cards[55][5] = {
	"",
	"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
	"H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
	"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
	"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
	"J1", "J2",
};

int main(int argc, char const *argv[]) {
	int i, K, Shuffling_Order[55], Order[55], flag = 1, Result[55];
	scanf("%d", &K);
	for(i = 1; i <= 54; i++) {
		scanf("%d", Shuffling_Order + i);
		Order[i] = i;
	}
	while(K--) {
		if(flag) {
			for(i = 1; i <= 54; i++) {
				Result[Shuffling_Order[i]] = Order[i];
			}
			flag = 0;
		} else {
			for(i = 1; i <= 54; i++) {
				Order[Shuffling_Order[i]] = Result[i];
			}
			flag = 1;
		}
	}
	if(flag) {
		for(i = 1; i <= 54; i++) {
			if(i == 54) {
				puts(Cards[Order[i]]);
			} else {
				printf("%s ", Cards[Order[i]]);
			}
		}
	} else {
		for(i = 1; i <= 54; i++) {
			if(i == 54) {
				puts(Cards[Result[i]]);
			} else {
				printf("%s ", Cards[Result[i]]);
			}
		}
	}
	return 0;
}

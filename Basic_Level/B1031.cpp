#include <stdio.h>

char Comparison_Table[12] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
int Weight_Table[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

int main(int argc, char const *argv[]) {
	char ID_Number[19];
	int N, flag = 1;
	scanf("%d", &N);
	while(N--) {
		scanf("%s", ID_Number);
		char *p = ID_Number;
		int i, Digit_Sum = 0, Check_value;
		for(i=0; i<17; i++, p++) {
			if(*p == 'X') Digit_Sum += (10 * Weight_Table[i]);
			else Digit_Sum += ((*p - '0') * Weight_Table[i]);
		}
		Check_value = Digit_Sum % 11;
		char Check_code = Comparison_Table[Check_value];
		if(Check_code == ID_Number[17]) continue;
		else {
			printf("%s\n", ID_Number);
			flag = 0;
		}
	}
	if(flag) printf("All passed\n");
	return 0;
}

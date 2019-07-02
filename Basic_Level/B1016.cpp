#include <stdio.h>
#define MaxSize 15

int Get_P_value(char *num, char D);

int main(int argc, char const *argv[]) {
	char A_num[MaxSize], B_num[MaxSize], DA, DB;
	int PA, PB;
	scanf("%s %c %s %c", A_num, &DA, B_num, &DB);
	PA = Get_P_value(A_num, DA);
	PB = Get_P_value(B_num, DB);
	printf("%d\n", PA + PB);
	return 0;
}

int Get_P_value(char *num, char D) {
	/*calculate the P value need 2 conditions:
	1. the value of D
	2. the occurrences of D in number string
	P=0 -> D don't appear in num
	*/
	int i, times = 0, P = 0, temp = D - '0';
	char *p;
	p = num;
	/*use char pointer to count the number of occurrences of D in number string*/
	while(*p) {
		if(*p == D) {
			P += temp;
			temp *= 10;
		}
		p++;
	}	
	return P;
}

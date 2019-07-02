#include <cstdio>

struct citizen{
	int year, month, day;
	char name[7];
} youngest, oldest, left, right, temp;

void Init();
bool Less(citizen a, citizen b);
bool More(citizen a, citizen b);

int main(int argc, char const *argv[]) {
	Init();
	int N, valid = 0;
	scanf("%d", &N);
	while(N--) {
		scanf("%s %d/%d/%d", temp.name, &temp.year, &temp.month, &temp.day);
		if(Less(temp, right) && More(temp, left)) {
			valid++;
			if(More(temp, youngest)) {
				youngest = temp;
			}
			if(Less(temp, oldest)) {
				oldest = temp;
			}
		}
	}
	if(valid) {
		printf("%d %s %s\n", valid, oldest.name, youngest.name);
	} else {
		printf("0\n");
	}
	return 0;
}

void Init() {
	left.year = youngest.year = 1814;
	right.year = oldest.year = 2014;
	youngest.month = oldest.month = left.month = right.month = 9;
	youngest.day = oldest.day = left.day = right.day = 6;
} 

bool Less(citizen a, citizen b) {
	if(a.year != b.year) return a.year <= b.year;
	else if(a.month != b.month) return a.month <= b.month;
	else return a.day <= b.day;
}

bool More(citizen a, citizen b) {
	if(a.year != b.year) return a.year >= b.year;
	else if(a.month != b.month) return a.month >= b.month;
	else return a.day >= b.day;
}

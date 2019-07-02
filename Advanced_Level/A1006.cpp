#include <cstdio>

struct person{
	char ID_number[20];
	int start_hh, start_mm, start_ss, end_hh, end_mm, end_ss;
} first, last, temp;

void Init();
bool Earliest(person a, person b);
bool Latest(person a, person b);

int main(int argc, char const *argv[]) {
	Init();
	int M;
	scanf("%d", &M);
	while(M--) {
		scanf("%s %d:%d:%d %d:%d:%d", temp.ID_number, &temp.start_hh, \
		&temp.start_mm, &temp.start_ss, &temp.end_hh, &temp.end_mm, &temp.end_ss);
		if(Earliest(temp, first)) {
			first = temp;
		}
		if(Latest(temp, last)) {
			last = temp;
		}
	}
	printf("%s %s\n", first.ID_number, last.ID_number);
	return 0;
}

void Init() {
	first.start_hh = 23;
	first.start_mm = first.start_ss = 59;
	last.end_hh = last.end_mm = last.end_ss = 0;
}

bool Earliest(person a, person b) {
	if(a.start_hh != b.start_hh) return a.start_hh <= b.start_hh;
	else if(a.start_mm != b.start_mm) return a.start_mm <= b.start_mm;
	else return a.start_ss <= a.start_ss;
}

bool Latest(person a, person b) {
	if(a.end_hh != b.end_hh) return a.end_hh >= b.end_hh;
	else if(a.end_mm != b.end_mm) return a.end_mm >= b.end_mm;
	else return a.end_ss >= b.end_ss;
}

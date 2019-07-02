#include <cstdio>

struct student{
	char name[15];
	char id[15];
	char gender;
	int grade;
} Fhighest, Mlowest, temp;

void Init();
bool Highest(student a, student b);
bool Lowest(student a, student b);

int main(int argc, char const *argv[]) {
	Init();
	int N;
	bool Fflag = false, Mflag = false;
	scanf("%d", &N);
	while(N--) {
		scanf("%s %c %s %d", temp.name, &temp.gender, temp.id, &temp.grade);
		if(temp.gender == 'F') {
			if(Highest(temp, Fhighest)) {
				Fhighest = temp;
				Fflag = true;
			}
		} else if(temp.gender == 'M') {
			if(Lowest(temp, Mlowest)) {
				Mlowest = temp;
				Mflag = true;
			}
		}
	}
	if(!Fflag && !Mflag) {
		printf("Absent\nAbsent\nNA\n");
	} else if(Fflag && !Mflag) {
		printf("%s %s\nAbsent\nNA\n", Fhighest.name, Fhighest.id);
	} else if(!Fflag && Mflag) {
		printf("Absent\n%s %s\nNA\n", Mlowest.name, Mlowest.id);
	} else {
		printf("%s %s\n%s %s\n%d\n", Fhighest.name, Fhighest.id, Mlowest.name, Mlowest.id, Fhighest.grade - Mlowest.grade);
	}
	return 0;
}

void Init() {
	Fhighest.grade = -1;
	Mlowest.grade = 100;
}

bool Highest(student a, student b) {
	return a.grade >= b.grade;
}
bool Lowest(student a, student b) {
	return a.grade <= b.grade;
}

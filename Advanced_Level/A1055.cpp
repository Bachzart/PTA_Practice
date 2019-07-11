#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 5;
int Age[MAXN] = {0};
struct people{
	char name[10];
	int age, worth;
} peo[MAXN], valid[MAXN];

bool cmp(people a, people b);

int main(int argc, char const *argv[]) {
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++) {
		scanf("%s %d %d", peo[i].name, &peo[i].age, &peo[i].worth);
	}
	sort(peo, peo + N, cmp);
	int validNum = 0;
	for(int i = 0; i < N; i++) {
		if(Age[peo[i].age] < 100) {
			Age[peo[i].age]++;
			valid[validNum++] = peo[i];
		}
	}
	int M, Amin, Amax;
	for(int i = 1; i <= K; i++) {
		bool flag = false;
		scanf("%d %d %d", &M, &Amin, &Amax);
		printf("Case #%d:\n", i);
		for(int j = 0; j < validNum && M; j++) {
			if(Amin <= valid[j].age && valid[j].age <= Amax) {
				printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].worth);
				M--;
				flag = true; 
			}
		}
		if(!flag) {
			printf("None\n");
		}
	}
	return 0;
}

bool cmp(people a, people b) {
	if(a.worth != b.worth) return a.worth > b.worth;
	else if(a.age != b.age) return a.age < b.age;
	else return strcmp(a.name, b.name) < 0;
}

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

/* C++ */
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 5;
struct people {
	string name;
	int age, worth;
} peo[maxn], output[maxn]; 
int Age[maxn] = {0};
bool cmp(people a, people b) {
	if(a.worth != b.worth) return a.worth > b.worth;
	else if(a.age != b.age) return a.age < b.age;
	else return a.name < b.name;
}
int main() {
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> peo[i].name >> peo[i].age >> peo[i].worth;
	}
	sort(peo, peo + n, cmp);
	int index = 0;
	for(int i = 0; i < n; i++) {
		if(Age[peo[i].age] < 100) {
			Age[peo[i].age]++;
			output[index++] = peo[i];
		}
	}
	int M, amin, amax;
	for(int i = 1; i <= k; i++) {
		cout << "Case #" << i << ":" << endl;
		cin >> M >> amin >> amax;
		int cnt = M;
		for(int i = 0; i < index; i++) {
			if(amin <= output[i].age && output[i].age <= amax) {
				cout << output[i].name << ' ' << output[i].age << ' ' << output[i].worth << endl;
				if(--cnt == 0) break;
			}
		}
		if(cnt == M) cout << "None" << endl;
	}
	return 0;
}
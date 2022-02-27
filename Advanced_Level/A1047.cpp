/* way 1: use number */
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 40010;
const int maxc = 2510;
char name[maxn][5];
vector<int> course[maxc];

bool cmp(int a, int b) {
	return strcmp(name[a], name[b]) < 0;
}

int main(int argc, char const *argv[]) {
	int n, k, c, courseID;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%s %d", name[i], &c);
		for(int j = 0; j < c; j++) {
			scanf("%d", &courseID);
			course[courseID].push_back(i);
		}
	}
	for(int i = 1; i <= k; i++) {
		printf("%d %d\n", i, course[i].size());
		sort(course[i].begin(), course[i].end(), cmp);
		for(int j = 0; j < course[i].size(); j++) {
			printf("%s\n", name[course[i][j]]);
		}
	}
	return 0;
}

/* way 2: use string */
/*

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int K = 2500 + 5;
vector<string> course[K];

int main() {
	int n, k, course_num;
	scanf("%d %d", &n, &k);
	char name[5];
	for(int i = 0; i < n; i++) {
		scanf("%s %d", name, &course_num);
		for(int j = 0; j < course_num; j++) {
			int course_id;
			scanf("%d", &course_id);
			course[course_id].push_back(name);
		}
	}
	for(int i = 1; i <= k; i++) {
		sort(course[i].begin(), course[i].end());
		printf("%d %d\n", i, course[i].size());
		for(int j = 0; j < course[i].size(); j++) {
			cout << course[i][j] << '\n';
		}
	}
	return 0;
}
*/

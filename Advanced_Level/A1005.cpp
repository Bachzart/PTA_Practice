/* method 1 */
#include <cstdio>
const int MAXN = 100 + 5;

char NumberTable[11][10] = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
	"ten",
};

int main(int argc, char const *argv[]) {
	char num[MAXN];
	int sum = 0;
	scanf("%s", num);
	char *p = num;
	while(*p != '\0') {
		sum += *p++ - '0';
	}
	int temp = sum, mask = 1;
	while(temp > 9) {
		temp /= 10;
		mask *= 10;
	}
	while(mask) {
		printf("%s", NumberTable[sum / mask]);
		if(mask > 9) {
			putchar(' ');
		}
		sum %= mask;
		mask /= 10;
	}
	putchar('\n');
	return 0;
}

/* method 2 */
#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, string> num2english = {{0, "zero"}, {1, "one"}, {2, "two"}, {3, "three"}, 
{4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}};

int main() {
	string str;
	cin >> str;
	int sum = 0;
	for(int i = 0; i < str.length(); i++) {
		sum += str[i] - '0';
	}
	str = to_string(sum);
	for(int i = 0; i < str.length(); i++) {
		cout << num2english[str[i] - '0'];
		if(i != str.length() - 1) cout << ' ';
	}
	return 0;
}

/* method 3 */
#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, string> num2english = {{0, "zero"}, {1, "one"}, {2, "two"}, {3, "three"}, 
{4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}};

void dfs(int n) {
	if(n / 10 == 0) {
		cout << num2english[n % 10];
		return;
	}
	dfs(n / 10);
	cout << ' ' << num2english[n % 10];
}
int main() {
	string str;
	cin >> str;
	int sum = 0;
	for(int i = 0; i < str.length(); i++) {
		sum += str[i] - '0';
	}
	dfs(sum);
	return 0;
}
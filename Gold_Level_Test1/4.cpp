#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
	char str[55];
	cin >> str;
	bool negetive = false, even = false;
	int amount2 = 0, i;
	for(i = 0; str[i] != '\0'; i++) {
		if(str[i] == '-') continue;
		if(str[i] == '2') amount2++;
	}
	if((str[i - 1] - '0') % 2 == 0) even = true;
	if(str[0] == '-') {
		negetive = true;
		i--;
	}
	double rate = 0.0;
	rate = (double)amount2 / i;
	if(negetive) rate *= 1.5;
	if(even) rate *= 2.0;
	printf("%.2lf%%", rate * 100);
	return 0;
}

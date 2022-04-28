#include <cstdio>

char Change(int number);
int Transfer(char *dst, int number, int dex);

int main(int argc, char const *argv[]) {
	int R, G, B, index = 1;
	scanf("%d %d %d", &R, &G, &B);
	char color[10] = "#00000000";
	index = Transfer(color, R, index);
	index = Transfer(color, G, index);
	index = Transfer(color, B, index);
	color[index] = '\0';
	puts(color);
	return 0;
}

int Transfer(char *dst, int number, int index) {
	int mask = 1, temp = number;
	while(temp > 12) {
		temp /= 13;
		mask *= 13;
	}
	temp = number;
	if(mask > 1) {
		while(mask) {
			dst[index++] = Change(temp / mask);
			temp %= mask;
			mask /= 13;
		}
	} else {
		index++;
		dst[index++] = Change(temp); 
	}
	return index;
}

char Change(int number) {
	char ret;
	if(0 <= number && number <= 9) {
		ret = number + '0';
	} else {
		ret = number - 10 + 'A';
	}
	return ret;
}

/* simplification */
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<int, string> marscolors;
char num2char(int num) {
	char ret = '0';
	if(0 <= num && num <= 9) ret += num;
	else ret = 'A' + num - 10;
	return ret;
}
int main() {
	marscolors[0] = "00";
	for(int i = 1; i < 169; i++) {
		int tmp = i;
		string s;
		while(tmp) {
			s += num2char(tmp % 13);
			tmp /= 13;
		}
		if(i < 13) s += "0";
		reverse(s.begin(), s.end());
		marscolors[i] = s;
	}
	int red, green, blue;
	cin >> red >> green >> blue;
	cout << "#" << marscolors[red] << marscolors[green] << marscolors[blue];
	return 0;
} 

#include <iostream>
#include <cstring>
using namespace std;
struct bign{
	int d[1005], len;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign change(char *str) {
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; i++) {
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a;
}

bign divide(bign a, int b, int &r) {
	bign c;
	c.len = a.len;
	for(int i = a.len - 1; i >= 0; i--) {
		r = r * 10 + a.d[i];
		if(r < b) c.d[i] = 0;
		else {
			c.d[i] = r / b;
			r %= b;
		}
	}
	while(c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
		c.len--;
	}
	return c;
}

int main(int argc, char const *argv[]) {
	char str[1005];
	int b, r = 0;
	cin >> str >> b;
	bign a = change(str), c;
	c = divide(a, b, r);
	for(int i = c.len - 1; i >= 0; i--) {
		cout << c.d[i];
	}
	cout << ' ' << r ;;
	return 0;
}

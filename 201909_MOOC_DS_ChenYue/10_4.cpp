#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int staff[55] = { 0 }, tmp;
	for (int i = 0; i < n; i++) {
		std::cin >> tmp;
		staff[tmp]++;
	}
	for (int i = 0; i < 52; i++) {
		if (staff[i]) std::cout << i << ':' << staff[i] << std::endl;
	}
	return 0;
}

/*
samples:
in:
8
10 2 0 5 7 2 5 2
out:
0:1
2:3
5:2
7:1
10:1

in:
10
10 2 0 0 0 5 7 2 5 2
out:
0:3
2:3
5:2
7:1
10:1

*/

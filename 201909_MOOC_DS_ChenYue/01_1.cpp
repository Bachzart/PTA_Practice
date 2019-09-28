#include <iostream>
using namespace std;
const int maxk = 100000 + 5;
int array[maxk] = {0};
int main() {
	int k;
	cin >> k;
	for(int i = 0; i < k; i++) {
		cin >> array[i];
	}
	int ThisSum = 0, MaxSum = 0;
	for(int i = 0; i < k; i++) {
		ThisSum += array[i];
		if(ThisSum > MaxSum) {
			MaxSum = ThisSum;
		} else if(ThisSum < 0) ThisSum = 0;
	}
	cout << MaxSum;
	return 0;
}

/*
some samples:
in:
6
-2 11 -4 13 -5 -2
out:
20

in:
4
-2 11 -4 13
out:
20

in:
3
-1 -2 -3
out:
0

in:
4
1 2 3 4
out:
10

in:
3
1 -1 2
out:
2

in:
3
2 -1 3
out:
4
*/

#include <iostream>
using namespace std;
const int maxk = 100000 + 5;
int array[maxk] = {0};
int main() {
	int k;
	cin >> k;
	bool flag = false;
	for(int i = 1; i <= k; i++) {
		cin >> array[i];
		if(array[i] >= 0) flag = true;
	}
	if(!flag) {
		cout << 0 << ' ' << array[1] << ' ' << array[k] << endl;
	} else {
		int left = 1, right = k, temp_left = 1;
		int ThisSum = 0, MaxSum = -1;
		for(int i = 1; i <= k; i++) {
			ThisSum += array[i];
			if(ThisSum > MaxSum) {
				MaxSum = ThisSum;
				left = temp_left;
				right = i;
			} else if(ThisSum < 0) {
				ThisSum = 0;
				temp_left = i + 1;
			}
		}
		cout << MaxSum << ' ' << array[left] << ' ' << array[right] << endl;
	}
	return 0;
}

/*
some samples:
in:
10
-10 1 2 3 4 -5 -23 3 7 -21
out:
10 1 4

in:
3
1 0 -1
out:
1 1 1

in:
3
-1 -2 -3
out:
0 -1 -3

in:
6
-2 11 -4 13 -5 -2
out:
20 11 13

in:
5
-2 11 -3 3 -1
out:
11 11 11

in:
3
-1 2 -1
out:
2 2 2

in:
3
-1 -1 0
out:
0 0 0
*/

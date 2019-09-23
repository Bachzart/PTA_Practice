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
	int left = 0, right = k - 1, temp_left = 0;
	int ThisSum = 0, MaxSum = 0;
	for(int i = 0; i < k; i++) {
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
	if(MaxSum) cout << MaxSum << ' ' << left << ' ' << right << endl;
	else cout << MaxSum << ' ' << array[left] << ' ' << array[right] << endl;
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
1 0 0

in:
3
-1 -2 -3
out:
0 -1 -3

in:
6
-2 11 -4 13 -5 -2 
out:
20 1 3

in:
5
-2 11 -3 3 -1
out:
11 1 1

in:
3
-1 2 -1
out:
2 1 1

in: 
-1 -1 0
out:
0 0 0
*/

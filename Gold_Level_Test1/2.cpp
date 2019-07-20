#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
	int A, B, sum;
	scanf("%d %d", &A, &B);
	sum = A + B;
	for(int i = 0; i < sum; i++) {
		cout << "Wang!";
	}
	return 0;
}

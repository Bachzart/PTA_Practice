#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
	int N, T;
	vector<int> v;
	cin >> N >> T;
	v.resize(N);
	for(int i = 0; i < N; i++)
		cin >> v[i];
	int A = 0;
	bool flag = false;
	while(A < N) {
		int B = A;
		while(B < N && v[B] > T) B++;
		if(B > A) {
			cout << "[" << A << ", " << B - 1 << "]" << endl;
			A = B;
			flag = true;
		} else A++;
	}
	if(!flag) cout << *max_element(v.begin(), v.end());
	return 0;
}
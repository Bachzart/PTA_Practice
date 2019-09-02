/*
method 1: use math, print it straightly according to the conditions.
*/
#include <iostream>
using namespace std;
const int maxn = 110;
int main() {
    int n, m, a[maxn];
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    m %= n;
    for(int i = n - m; i < n; i++) {
        cout << a[i] << ' ';
    }
    for(int i = 0; i < n - m; i++) {
        cout << a[i];
        if(i != n - m - 1) cout << ' ';
    }
    return 0;
}

/*
method 2: use queue
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int n, m, temp;
    cin >> n >> m;
    m %= n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        q.push(temp);
    }
    for(int i = 0; i < n - m; i++) {
        temp = q.front();
        q.pop();
        q.push(temp);
    }
    while(!q.empty()) {
        cout << q.front();
        q.pop();
        if(q.size() != 0) cout << ' ';
    }
    return 0;
}
*/

/*
method 3: use shift algorithm
#include <iostream>
using namespace std;
const int maxn = 110;
void Reverse(int a[], int start, int end) {
    for(int i = start; i <= (start + end) / 2; i++) {
        int temp = a[i];
        a[i] = a[end + start - i];
        a[end + start - i] = temp;
    }
}
int main() {
    int n, m, a[maxn];
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    m %= n;
    Reverse(a, 0, n - m - 1);
    Reverse(a, n - m, n - 1);
    Reverse(a, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << a[i];
        if(i != n - 1) cout << ' ';
    }
    return 0;
}

*/

/* method 4: use GCD to move elements

#include <cstdio>
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main(int argc, char const *argv[]) {
	int array[110], n, m, temp, pos, next;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	m = m % n;
	if(m != 0) {
		int d = gcd(n, m);
		for(int i = n - m; i < n - m + d; i++) {
			temp = array[i];
			pos = i;
			do {
				next = (pos - m + n) % n;
				if(next != i) array[pos] = array[next];
				else array[pos] = temp;
				pos = next;
			} while(pos != i);
		}
	}
	for(int i = 0; i < n; i++) {
		printf("%d", array[i]);
		if(i < n - 1) putchar(' ');
	}
	return 0;
}

*/

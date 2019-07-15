#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
	int height;
	scanf("%d", &height);
	double weight = (height - 100) * 0.9 * 2.0;
	printf("%.1lf\n", weight);
	return 0;
}

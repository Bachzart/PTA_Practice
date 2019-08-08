#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100005;
struct node {
	double data;
	vector<int> child;
} Node[maxn];
int n, num = 0;
double p, r, maxDepth = 0;
void DFS(int index, int depth) {
	if(Node[index].child.size() == 0) {
		if(depth > maxDepth) {
			maxDepth = depth;
			num = 1;
		} else if(depth == maxDepth) {
			num++;
		}
		return;
	}
	for(int i = 0; i < Node[index].child.size(); i++) {
		DFS(Node[index].child[i], depth + 1); 
	}
}

int main(int argc, char const *argv[]) {
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	int root, parent;
	for(int i = 0; i < n; i++) {
		scanf("%d", &parent);
		if(parent != -1) {
			Node[parent].child.push_back(i);
		} else {
			root = i;
		}
	}
	DFS(root, 0);
	printf("%.2lf %d\n", p * pow(1 + r, maxDepth), num);
	return 0;
}

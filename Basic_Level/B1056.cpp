/* way 1 */
#include <cstdio>

int main() {
	int n, arr, sum = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr);
		sum += arr;
	} 
	printf("%d", sum * (n - 1) * 11);
	return 0;	                 	
}

/* way 2

#include <cstdio>

int main() {
	int n, arr[15], sum = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]); 
	} 
	for(int i = 0; i < n; i++) {
		sum = sum + (arr[i] * 10 * (n - 1));
		for(int j = 0; j < n; j++) {
			if(j != i) sum += arr[i]; 
		}
	}
	printf("%d", sum);
	return 0;	                 	
}

*/

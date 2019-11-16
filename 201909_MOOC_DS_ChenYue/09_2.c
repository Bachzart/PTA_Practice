#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxn 105
int tar[maxn], arr[maxn], tmparr[maxn], n;
bool issame(int *a) {
    for(int i = 0; i < n; i++) {
        if(a[i] != tar[i]) return false;
    }
    return true;
}
void printarray(const int *array, int size) {
    for(int i = 0; i < n; i++) {
        printf("%d", array[i]);
        if(i < n - 1) putchar(' ');
    }
}
void insert_pass(int *array, int pos) {
    int tmp = array[pos], j;
    for(j = pos; j > 0 && tmp < array[j - 1]; j--) {
        array[j] = array[j - 1];
    }
    array[j] = tmp;
}
bool isinsert(int *array, int n, int *round) {
    for(int i = 1; i < n; i++) {
        insert_pass(array, i);
        if(issame(array)) {
            *round = i + 1;
            return true;
        }
    }
    return false;
}
void merge(int *array, int *tmparr, int left, int right, int rightend) {
    int leftend = right - 1, tmp = left;
    int numofelements = rightend - left + 1;
    while(left <= leftend && right <= rightend) {
        if(array[left] < array[right]) tmparr[tmp++] = array[left++];
        else tmparr[tmp++] = array[right++];
    }
    while(left <= leftend) tmparr[tmp++] = array[left++];
    while(right <= rightend) tmparr[tmp++] = array[right++];
    for(int i = 0; i < numofelements; i++, rightend--) {
        array[rightend] = tmparr[rightend];
    }
}
void merge_pass(int *array, int *tmparr, int n, int length) {
    int i, j;
    for(i = 0; i <= n - 2 * length; i += (2 * length)) {
        merge(array, tmparr, i, i + length, i + 2 * length - 1);
    }
    if(i + length < n) merge(array, tmparr, i, i + length, n - 1);
    else for(j = i; j < n; j++) tmparr[j] = array[j];
}
void merge_sort(int *array, int n) {
    int *tmparr;
    tmparr = (int*)malloc(n * sizeof(int));
    if(tmparr != NULL) {
        int length = 1;
        while(length < n) {
            merge_pass(array, tmparr, n, length);
            length *= 2;
            if(issame(tmparr)) {
                merge_pass(tmparr, array, n, length);
                printarray(array, n);
                break;
            }
            merge_pass(tmparr, array, n, length);
            length *= 2;
            if(issame(array)) {
                merge_pass(array, tmparr, n, length);
                printarray(tmparr, n);
                break;
            }
        }
        free(tmparr);
    } else return;
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        tmparr[i] = arr[i];
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &tar[i]);
    }
    int round = 0;
    if(isinsert(tmparr, n, &round)) {
        printf("Insertion Sort\n");
        insert_pass(tmparr, round);
        printarray(tmparr, n);
    } else {
        for(int i = 0; i < n; i++) tmparr[i] = arr[i];
        printf("Merge Sort\n");
        merge_sort(tmparr, n);
    }
    return 0;
}

/*
samples:
in:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
out:
Insertion Sort
1 2 3 5 7 8 9 4 6 0

in:
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
out:
Merge Sort
1 2 3 8 4 5 7 9 0 6


*/

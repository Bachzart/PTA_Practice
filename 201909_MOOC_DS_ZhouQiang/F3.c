#include <stdio.h>
#define MAXSIZE 100
int indexOfMax(int *array, int size);
int main(){
    int num[MAXSIZE];
    int total;
    scanf("%d",&total);
    for(int i=0; i<total; i++) scanf("%d",&num[i]);
    printf("%d\n",num[indexOfMax(num,total)]);
    return 0;
}

int indexOfMax(int *array, int size) {
    int index = 0;
    for(int i = 1; i < size; i++) {
        if(array[i] > array[index]) index = i;
    }
    return index;
}

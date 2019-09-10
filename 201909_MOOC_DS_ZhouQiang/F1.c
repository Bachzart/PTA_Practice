#include <stdio.h>

int getTreasure(int *pBucket, int x, int y);

int main(){
    int bucket,total;
    bucket = total = 0;
    scanf("%d",&total);
    for (int i=0; i<total; i++) {
        int x,y;
        x = y = 0;
        scanf("%d%d", &x, &y);
        int flag = getTreasure(&bucket, x, y);
        printf("[%d]:%d\n", flag, bucket);
    }
}

int getTreasure(int *pBucket, int x, int y) {
    int flag = 1;
    if(x % 2 == 0 && y % 2 == 0) *pBucket += 5;
    else if(x % 2 == 1 && y % 2 == 1) *pBucket += (*pBucket) / 3;
    else flag = 0;
    return flag;
}

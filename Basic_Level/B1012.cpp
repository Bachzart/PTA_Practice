#include <cstdio>

int main() {
    int n, temp, a[6] = {0}, sign = 1, count = 0, flag = 0;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &temp);
        int remain = temp % 5;
        if(remain == 0 && temp % 2 == 0) a[1] += temp;
        if(remain == 1) {
            a[2] += sign * temp;
            sign = -sign;
            flag = 1;
        }
        if(remain == 2) a[3]++;
        if(remain == 3) {
            a[4] += temp;
            count++;
        }
        if(remain == 4 && temp > a[5]) {
            a[5] = temp;
        }
    }
    if(a[1]) printf("%d ", a[1]);
    else printf("N ");
    if(flag) printf("%d ", a[2]);
    else printf("N ");
    if(a[3]) printf("%d ", a[3]);
    else printf("N ");
    if(a[4]) printf("%.1lf ", (double)a[4] / count);
    else printf("N ");
    if(a[5]) printf("%d", a[5]);
    else printf("N");
    return 0;
}

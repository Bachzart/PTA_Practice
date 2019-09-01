/* method 1: use string
#include <iostream>
using namespace std;
int getnum(char *str, char D) {
    int ret = 0;
    char *p = str;
    for(; *p != '\0'; p++) {    //loop condition also can use str[i] != '\0'
        if(*p == D) {
            ret = ret * 10 + (*p - '0');
        }
    }
    return ret;
}
int main() {
    char A[12], B[12], a, b;
    scanf("%s %c %s %c", A, &a, B, &b);
    printf("%d", getnum(A, a) + getnum(B, b));
    return 0;
}
*/
/* method 2: use int*/
#include <iostream>
using namespace std;
int getnum(int A, int a) {
    int ret = 0;
    do{
        if(A % 10 == a) ret = ret * 10 + a;
        A /= 10;
    } while(A > 0);
    return ret;
}
int main() {
    int A, B, a, b;
    scanf("%d %d %d %d", &A, &a, &B, &b);
    printf("%d", getnum(A, a) + getnum(B, b));
    return 0;
}

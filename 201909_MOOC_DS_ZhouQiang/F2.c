#include <stdio.h>
#include <string.h>
#define MAXLENGTH 100
int isPalindrome(const char* str, char* pch);
int main(){
    char str[MAXLENGTH],mid;
    scanf("%s",str);
    if(isPalindrome(str, &mid))
        printf("是回文！中间字符是%c\n",mid);
    else
        printf("不是回文！中间字符是%c\n",mid);
    return 0;
}

int isPalindrome(const char* str, char* pch) {
    int len = strlen(str), flag = 1;
    if(len % 2 == 1) *pch = str[len / 2];
    else *pch = str[len / 2 - 1];
    for(int i = 0; i < len / 2; i++) {
        if(str[i] != str[len - i - 1]) flag = 0;
    }
    return flag;
}

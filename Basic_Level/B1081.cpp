// new version
#include <cstdio>
#include <cstring>
#include <cctype>
char str[85];
int n;

int main() {
	scanf("%d%*c", &n);
	while(n--) {
		fgets(str, 85, stdin);
		if(strlen(str) - 1 < 6) {
			printf("Your password is tai duan le.\n");
			continue;
		}
		bool flag1, flag2, flag3;
		flag1 = flag2 = flag3 = false;
		for(int i = 0; str[i] != '\0'; i++) {
			if(isalpha(str[i])) flag2 = true;
			else if(isdigit(str[i])) flag3 = true;
			else if(str[i] == '.' || str[i] == '\n') continue;
			else flag1 = true;
		}
		if(flag1) printf("Your password is tai luan le.\n");
		else if(flag2 && !flag3) printf("Your password needs shu zi.\n");
		else if(!flag2 && flag3) printf("Your password needs zi mu.\n");
		else printf("Your password is wan mei.\n");
	}
	return 0;
}

/* 
// earlier version

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MaxLength 85

int Validity_Check(char *password);
char *Result[5] = {
	"Your password is tai duan le.",
	"Your password is tai luan le.",
	"Your password needs shu zi.",
	"Your password needs zi mu.",
	"Your password is wan mei.",
};

int main(int argc, char const *argv[]) {
	int flag, N;
	char Password[MaxLength];
	scanf("%d%*c", &N);
	while(N--) {
		gets(Password);	//notice the space
		flag = Validity_Check(Password);
		puts(Result[flag]);
	}
	return 0;
}

int Validity_Check(char *password) {
	int ret = 4, len = strlen(password), i;
	int num_flag, alpha_flag, invalid_flag;
	num_flag = alpha_flag = invalid_flag = 0;
	if(len >= 6) {
		for(i = 0; i < len; i++) {
			if( isdigit(password[i]) ) {
				num_flag = 1;
			} else if( isalpha(password[i]) ) {
				alpha_flag = 1;
			} else if(password[i] == '.') {
				continue;
			} else {
				invalid_flag = 1;
			}
		}
		if(invalid_flag) {
			ret = 1;
		} else if(!num_flag) {
			ret = 2;
		} else if(!alpha_flag) {
			ret = 3;
		}
	} else {
		ret = 0;
	}
	return ret;
}
*/
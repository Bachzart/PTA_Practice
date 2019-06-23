#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a, b;
	char c;
	scanf("%d %c %d", &a, &c, &b);
	a = -7; b = 2;
	c = '/';
	/*method 1:
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%'){
		if(c == '+') printf("%d\n", a + b);
		if(c == '-') printf("%d\n", a - b);
		if(c == '*') printf("%d\n", a * b);
		if(c == '/') printf("%d\n", a / b);
		if(c == '%') printf("%d\n", a % b);
	}else{
		printf("ERROR\n");
	}
	*/
	/*method 2:*/
	switch(c){
		case '+': printf("%d\n", a + b);break;
		case '-': printf("%d\n", a - b);break;
		case '*': printf("%d\n", a * b);break;
		case '/': printf("%d\n", a / b);break;
		case '%': printf("%d\n", a & b);break;
		default : printf("ERROR\n");
	}
	return 0;
}
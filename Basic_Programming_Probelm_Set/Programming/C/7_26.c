#include <stdio.h>

int main(int argc, char const *argv[])
{
	char ch;
	int length=0,flag=0;
	while((ch=getchar()) != '.')
	{
		if(ch != ' '){
			if(length > 0 && flag >0){
				printf("%d ", length);
				length=0;
			}
			length++;
			flag=0;
		}
		if(ch == ' ') flag++;
	}
	if(length > 0){
		printf("%d\n", length);
	}else{
		printf("\n");
	}
	return 0;
}

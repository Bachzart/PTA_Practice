#include <stdio.h>
#include <string.h>
char num2letter[11]="abcdefghij";
char units[4]="QBS";
void exchange(int num[], int n);

int main(int argc, char const *argv[])
{
	char number[10];
	scanf("%s", number);
	int i,len=strlen(number);
	int num[9]={0};
	for(i=0; i<len; i++){
		num[i]=number[i] - '0';
	}
	if(len <= 4){
		exchange(num, len-1);
	}else if(len <= 8){
		exchange(num, len-5);
		printf("W");
		exchange(num+len-4, 3);
	}else{
		printf("%cY", num2letter[num[0]]);
		exchange(num+1, 3);
		if(num[1]!=0 && num[2]!=0 && num[3]!=0 && num[4]!=0){
			printf("W");
		}
		if(num[len-4] == 0){
			printf("%c", num2letter[0]);
		}
		exchange(num+5, 3);
	}
	return 0;
}
void exchange(int num[], int n)
{
	int index = 0;
	while(num[index] == 0){
		index++;
	}
	if(num[index-1] == 0 && index != 0){
		printf("%c", num2letter[0]);
	}
	while(index <= n)
	{
		if(num[index] != 0 && index <= n){
			if(index != n){
				printf("%c%c", num2letter[num[index]], units[4-n-1+index]);
			}else{
				printf("%c", num2letter[num[index]]);
			}
		}else if(num[index] == 0 && num[index+1] != 0 && index <= n-1){
			printf("%c", num2letter[0]);
		}
		index++;
	}
}
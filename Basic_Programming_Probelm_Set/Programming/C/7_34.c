#include <stdio.h>
typedef struct address_list
{
	char name[12];
	char brith[12];
	char gender;
	char landline[18];
	char phone[18];
}address_list;
int main(int argc, char const *argv[])
{
	int i,N;
	scanf("%d", &N);
	address_list list[N];
	for(i=0; i<N; i++)
	{
		scanf("%s %s %c %s %s", list[i].name, list[i].brith, &list[i].gender, list[i].landline, list[i].phone);
	}
	int K,j;
	scanf("%d", &K);
	for(i=1; i<=K; i++)
	{
		int j,check_num=0,flag=0;
		scanf("%d", &check_num);
		for(j=0; j<N; j++)
		{
			if(j == check_num){
				printf("%s %s %s %c %s\n", list[j].name, list[j].landline, list[j].phone, list[j].gender, list[j].brith);
				flag=1;
			}
		}
		if(!flag) printf("Not Found\n");
	}
	return 0;
}

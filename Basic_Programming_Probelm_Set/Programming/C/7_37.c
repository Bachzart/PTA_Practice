#include <stdio.h>
void division(int i);
int N;
int s[31];
int top=-1;
int cnt=0;
int sum=0;

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	division(1);
	return 0;
}
void division(int i)
{
	if(sum == N){
		cnt++;
		printf("%d=", N);
		int k;
		for(k=0; k<top; k++)
		{
			printf("%d+", s[k]);
		}
		if(cnt%4 == 0 || s[top] == N){
			printf("%d\n", s[top]);
		}else{
			printf("%d;", s[top]);
		}
		return ;
	}
	if(sum > N){
		return ;
	}
	int j;
	for(j=i; j<=N; j++)
	{
		s[++top]=j;
		sum+=j;
		division(j);
		sum-=j;
		top--;
	}
}
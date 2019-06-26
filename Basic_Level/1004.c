#include <stdio.h>

typedef struct Stu
{
	char name[12];
	char number[12];
	int grade;
} students;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int i=0;
	students stu, max, min;
	scanf("%s %s %d", stu.name, stu.number, &stu.grade);
	max = min = stu;
	for(i=1; i<n; i++)
	{
		scanf("%s %s %d", stu.name, stu.number, &stu.grade);
		/*online processing, find the minimum and maximum when inputing. */ 
		if(stu.grade < min.grade) min = stu;
		if(stu.grade > max.grade) max = stu;
	} 
	printf("%s %s\n%s %s\n", max.name, max.number, min.name, min.number);
	return 0;
}

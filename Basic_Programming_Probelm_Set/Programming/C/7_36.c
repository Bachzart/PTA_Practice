#include <stdio.h>
#include <math.h>
/*
void print_complex_number(double a, double b);
double rounding(double n);
int main(int argc, char const *argv[])
{
	double a1,b1,a2,b2;
	// scanf("%lf %lf %lf %lf", &a1, &b1, &a2, &b2);
	// a1=1, b1=1, a2=-1, b2=-1.01;
	a1=2, b1=0, a2=-2.04, b2=0;
	// a1=0, b1=1.06, a2=0, b2=1.01;
	// printf("a1=%.1f,b1=%.1f,a2=%.1f,b2=%.1f\n", a1, b1, a2, b2);
	char ope[]="+-*-/";
	// printf("%s\n", ope);
	int i;
	for(i=0; i<4; i++)
	{
		double real_part=0,imaginary_part=0;
		switch(ope[i]){
			case '+': {
				printf("(");
				print_complex_number(a1, b1);
				printf(") + (");
				print_complex_number(a2, b2);
				printf(") = ");
				real_part=a1+a2;
				imaginary_part=b1+b2;
				print_complex_number(real_part, imaginary_part);
				printf("\n");
				// printf("%.2f,%.2f\n", rounding(real_part), rounding(imaginary_part));
				break;
			}
			case '-': {
				printf("(");
				print_complex_number(a1, b1);
				printf(") - (");
				print_complex_number(a2, b2);
				printf(") = ");
				real_part=a1-a2;
				imaginary_part=b1-b2;
				print_complex_number(real_part, imaginary_part);
				printf("\n");
				// printf("%.2f,%f\n", real_part, imaginary_part);
				// printf("%.1f,%f\n", rounding(real_part), rounding(imaginary_part));
				// printf("%.1f\n", rounding(0.050000));
				break;
			}
			case '*': {
				printf("(");
				print_complex_number(a1, b1);
				printf(") * (");
				print_complex_number(a2, b2);
				printf(") = ");
				real_part=a1*a2 - b1*b2;
				imaginary_part=a2*b1 + a1*b2;
				print_complex_number(real_part, imaginary_part);
				printf("\n");
				// printf("%.2f,%.2f\n", rounding(real_part), rounding(imaginary_part));
				break;
			}
			case '/': {
				printf("(");
				print_complex_number(a1, b1);
				printf(") / (");
				print_complex_number(a2, b2);
				printf(") = ");
				real_part=(a1*a2 + b1*b2) / (a2*a2 + b2*b2);
				imaginary_part=(a2*b1 - a1*b2) / (a2*a2 + b2*b2);
				print_complex_number(real_part, imaginary_part);
				printf("\n");
				// printf("%.2f,%.2f\n", rounding(real_part), rounding(imaginary_part));
				break;
			}
			default: break;
		}
	}
	return 0;
}

void print_complex_number(double a, double b)
{
	a = rounding(a);
	b = rounding(b);
	int flag=0;
	if(b < 0){
		flag = 1;
	}
	if(a == 0 && b == 0){
		printf("0.0");
	}else if(a == 0 && b != 0){
		printf("%.1fi", b);
	}else if(a != 0 && b == 0){
		printf("%.1f", a);
	}else{
		if(flag){
			printf("%.1f%.1fi", a, b);
		}else{
			printf("%.1f+%.1fi", a, b);
		}
	}
}


double rounding(double n)
{
	double ret=n,flag=1.0;
	if(ret < -0.1 || ret > 0.1) return ret;
	if(ret < 0){
		ret = -ret;
		flag=-flag;
	}
	if(ret < 0.05){
		ret = 0.0;
	}else{
		ret = 0.1;
	}
	return ret*flag;
}
*/

double a1,b1,a2,b2;
void print_complex_number(double a, char c, double b);
int main(int argc, char const *argv[])
{
	double real_part=0.0,imaginary_part=0.0;
	// scanf("%lf %lf %lf %lf", &a1, &b1, &a2, &b2);
	a1=0, b1=1.06, a2=0, b2=1.01;
	real_part=a1 + a2;
	imaginary_part=b1 + b2;
	print_complex_number(real_part, '+', imaginary_part);

	real_part=a1 - a2;
	imaginary_part=b1 - b2;
	print_complex_number(real_part, '-', imaginary_part);

	real_part=a1*a2 - b1*b2;
	imaginary_part=a2*b1 + a1*b2;
	print_complex_number(real_part, '*', imaginary_part);

	real_part=(a1*a2 + b1*b2) / (a2*a2 + b2*b2);
	imaginary_part=(a2*b1 - a1*b2) / (a2*a2 + b2*b2);
	print_complex_number(real_part, '/', imaginary_part);
	return 0;
}
void print_complex_number(double a, char c, double b)
{
	if(b1 >= 0 && b2 >= 0){
		printf("(%.1lf+%.1lfi) %c (%.1lf+%.1lfi) = ", a1, b1, c, a2, b2);
	}else if(b1 >= 0 && b2 < 0){
		printf("(%.1lf+%.1lfi) %c (%.1lf%.1lfi) = ", a1, b1, c, a2, b2);
	}else if(b1 < 0 && b2 >= 0){
		printf("(%.1lf%.1lfi) %c (%.1lf+%.1lfi) = ", a1, b1, c, a2, b2);
	}else{
		printf("(%.1lf%.1lfi) %c (%.1lf%.1lfi) = ", a1, b1, c, a2, b2);
	}
	if(fabs(a) < 0.1 && fabs(b) < 0.1){
		printf("0.0\n");
		return;
	}
	int flag=0;
	if(fabs(a) >= 0.1){
		printf("%.1lf", a);
		flag++;
	}
	if(fabs(b) >= 0.1){
		if(flag && b > 0.0){
			printf("+%.1lfi", b);
		}else{
			printf("%.1lfi", b);
		}
	}
	printf("\n");
}
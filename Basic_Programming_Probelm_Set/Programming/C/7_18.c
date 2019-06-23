#include <stdio.h>

float a3,a2,a1,a0;
float Cal_polynomial(float a);

int main(int argc, char const *argv[])
{
	scanf("%f %f %f %f", &a3, &a2, &a1, &a0);
	float left,right,midpoint;
	scanf("%f %f", &left, &right);
	while((Cal_polynomial(left) * Cal_polynomial(right)) <= 0 && (right-left) > 0.001){
		if(Cal_polynomial(left) == 0){
			printf("%.2f\n", left);
			return 0;
		}
		if(Cal_polynomial(right) == 0){
			printf("%.2f\n", right);
			return 0;
		}
		midpoint=(left+right)/2.0;
		if(Cal_polynomial(left) * Cal_polynomial(midpoint) > 0){
			left = midpoint;
		}else{
			right = midpoint;
		}
	}
	printf("%.2f\n", (left+right)/2);
	return 0;
}

float Cal_polynomial(float a)
{
	float ret;
	ret=(a3*a*a*a)+(a2*a*a)+(a1*a)+a0;
	return ret;
}

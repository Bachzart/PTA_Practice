#include <iostream>
#include <cmath>
#include <stack>
#include <string>
using namespace std;
string str;
double str2num(int &index) {
	double ret = 0;
	int pos = 0;
	for(; str[index] != ' ' && str[index] != '\0'; index++) {
		if(str[index] == '.') {
			pos = index;
			continue;
		} else {
			ret = ret * 10 + (str[index] - '0');
		}
	} 
	if(pos) ret /= pow(10, index - pos - 1);
	return ret;
}
int main() { 
	stack<double> num;
	getline(cin, str);
	double n, n1, n2;
	int sign = 1;
	for(int i = 0; i < str.length(); i++) {
		if(str[i] != ' ') {
			if(str[i] == '-' && ('0' <= str[i + 1] && str[i + 1] <= '9')) {
				sign = -1;
				continue;
			}
			if('0' <= str[i] && str[i] <= '9') {
				n = str2num(i) * sign;
				num.push(n);
				if(sign == -1) sign = 1;
			} else {
				n1 = num.top();
				num.pop();
				n2 = num.top();
				num.pop();
				if(str[i] == '+') {
					num.push(n1 + n2);
				} else if(str[i] == '-') {
					num.push(n2 - n1);
				} else if(str[i] == '*') {
					num.push(n1 * n2);
				} else if(str[i] == '/') {
					num.push(n2 / n1);
				}
			}
		}
	}
	printf("%.1lf", num.top());
	return 0;
}

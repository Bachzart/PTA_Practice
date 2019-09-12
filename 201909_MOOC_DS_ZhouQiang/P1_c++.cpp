#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string radix, num1, num2, num(105, '\0');
int main() {
	cin >> radix >> num1 >> num2;
	int len = radix.length(), len1 = num1.length(), len2 = num2.length();
	int index1, index2, count = 0, carry = 0, sum;
	int i = len1 - 1, j = len2 - 1;
	if(len1 >= len2) {
		for(; i >= 0; i--, j--) {
			index1 = radix.find(num1[i]);
			if(j >= 0) index2 = radix.find(num2[j]);
			else index2 = 0;
			sum = index1 + index2 + carry;
			carry = sum / len;
			num[count++] = radix[sum % len];
		}
		if(carry) num[count++] = radix[carry];
	} else {
		for(; j >= 0; j--, i--) {
			if(i >= 0) index1 = radix.find(num1[i]);
			else index1 = 0;
			index2 = radix.find(num2[j]);
			sum = index1 + index2 + carry;
			carry = sum / len;
			num[count++] = radix[sum % len]; 
		}
	}
	reverse(num.begin(), num.begin() + count);
	cout << num;
	return 0;
}

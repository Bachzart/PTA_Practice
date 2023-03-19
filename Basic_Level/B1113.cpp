#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<int, char> num2char = {
	{0, '0'}, {1, '1'}, {2, '2'},
	{3, '3'}, {4, '4'}, {5, '5'},
	{6, '6'}, {7, '7'}, {8, '8'},
	{9, '9'}, {10, 'a'}, {11, 'b'}, 
	{12, 'c'}, {13, 'd'}, {14, 'e'}, 
	{15, 'f'}, {16, 'g'}, {17, 'h'}, 
	{18, 'i'}, {19, 'j'}, {20, 'k'}, 
	{21, 'l'}, {22, 'm'}, {23, 'n'}, 
	{24, 'o'}, {25, 'p'}, {26, 'q'}, 
	{27, 'r'}, {28, 's'}, {29, 't'},
};
unordered_map<char, int> char2num = {
	{'0', 0}, {'1', 1}, {'2', 2},
	{'3', 3}, {'4', 4}, {'5', 5},
	{'6', 6}, {'7', 7}, {'8', 8},
	{'9', 9}, {'a', 10}, {'b', 11},
	{'c', 12}, {'d', 13}, {'e', 14},
	{'f', 15}, {'g', 16}, {'h', 17}, 
	{'i', 18}, {'j', 19}, {'k', 20}, 
	{'l', 21}, {'m', 22}, {'n', 23}, 
	{'o', 24}, {'p', 25}, {'q', 26}, 
	{'r', 27}, {'s', 28}, {'t', 29},
};

void trimRightZero(string &num) {
	for(auto it = num.rbegin(); it != num.rend(); it++) 
		if(*it == '0')
			num.pop_back();
		else 
			break;
}

int main() {
	string num1, num2, sum;
	cin >> num1 >> num2;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	int index = 0, carry = 0;
	while(index < num1.length() || index < num2.length()) {
		int tmp1 = index < num1.length() ? char2num[num1[index]] : 0;
		int tmp2 = index < num2.length() ? char2num[num2[index]] : 0;
		int s = tmp1 + tmp2 + carry;
		carry = s / 30;
		s %= 30;
		sum.push_back(num2char[s]);
		index++;
	}
	if(carry) 
		sum.push_back(num2char[carry]);
	trimRightZero(sum);
	reverse(sum.begin(), sum.end());
	if(sum == "") sum = "0";
	cout << sum << endl;
	return 0;
}
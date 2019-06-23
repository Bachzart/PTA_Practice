#include <iostream>
using namespace std;
 
int main(int argc, char const *argv[])
{
	int dec, hex;
	cin >> dec;
	hex = (dec / 16) * 10 + dec % 16;
	cout << hex << endl;
	return 0;
}

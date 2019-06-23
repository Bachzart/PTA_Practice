#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int centimeters, foot, inch;
	cin >> centimeters;
	foot = centimeters / 30.48;
	inch = centimeters / 2.54 - 12*foot;
	cout << foot << " " << inch << endl;
	return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
	double f1, f2;
	int a;
	char c;
	cin >> f1 >> a >> c >> f2;
	/* setiosflags is liked %x in C.
	Once haved used setiosflags(ios::fixed) and setprecision(n), all the next floating number will follow this format. 
	*/
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << c << " " << a << " " << f1 << " " << f2;
	return 0;
}

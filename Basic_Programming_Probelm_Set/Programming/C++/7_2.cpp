#include <iostream>
using namespace std;

int main(){
	int start, time, end;
	cin >> start >> time;
	int hours, minutes;
	minutes = start/100*60 + start%100 + time;
	hours = minutes / 60;
	minutes -= hours*60;
	end = hours*100 + minutes;
	cout << end << endl;
	return 0;
} 

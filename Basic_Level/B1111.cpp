// method 1: use int
#include <cstdio>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string, int> mon2num = {
	{"Jan", 1},
	{"Feb", 2},
	{"Mar", 3},
	{"Apr", 4},
	{"May", 5},
	{"Jun", 6},
	{"Jul", 7},
	{"Aug", 8},
	{"Sep", 9},
	{"Oct", 10},
	{"Nov", 11},
	{"Dec", 12},
};

int main(int argc, char const *argv[]) {
	char month[5];
	int day, year, N;
	scanf("%d", &N);
	while(N--) {
		scanf("%s %d, %d", month, &day, &year);
		string str_mon = month;
		int mon = mon2num[month];
		int n = year * 10000 + mon * 100 + day;
		string ans = to_string(n), rans;
		if(ans.length() == 7)
			ans = "0" + ans;
		if(ans.length() == 6)
			ans = "00" + ans;
		if(ans.length() == 5)
			ans = "000" + ans;
		rans = ans;
		reverse(rans.begin(), rans.end());
		if(ans == rans)
			printf("Y ");
		else
			printf("N ");
		printf("%s\n", ans.c_str());
	}
	return 0;
}

/*
// method 2: use string

#include <cstdio>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string, string> mon2num = { 
	{"Jan", "01"}, 
	{"Feb", "02"}, 
	{"Mar", "03"}, 
	{"Apr", "04"}, 
	{"May", "05"}, 
	{"Jun", "06"}, 
	{"Jul", "07"}, 
	{"Aug", "08"}, 
	{"Sep", "09"}, 
	{"Oct", "10"}, 
	{"Nov", "11"}, 
	{"Dec", "12"}, 
};

int main(int argc, char const *argv[]) {
	char month[5];
	int day, year, N;
	scanf("%d", &N);
	while(N--) {
		scanf("%s %d, %d", month, &day, &year);
		string str_mon = month, str_day = to_string(day), str_year = to_string(year);
		if(str_day.length() == 1) 
			str_day = "0" + str_day;
		if(str_year.length() == 1) 
			str_year = "000" + str_year;
		else if(str_year.length() == 2)
			str_year = "00" + str_year;
		else if(str_year.length() == 3) 
			str_year = "0" + str_year;
		string date = str_year + mon2num[str_mon] + str_day;
		string tmp = date;
		reverse(tmp.begin(), tmp.end());
		if(date == tmp) 
			printf("Y ");
		else 
			printf("N ");
		printf("%s\n", date.c_str());
	}
	return 0;
}
*/
#include <cstdio> 
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 5;

struct record{
	char name[25];
	int month, day, hour, minute;
	bool status;
} rec[MAXN], temp;
int rate[25] = {0};

bool cmp(record a, record b);
void get_time(int on, int off, int &time, int &money);

int main(int argc, char const *argv[]) {
	for(int i = 0; i < 24; i++) {
		scanf("%d", rate + i);
	}
	int N;
	scanf("%d", &N);
	char line[10];
	for(int i = 0; i < N; i++) {
		scanf("%s %d:%d:%d:%d", rec[i].name, &rec[i].month, &rec[i].day, &rec[i].hour, &rec[i].minute);
		scanf("%s", line);
		if(!strcmp(line, "on-line")) {
			rec[i].status = true;
		} else {
			rec[i].status = false;
		}
	}
	sort(rec, rec + N, cmp);
	int on = 0, off, next;
	while(on < N) {
		int needPrint = 0;
		next = on;
		// fint the next customer, and check the current customer has paired 'on-line' and 'off-line' or not
		while(next < N && strcmp(rec[next].name, rec[on].name) == 0) {
			if(needPrint == 0 && rec[next].status == true) {
				needPrint = 1;
			} else if(needPrint == 1 && rec[next].status == false) {
				needPrint = 2;
			}
			next++;
		}
		//the current customer has not paired 'on-line' and 'off-line', skip this customer
		if(needPrint < 2) {
			on = next;
			continue;
		}
		//calculate the money for current customer
		int Total = 0;
		printf("%s %02d\n", rec[on].name, rec[on].month);
		while(on < next) {
			//find the paired 'on-line' and 'off-line'
			while(on < next - 1 && !(rec[on].status == true && rec[on + 1].status == false)) {
				on++;
			} 
			off = on + 1;
			if(off == next) {
				on = next;
				break;
			}
			printf("%02d:%02d:%02d ", rec[on].day, rec[on].hour, rec[on].minute);
			printf("%02d:%02d:%02d ", rec[off].day, rec[off].hour, rec[off].minute);
			int time = 0, money = 0;
			get_time(on, off, time, money);
			Total += money;
			printf("%d $%.2lf\n", time, money / 100.0);
			on = off + 1; 
		}
		printf("Total amount: $%.2lf\n", Total / 100.0);
	}
	return 0;
}

bool cmp(record a, record b) {
	if(strcmp(a.name, b.name)) return strcmp(a.name, b.name) < 0;
	else if(a.month != b.month) return a.month < b.month;
	else if(a.day != b.day) return a.day < b.day;
	else if(a.hour != b.hour) return a.hour < b.hour;
	else return a.minute < b.minute;
}

void get_time(int on, int off, int &time, int &money) {
	temp = rec[on];
	while(temp.day < rec[off].day || temp.hour < rec[off].hour || temp.minute < rec[off].minute) {
		time++;
		money += rate[temp.hour];
		temp.minute++;
		if(temp.minute >= 60) {
			temp.minute = 0;
			temp.hour++;
		}
		if(temp.hour >= 24) {
			temp.hour = 0;
			temp.day++;
		}
	}
}

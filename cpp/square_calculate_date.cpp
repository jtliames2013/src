知道今天11/26/2015是Thuesday。
然后写一个fucntion, 输入任何一个过去的日期，都能返回是星期几。不用考虑闰年。
比如，输入10/30/2015返回Friday. 感觉不是现在的面试题风格啊。。

给了reference date是星期几, 然后input是year, month, day
output求出那一天是星期几. 

enum Date {
	Monday=0,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

class Solution {
public:
	Solution () {
		currYear=2015;
		currMonth=11;
		currDay=15;
		currDate=Sunday;
		monthDays={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	}

	Date getDate(int year, int month, int day) {
		int days=0; // gap between day and currDay not including day
		bool old=false;
		if (year<currYear) {
			// add curr year days
			for (int i=0; i<currMonth-1; i++) {
				days+=monthDays[i];
			}
			days+=currDay;
			// add middle years days
			days+=365*(currYear-year-1);
			// add to calculate year days
			days+=monthDays[month-1]-day;
			for (int i=month; i<12; i++) {
				days+=monthDays[i];
			}
			old=true;
		} else if (year==currYear) {
			if (month<currMonth) {
				days+=currDay;
				for (int i=month; i<currMonth-1; i++) {
					days+=monthDays[i];
				}
				days+=monthDays[month-1]-day;
				old=true;
			}
			else if (month==currMonth) {
				if (day<currDay) {
					days+=currDay-day;
					old=true;
				} else if (day>currDay) {
					days+=day-currDay;
				}
			} else {
				days+=day-1;
				for (int i=currMonth; i<month-1; i++) {
					days+=monthDays[i];
				}
				days+=monthDays[currMonth-1]-(currDay-1);
			}
		} else {
			// add to calculate year days
			for (int i=0; i<month-1; i++) {
				days+=monthDays[i];
			}
			days+=day-1;
			// add middle years days
			days+=365*(year-currYear-1);
			// add curr year days
			days+=monthDays[currMonth-1]-(currDay-1);
			for (int i=currMonth; i<12; i++) {
				days+=monthDays[i];
			}
		}

		int date;
		int mod=days%7;
		if (old) {
			date=currDate-mod;
			if (date<0) date+=7;
		} else {
			date=(currDate+mod)%7;
		}

		return (Date)date;
	}

private:
	vector<int> monthDays;
	int currYear;
	int currMonth; // from 1 - 12
	int currDay; // start from 1
	Date currDate;
};

int main() {
	Solution s;
	//int date=s.getDate(2015,3,5);
	int date=s.getDate(2014,12,16);
	//int date=s.getDate(2016,1,20);
	cout << date << endl;
	return 0;
}


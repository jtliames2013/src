1. 给出 ［“1999-02-13”， “2001-03-14"］ 打印出中间所有的月份 ［“1999-02-13”， “1999-02-28"]，［“1999-03-01”， “1999-03-31"] ...  ["2001-03-01", “2001-03-14"］当然input可以是任意年月日。

class Interval {
public:
	string start;
	string end;
	Interval() {}
	Interval(string s, string e):start(s), end(e) {}
};

class Date {
public:
	int year;
	int month;
	int day;
	Date():year(0), month(0), day(0) {}
	Date(int y, int m, int d):year(y), month(m), day(d) {}
};

class Solution {
public:
	void printRange(Interval range) {
		Date start=parseDate(range.start), end=parseDate(range.end);
		for (int i=start.year, j=start.month; i<end.year || (i==end.year && j<=end.month); ) {
			ostringstream osss, osse;
			if (i==start.year && j==start.month) {
				osss << start.year << "-";
				osss << setw(2) << setfill('0') << start.month;
				osss << "-";
				osss << setw(2) << setfill('0') << start.day;
			} else {
				osss << i << "-";
				osss << setw(2) << setfill('0') << j;
				osss << "-";
				osss << setw(2) << setfill('0') << mp[j].first;
			}

			if (i==end.year && j==end.month) {
				osse << end.year << "-";
				osse << setw(2) << setfill('0') << end.month;
				osse << "-";
				osse << setw(2) << setfill('0') << end.day;
			} else {
				osse << i << "-";
				osse << setw(2) << setfill('0') << j;
				osse << "-";
				if (i%4==0 && j==2) {
					// leap year
					osse << setw(2) << setfill('0') << "29";
				} else {
					osse << setw(2) << setfill('0') << mp[j].second;
				}
			}

			cout << "[" << osss.str() << ", " << osse.str() << "]" << endl;
			j++;
			if (j>12) {
				i++;
				j=1;
			}
		}
	}
private:
	Date parseDate(string s) {
		Date d;
		istringstream iss(s);
		string val;
		int i=0;
		while (getline(iss, val, '-')) {
			if (i==0) d.year=stoi(val);
			else if (i==1) d.month=stoi(val);
			else if (i==2) d.day=stoi(val);
			i++;
		}
		return d;
	}

	unordered_map<int, pair<string,string>> mp = {
		{1, {"1", "31"}},
		{2, {"1", "28"}},
		{3, {"1", "31"}},
		{4, {"1", "30"}},
		{5, {"1", "31"}},
		{6, {"1", "30"}},
		{7, {"1", "31"}},
		{8, {"1", "31"}},
		{9, {"1", "30"}},
		{10, {"1", "31"}},
		{11, {"1", "30"}},
		{12, {"1", "31"}}
	};
};

int main() {
	Solution s;
	Interval range("1999-02-13", "2001-03-14");
	s.printRange(range);
	return 0;
}


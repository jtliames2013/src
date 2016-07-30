Count in the last minitue, hour, etc.

class Solution {
public:
	Solution(int n) {
		// assert n>60
		windowSize=n;
		hourIter=count.begin();
		tenminIter=count.begin();
		countHour=0;
		countTenMin=0;
	}

	void cleanObsolete(int currTime) {
		if (hourIter==count.end()) hourIter=count.begin();
		while (hourIter!=count.end()) {
			if (currTime-hourIter->first>=60) {
				countHour-=hourIter->second;
				hourIter++;
			} else {
				break;
			}
		}

		if (tenminIter==count.end()) tenminIter=count.begin();
		while (tenminIter!=count.end()) {
			if (currTime-tenminIter->first>=10) {
				countTenMin-=tenminIter->second;
				tenminIter++;
			} else {
				break;
			}
		}

		while (!count.empty()) {
			pair<int,int> f=count.front();
			if (currTime-f.first>=windowSize) {
				count.pop_front();
			} else {
				break;
			}
		}
	}

	void updateCount(int currTime) {
		cleanObsolete(currTime);
		if (!count.empty() && count.back().first==currTime) {
			count.back().second++;
		} else {
			count.push_back({currTime, 1});
		}
		countHour++;
		countTenMin++;
	}

	int getLastHour(int currTime) {
		cleanObsolete(currTime);
		return countHour;
	}

	int getLastTenMinute(int currTime) {
		cleanObsolete(currTime);
		return countTenMin;
	}

	int enumCount(int currTime, int interval) {
		int cnt=0;
		for (auto riter=count.rbegin(); riter!=count.rend(); riter++) {
			if (currTime-riter->first>=interval) break;
			else {
				cnt+=riter->second;
			}
		}
		return cnt;
	}

	int getCount(int currTime, int interval) {
		cleanObsolete(currTime);
		return enumCount(currTime, interval);
	}

private:
	list<pair<int, int>> count;
	list<pair<int, int> >::iterator hourIter;
	list<pair<int, int> >::iterator tenminIter;
	int windowSize;
	int countHour;
	int countTenMin;
};

int main() {
	Solution s(120);
	for (int i=0; i<20; i++) {
		s.updateCount(i);
		s.updateCount(i);
	}
	int res=s.getCount(19, 10);
	cout << res << endl;
	int hour=s.getLastHour(14);
	cout << hour << endl;
	return 0;
}


1. 有一个function A，会被callback访问到，让实现一个funciton，可以统计过去N秒
这个A被call了几次。 经典题，circular array统计每秒call的次数

class Solution {
public:
	Solution(int n) {
		windowSize=n;
		total=0;
	}

	void cleanObsolete(int time) {
		while (!count.empty()) {
			pair<int,int> f=count.front();
			if (time-f.first>=windowSize) {
				count.pop();
				total-=f.second;
			} else {
				break;
			}
		}
	}

	void updateCount(int time) {
		cleanObsolete(time);
		if (!count.empty() && count.back().first==time) {
			count.back().second++;
		} else {
			count.push({time, 1});
		}
		total++;
	}

	int getCount(int time) {
		cleanObsolete(time);
		return total;
	}

private:
	queue<pair<int, int>> count;
	int windowSize;
	int total;
};

int main() {
	Solution s(10);
	for (int i=0; i<15; i++) {
		s.updateCount(i);
		s.updateCount(i);
	}
	int res=s.getCount(14);
	cout << res << endl;
	return 0;
}


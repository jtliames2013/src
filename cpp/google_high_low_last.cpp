刚刚面的G家，三哥上来二话不说两道题+follow1.Implement a simple stock price display systemwhich will show High, Low and Last price for a given stock throughout one day.The data comes from a real-time feed and have the following messages:
PriceUpdate(t, P) -> Price of Stock A at timet is P.
Correction(t, NewP) -> Price of Stock A attime t is rectified to NewP
Remove(t) -> Disregard the price feedreceived at time t.
PriceUpdate(10100,850.50) -> high = 850.50, Low = 850.50, Last = 850.50
PriceUpdate(10200,852.25) -> high = 852.25, Low = 850.50, Last = 852.25
PriceUpdate(10300,848.00) -> high = 852.25, Low = 848.00, Last = 848.00
Correction(10200, 849.00) -> high = 850.50, Low = 848.00, Last 848.00
PriceUpdate(10400,855.00)  -> high = 855.00, Low = 848.00, Last = 855.00
Correction(10300, 853.00) -> high = 855.00, Low = 850.50, Last = 855.00
PriceUpdate(10500,854.00) -> high = 855.00, Low = 848.00, Last = 854.00
Correction(10500,853.25) -> high = 855.00, Low = 848.00, Last = 853.25
Remove(10300) -> high = 855.00, Low = 849.00, Last = 853.25

简单说来PriceUpdate就是添加新的（timestamp, price）, Correction是改之前的(timestamp, price), 求实现当前high(), low(), last()
LZ是用的Heap + HashMap, 特别问了时间复杂度(我猜到他想考heap的remove(obj)复杂度)
follow Up是: 有没有办法把复杂度降到O(logN)

class Solution {
public:
	double high() {
		if (price.empty()) return -1;
		return *price.rbegin();
	}

	double low() {
		if (price.empty()) return -1;
		return *price.begin();
	}

	double last() {
		if (time.empty()) return -1;
		return time.begin()->second;
	}

	void add(int t, double p) {
		if (time.find(t)!=time.end()) return;
		time[t]=p;
		price.insert(p);
	}

	void update(int t, double p) {
		if (time.find(t)==time.end()) return;
		price.erase(time[t]);
		time[t]=p;
		price.insert(p);
	}

	void remove(int t) {
		if (time.find(t)==time.end()) return;
		price.erase(time[t]);
		time.erase(t);
	}

private:
	multiset<double> price;
	map<int, double> time;
};


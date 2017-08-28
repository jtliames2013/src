可以随便交易很多次，可以同时买很多股票，但是一旦卖就要把手里的股票全部卖了，问怎样最大化收益。比如[1, 2,3], 前2天都买，第三天全部卖，收益就是(3-1)+(3-2).
stock sell all

class Solution {
public:
	int maxProfix(vector<int> prices) {
		int maxPrice=0, res=0;
		for (int i=prices.size()-1; i>=0; i--) {
			maxPrice=max(maxPrice, prices[i]);
			res+=max(0, maxPrice-prices[i]);
		}
		return res;
	}
};


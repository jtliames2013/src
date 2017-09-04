给两个数 n1, n2. n2 is n1 without 1 digit, e.g. n1 = 123, then n2 can be 12, 13 or 23. 现在知道n1+n2的和是多少， 求n1 和 n2 的可能值

class Solution {
public:
	vector<pair<int,int>> findPair(int sum) {
		vector<pair<int,int>> res;
		unordered_map<int, pair<int,int>> mp;
		if (sum<11) {
			res.push_back({sum,0});
			return res;
		}
		int base=1;
		while (sum/(11*base)>0) {
			int low=sum%base;
			if (low%2==0) {
				int total=sum/base;
				int high=total/11;
				int miss=total%11;
				int borrow=0;
				while (borrow<2 && miss>=0) {
					int l=low+borrow*base;
					l/=2;
					int n1=l+miss*base+high*base*10;
					int n2=l+high*base;
					mp[n1]={n1, n2};

					if (base==1) break;
					borrow++;
					miss--;
				}
			}

			base*=10;
		}

		for (auto iter:mp) res.push_back(iter.second);
		return res;
	}
};

int main()
{
	Solution s;
	//int sum=2;
	//int sum=39;
	//int sum=1246;
	int sum=1346;
	vector<pair<int,int>> v=s.findPair(sum);
	for (auto p:v) cout << p.first << " " << p.second << endl;
	return 0;
}


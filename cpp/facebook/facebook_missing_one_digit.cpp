给两个数 n1, n2. n2 is n1 without 1 digit, e.g. n1 = 123, then n2 can be 12, 13 or 23. 现在知道n1+n2的和是多少， 求n1 和 n2 的可能值

给的提示非常有意义，比如 sum = A + A'
A'是A去掉任意一位。那么可以看成是两部分相加：
sum = (A1 + A1')*(10^r) + 2*A2
其中，A1是A的左半部分，A2是A的右半部分。比如A1'则是A1去掉了最后一位。r则是截成左右两段的位数。
而如果A1'是A1去掉最后一位，则非常容易反推
例如：1246 = 1223+123

n2是n1少一位digit，输入s=n1 + n2, 求(n1, n2)的可能解

123456
   ^
   e
^^^ ^^
h   t

e为去掉的digit
h为前缀
t为后缀
s = 2 * t + (11 * h + e) * 10^r
= 2 * t + e * 10^r + h * 11 * 10^r

注意2 * t < 10^r, 0 <= e <= 9

尝试不同的r. From 1point 3acres bbs
h = s / (11 * 10^r)
e * 10^r + 2 * t = s % (11 * 10 ^ r)
e = (s % (11 * 10 ^ r)) / 10 ^ r
t = ((s % (11 * 10 ^ r)) % 10 ^ r) / 2

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


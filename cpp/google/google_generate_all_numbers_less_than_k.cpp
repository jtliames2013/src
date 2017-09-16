given an input list of digits, generate numbers smaller than target number

class Solution {
public:
	void generate(vector<int>& res, vector<int>& digits, int& num, int start, int k) {
		for (int i=0; i<digits.size(); i++) {
			if (num==0 && digits[i]==0) continue;
			num=num*10+digits[i];
			if (num<k) {
				res.push_back(num);
				generate(res, digits, num, i, k);
			}
			num/=10;
		}
	}

	vector<int> generate(vector<int> digits, int k) {
		vector<int> res;
		int num=0;
		generate(res, digits, num, 0, k);

		return res;
	}
};


int main()
{
	Solution s;
	vector<int> digits={0, 1, 2, 3};
	vector<int> res=s.generate(digits, 25);
	for (auto n:res) cout << n << endl;
	return 0;
}


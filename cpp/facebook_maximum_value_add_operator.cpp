给一个数字组成的字符串，可以在任意两个数字之间放加号或乘号，求可以得到的最大值。就是用divide + memorization解之。

class Solution {
public:
	int dfs(string& nums, int start, int end, unordered_map<string,int>& mp) {
		string str=nums.substr(start, end-start+1);
		if (mp.find(str)!=mp.end()) return mp[str];
		if (start==end) {
			int val=stoi(str);
			mp[str]=val;
			return val;
		}

		int res=INT_MIN;
		for (int i=start; i<end; i++) {
			int l=dfs(nums, start, i, mp);
			int r=dfs(nums, i+1, end, mp);
			res=max(res, l+r);
			res=max(res, l*r);
		}
		mp[str]=res;
		return res;
	}

	int findMaxValue(string nums) {
		unordered_map<string,int> mp;
		return dfs(nums, 0, nums.size()-1, mp);
	}
};

int main()
{
	Solution s;
	string nums="1121";
	cout << s.findMaxValue(nums) << endl;
	return 0;
}


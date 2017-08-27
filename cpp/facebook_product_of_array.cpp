product of the array   给定一个array，返回里面元素乘积的所有可能值。 例如给定array:[1,2,3,4]   应该返回 [1, 2, 3, 4, 6, 8, 12, 24]

class Solution {
public:
	void getProd(unordered_set<int>& st, int prod, vector<int>& nums, int start) {
		for (int i=start; i<nums.size(); i++) {
			prod*=nums[i];
			st.insert(prod);
			getProd(st, prod, nums, i);
			prod/=nums[i];
		}
	}

	vector<int> productArray(vector<int> nums) {
		vector<int> res;
		unordered_set<int> st;
		int prod=1;
		getProd(st, prod, nums, 0);

		for (auto i:st) res.push_back(i);
		return res;
	}
};


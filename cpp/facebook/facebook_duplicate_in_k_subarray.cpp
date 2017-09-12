大家都在问第一题，大概是这个意思：给一个array, 然后给一个k, 让你check 连续的k个integer是否含有dulplicate, 很简单的，用窗口为K的hashset一直扫一遍就行了，很简单

class Solution {
public:
	bool duplicateInKConsecutiveSubarray(vector<int> nums, int k) {
		int n=nums.size();
		if (n==0) return false;
		unordered_set<int> st;
		for (int i=0; i<n; i++) {
			if (st.find(nums[i])!=st.end()) return true;
			st.insert(nums[i]);
			if (i>=k) st.erase(nums[i-k]);
		}

		return false;
	}
};

int main()
{
	Solution s;
	vector<int> nums={1,2,3,1,3,3};
	bool res=s.duplicateInKConsecutiveSubarray(nums, 3);
	cout << res << endl;
	return 0;
}


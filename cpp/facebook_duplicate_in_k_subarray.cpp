大家都在问第一题，大概是这个意思：给一个array, 然后给一个k, 让你check 连续的k个integer是否含有dulplicate, 很简单的，用窗口为K的hashset一直扫一遍就行了，很简单

class Solution {
public:
	bool duplicateInKConsecutiveSubarray(vector<int> nums, int k) {
		int n=nums.size();
		if (n==0) return false;
		map<int,int> count;
		int i;
		for (i=0; i<k && i<n; i++) {
			if (count[nums[i]]>0) return true;
			count[nums[i]]++;
		}

		for (; i<n; i++) {
			count[nums[i-k]]--;
			if (count[nums[i]]>0) return true;
			count[nums[i]]++;
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


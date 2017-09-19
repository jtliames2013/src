问一个数组能否只改变一个数字，从而让他变成单调增的数组

class Solution {
public:
	bool canChangeOne(vector<int> nums) {
		int n=nums.size();
		if (n<2) return true;
		bool changed=false;
		for (int i=1; i<n; i++) {
			if (nums[i]<nums[i-1]) {
				if (changed) return false;
				changed=true;
				if (i-1==0 || nums[i]>=nums[i-2]) nums[i-1]=nums[i];
				else nums[i]=nums[i-1];
			}
		}

		return true;
	}
};

int main()
{
	Solution s;
	//vector<int> nums={3,3,2,2};
	vector<int> nums={1,2,5,3,3};
	cout << s.canChangeOne(nums) << endl;
	return 0;
}


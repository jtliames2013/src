. 给一个数组，找最长山脉。山脉的定义是先升后降。
比如，假设[2, 6, 1, 8, 9, 2, 7, 3, 10]， 那么[1, 8, 9, 2]就是最长山脉

class Solution {
public:
	int longestMountain(vector<int> nums) {
		int res=0, n=nums.size(), bottom1, bottom2;
		for (int i=0; i<n; ) {
			while (i<n-1 && nums[i]>=nums[i+1]) i++;
			bottom1=i;
			while (i<n-1 && nums[i]<=nums[i+1]) i++;
			while (i<n-1 && nums[i]>=nums[i+1]) i++;
			bottom2=i;
			res=max(res, bottom2-bottom1+1);
			if (i==n-1) break;
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> nums={2, 6, 1, 8, 9, 2, 7, 3, 10};
	//vector<int> nums={0, 2, 4, 8, 6, 10, 12, 11, 9, 7, 3, 5, 1};
	cout << s.longestMountain(nums) << endl;
	return 0;
}


似乎是新题， 给一个排序好的数组，数一数有多少个子集（subset）使得子集里面的最大元素加上最小元素小于K。
A: [2, 3, 5, 7]  K: 8 
=> # of subsets S: Max(S) + Min(S) < K
=> [2] , [2, 3], [2, 5], [2, 3, 5], [3] => #: 5

class Solution {
public:
	int twoSumSmaller(vector<int> nums, int target) {
		int n=nums.size(), l=0, r=n-1;
		if (n<2) return 0;
		int res=0;
		if (nums[r]+nums[r]<target) return pow(2, r-l+1)-1;
		while (l<=r) {
			if (nums[l]+nums[r]>=target) r--;
			else {
				// all subsets between l and r plus (l) and (l,r)
                // if there is duplidate, then count between l and r, multiply by count+1
				res+=pow(2, r-l);
				l++;
			}
		}
		return res;
	}
};


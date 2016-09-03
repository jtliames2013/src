2. 给一组数 [10,4,6,7,8,9], 然后给一个range 比如是 [1,5], 求出这个数组中所有的在这个range中的数.
    这题和 leetcode里 search range 很类似. 主要是 binary search.
    follow up 是如果数组中存在重复的数怎么处理, 反正search range的解法可以handle这个.
    这一轮面试面试官迟到了10分钟,然后聊的也比较开心和谐. 很快就写完了,算上面试官迟到的10分钟一共就30分钟, 面试官就说他OK了, 然后问他问题. 

class Solution {
public:
	vector<int> search(vector<int>& nums, int start, int end) {
		vector<int> res;
		for (int i=start; i<=end; i++) {
			if (search(nums, i)) res.push_back(i);
		}
		return res;
	}

	bool search(vector<int>& nums, int target) {
		int l=0, r=nums.size()-1;
		int mid;

		while (l<=r) {
			mid=l+(r-l)/2;
			if (nums[mid]==target) return true;
			if (nums[mid]<nums[r]) {
				if (target>nums[mid] && target<=nums[r]) {
					l=mid+1;
				} else {
					r=mid-1;
				}
			} else if (nums[mid]>nums[r]){
				if (target>=nums[l] && target<nums[mid]) {
					r=mid-1;
				} else {
					l=mid+1;
				}
			} else {
				r--;
			}
		}

		return false;
	}
};

int main() {
	Solution s;
	vector<int> nums={10,4,6,7,8,9};
	vector<int> res=s.search(nums, 1, 5);
	return 0;
}


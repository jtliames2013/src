第一道题, 给一个数组让排序, 然而排序只可以用一个反转函数reverse(int[] array, int end), 意思就是反转数组中第0个到第end个为止的数, 比如:[br][8, 7, 6. 5, 10, 1], reverse(array, 2)的话就变成[6, 7, 8, 5, 10, 1], 只能call这个反转函数直到数组中所有的数排好序为止.

第二道题, 第一题的follow up, 现在给的是布尔数组, 还是反转函数reverse(array, end), 只是除了反转以外, 需要反转的数都要被取反, 比如:
[true, false, false, false, true, true], reverse(array, 2)的话, 就变成[true, true, false, false, true, true], 需要最后把这个数组变成[true, true, true, true, true, true]

class Solution {
public:
	void sort(vector<int>& nums) {
		size_t n=nums.size();
		for (size_t i=n-1; i>0; i--) {
			int maxVal=INT_MIN, maxIdx=-1;
			for (size_t j=0; j<=i; j++) {
				if (nums[j]>maxVal) {
					maxVal=nums[j];
					maxIdx=j;
				}
			}
			reverse(nums.begin(), nums.begin()+maxIdx+1);
			reverse(nums.begin(), nums.begin()+i+1);
		}
	}

	void reverseToggle(vector<bool>& nums, int end) {
		reverse(nums.begin(), nums.begin()+end+1);
		for (int i=0; i<=end; i++) nums[i]=!nums[i];
	}

	void setTrue(vector<bool>& nums) {
		size_t n=nums.size();
		for (int i=n-1; i>=0; i--) {
			if (nums[i]==false) {
				if (nums[0]) reverseToggle(nums, 0);
				reverseToggle(nums, i);
			}
		}
	}
};

int main() {
	Solution s;
	vector<int> nums={3,4,8,1,0,9,7,11,5,3,2};
	s.sort(nums);
	for (auto i:nums) cout << i << " ";
	cout << endl;

	vector<bool> nums2={true, false, false, false, true, true};
	s.setTrue(nums2);
	for (auto i:nums2) cout << i << " ";
	cout << endl;
	return 0;
}


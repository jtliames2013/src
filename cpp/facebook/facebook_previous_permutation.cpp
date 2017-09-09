就是lc next permutation的反着来的previous permutation，做法一样

class Solution {
public:
    void previousPermutation(vector<int>& nums) {
    	int n=nums.size();
    	int i=n-1;
    	for (; i>0; i--) {
    		if (nums[i]<nums[i-1]) break;
    	}
    	if (i==0) {
    		reverse(nums.begin(), nums.end());
    	}

    	int k=i-1, j=n-1;
    	for (; j>=i; j--) {
    		if (nums[j]<nums[k]) break;
    	}
    	swap(nums[k], nums[j]);
    	reverse(nums.begin()+i, nums.end());
    }
};

int main()
{
	Solution s;
	vector<int> v={2,1,3};
	s.previousPermutation(v);
	for (auto i:v) cout << i << " ";
	cout << endl;
	return 0;
}


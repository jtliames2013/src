90. Subsets II  
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
Hide Company Tags Facebook
Hide Tags Array Backtracking

class Solution {
public:
    void getSet(vector<vector<int>>& res, vector<int>& output, vector<int>& nums, int start) {
        res.push_back(output);
        
        for (int i=start; i<nums.size(); i++) {
            if (i==start || nums[i]!=nums[i-1]) {
                output.push_back(nums[i]);
                getSet(res, output, nums, i+1);
                output.pop_back();
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        if (n==0) return res;
        sort(nums.begin(), nums.end());
        vector<int> output;
        getSet(res, output, nums, 0);
        
        return res;
    }
};

int main()
{
	return 0;
}


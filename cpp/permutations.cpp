46. Permutations  
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
Hide Company Tags LinkedIn Microsoft
Hide Tags Backtracking
Hide Similar Problems (M) Next Permutation (M) Permutations II (M) Permutation Sequence (M) Combinations

swap and move one number at a time
class Solution {
public:
    void getPerm(vector<vector<int>>& res, vector<int>& nums, int start) {
        if (start==nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i=start; i<nums.size(); i++) {
            swap(nums[start], nums[i]);
            getPerm(res, nums, start+1);
            swap(nums[start], nums[i]);
        }    
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        getPerm(res, nums, 0);
        
        return res;
    }
};


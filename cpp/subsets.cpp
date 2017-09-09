78. Subsets  
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
Hide Company Tags Amazon Uber Facebook
Hide Tags Array Backtracking Bit Manipulation
Hide Similar Problems (M) Generalized Abbreviation

class Solution {
public:
    void getSet(vector<vector<int>>& res, vector<int>& output, vector<int>& nums, int start) {
        res.push_back(output);
        
        for (int i=start; i<nums.size(); i++) {
            output.push_back(nums[i]);
            getSet(res, output, nums, i+1);
            output.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> output;
        getSet(res, output, nums, 0);
        
        return res;
    }
};

2. use bit
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size(), total=1<<n;
        for (int i=0; i<total; i++) {
            vector<int> output;
            for (int j=0; j<n; j++) {
                if (((i>>j) & 0x1)==1) output.push_back(nums[j]);
            }
            res.push_back(output);
        }
        return res;
    }
};


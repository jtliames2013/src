47. Permutations II  
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
Hide Company Tags LinkedIn Microsoft
Hide Tags Backtracking
Hide Similar Problems (M) Next Permutation (M) Permutations (M) Palindrome Permutation II

NOTE: Can't use swap as in I because it will change the sorted order and sorted order is used to avoid duplicate.
E.g., [0,0,0,1,9], after swap [0,9,0,1,0] and index is at 2. swap index 2 and 4 will cause duplicate.

1.
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> output;
        vector<bool> selected(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, res, output, selected);
        return res;
    }
private:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& output, vector<bool>& selected) {
        if (output.size()==nums.size()) {
            res.push_back(output);
            return;
        }
        
        for (int i=0; i<nums.size(); ++i) {
            if (selected[i]==false && (i==0 || selected[i-1]==true || nums[i]!=nums[i-1])) {
                selected[i]=true;
                output.push_back(nums[i]);
                dfs(nums, res, output, selected);
                output.pop_back();
                selected[i]=false;
            }
        }
    }
};

2. pass array instead of reference
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;        
        sort(nums.begin(), nums.end());
        dfs(nums, res, 0);
        return res;
    }
private:
    void dfs(vector<int> nums, vector<vector<int>>& res, int start) {
        if (start==nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for (int i=start; i<nums.size(); ++i) {
            if (i==start || nums[i]!=nums[start]) {
                swap(nums[i], nums[start]);
                dfs(nums, res, start+1);
            }
        }
    }
};

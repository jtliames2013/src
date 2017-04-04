40. Combination Sum II  
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Hide Tags Array Backtracking
Hide Similar Problems (M) Combination Sum

class Solution {
public:
    void getSum(vector<vector<int>>& res, vector<int>& output, vector<int>& candidates, int target, int start) {
        if (target==0) {
            res.push_back(output);
            return;
        }    
        
        for (int i=start; i<candidates.size(); i++) {
            if (target-candidates[i]>=0 && (i==start || candidates[i]!=candidates[i-1])) {
                output.push_back(candidates[i]);
                getSum(res, output, candidates, target-candidates[i], i+1);
                output.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> output;
        sort(candidates.begin(), candidates.end());
        getSum(res, output, candidates, target, 0);
        
        return res;
    }
};

